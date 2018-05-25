#include "RandomPlayer.h"
#include <stdlib.h>
#include <iostream>

void RandomPlayer::start(bool b) {
}

int RandomPlayer::move() {
	int r = rand() % 6;
	while (board.getBasin(r, 0) == 0) {
		r = rand() % 6;
	}
	board.moveBasin(r, 0);
	return r;
}

void RandomPlayer::tellMove(int move) {
	board.moveBasin(move, 1);
}