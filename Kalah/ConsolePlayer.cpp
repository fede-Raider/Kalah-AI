#include "ConsolePlayer.h"
#include <iostream>

void ConsolePlayer::start(bool b) {
}

int ConsolePlayer::move() {
	int r = -1;
	std::cout << "Inserisci Mossa: ";
	std::cin >> r;
	std::cout << std::endl;
	return r;
}

void ConsolePlayer::tellMove(int move) {
	board.moveBasin(move, 1);
}