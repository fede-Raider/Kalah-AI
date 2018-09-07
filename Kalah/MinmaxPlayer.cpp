#include "MinmaxPlayer.h"
#include <stdlib.h>
#include <iostream>

void MinmaxPlayer::start(bool b) {
	first = b;
	maxDepth = 6;
}

int MinmaxPlayer::move() {
	turn++;
	if (turn % 2 == 0) { maxDepth++; }

	if (first) {
		first = false;
		board.moveBasin(5, 0);
		return 5;
	}

	int max = MIN_VALUE;
	int best = -1;
	for (int i = 0; i < Board::getSize() / 2 - 1; i++) {
		if (board.getBasin(i, 0) != 0) {
			Board b = board;
			int repeat = b.moveBasin(i, 0);
			int val = minmax(1, b, (1 - repeat), max, MAX_VALUE, repeat);
			if (val > max) {
				best = i;
				max = val;
			}
		}
	}
	board.moveBasin(best, 0);
	return best;
}

void MinmaxPlayer::tellMove(int move) {
	board.moveBasin(move, 1);
}

int MinmaxPlayer::minmax(int currentDepth, const  Board& board, int player, int alpha, int beta, int repeatCheck) const {

	if (board.getMancala(0) > Board::getStonesToWin()) { return MAX_VALUE - currentDepth; } 
	else if (board.getMancala(1) > Board::getStonesToWin()) { return MIN_VALUE + currentDepth; }

	if (board.checkEndGame()) {
		if (board.getTotalMancala(0) > Board::getStonesToWin()) { return MAX_VALUE - currentDepth; } 
		else if (board.getTotalMancala(1) > Board::getStonesToWin()) { return MIN_VALUE + currentDepth; }
	}

	if (!repeatCheck && currentDepth >= maxDepth) {
		return board.getMancala(0) - board.getMancala(1);
	}

	int val = (player == 0) ? MIN_VALUE : MAX_VALUE;
	if (player == 0) {
		for (int i = 0; i < Board::getSize() / 2 - 1; i++) {
			if (board.getBasin(i, player) != 0) {
				Board b = board;
				int repeat = b.moveBasin(i, player);
				val = std::max(val, minmax(currentDepth + 1, b, (1 - repeat), alpha, beta, repeat));
				alpha = std::max(alpha, val);
				if (beta <= alpha) {
					i = Board::getSize() / 2 - 1;
				}
			}
		}
	} else {
		for (int i = 0; i < Board::getSize() / 2 - 1; i++) {
			if (board.getBasin(i, player) != 0) {
				Board b = board;
				int repeat = b.moveBasin(i, player);
				val = std::min(val, minmax(currentDepth + 1, b, repeat, alpha, beta, repeat));
				beta = std::min(beta, val);
				if (beta <= alpha) {
					i = Board::getSize() / 2 - 1;
				}
			}
		}
	}
	return val;
}