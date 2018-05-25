#include <stdlib.h>
#include <iostream>
#include <array>
#include <time.h> 
#include <memory>
#include "Player.h"
#include "MinmaxPlayer.h"
#include "RandomPlayer.h"
#include "Board.h"

using namespace std;

unique_ptr<Board> board;
array<unique_ptr<Player>, 2> players;

int turn = 0;

void setUpGame() {
	board = make_unique<Board>();
	players = { make_unique<MinmaxPlayer>(), make_unique<RandomPlayer>() };
	players[0]->start(true);
	players[1]->start(false);
}

bool runTurn(int player) {
	//cout << "START: " << player << endl;
	int move = players[player]->move();
	//cout << "MOVE: " << move << " STONES: " << board->getBasin(move, player) << endl;
	if (board->getBasin(move, player) == 0) {
		throw player;
	}
	bool repeat = board->moveBasin(move, player);
	players[(player + 1) % 2]->tellMove(move);
	//board->print();
	return repeat;
}

void gameLoop() {
	while (!board->checkEndGame()) {
		try {
			bool repeat = runTurn(turn % 2);
			if (repeat) {
				turn--;
			}
		} catch (int e) {
			cout << "Player " << e << " select empty basin!" << endl;
			break;
		}
		turn++;
	}
	board->addEndMancala(0);
	board->addEndMancala(1);
}

//-1 pair, 0 first, 1 second
int checkWin() {
	if (board->getMancala(0) > Board::getStonesToWin()) { return 0; }
	if (board->getMancala(1) > Board::getStonesToWin()) { return 1; }
	return -1;
}


int main() {
	srand(time(NULL));

	int a_points = 0;
	int b_points = 0;
	int pairs = 0;

	for (int i = 0; i < 100; i++) {
		setUpGame();
		gameLoop();
		int winner = checkWin();
		if (winner == 0) { a_points++; }
		else if (winner == 1) { b_points++; }
		else if (winner == -1) { pairs++; }
		board->print();
	}
	cout << "Player 0 wins: " << a_points << endl;
	cout << "Player 1 wins: " << b_points << endl;
	cout << "Pairs: " << pairs << endl;
	system("PAUSE");
}
