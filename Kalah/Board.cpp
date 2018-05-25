#include "Board.h"
#include <iostream>
#include <iomanip>

int Board::getMancala(int player) const {
	return board[size / 2 - 1 + size / 2 * player];
}

int Board::getTotalMancala(int player) const {
	int tot = 0;
	for (int i = 0 + size / 2 * player; i < size / 2 - 1 + size / 2 * player; i++) {
		tot += board[i];
	}
	return board[size / 2 - 1 + size / 2 * player] + tot;
}

bool Board::moveBasin(int index, int player) {
	int real_index = index + (size / 2) * player;
	int stones = board[real_index];
	board[real_index] = 0;
	for (int i = 1; i <= stones; i++) {
		int position = ((index + i) % (size - 1) + (size / 2) * player) % size;
		board[position]++;
	}
	int last  = ((index+stones) % (size - 1) + (size / 2) * player) % size;
	checkLastInternal(last, player);
	return checkLastMancala(last, player);
}

void Board::checkLastInternal(int last, int player) {
	if(last < size/2 - 1 + size/2*player && last >= (size / 2) * player && board[last] == 1){
		addLastInternal(last, player);
	}
}

void Board::addLastInternal(int position, int player) {
	board[size/2 - 1 + size/2*player] += board[size - 2 - position] + 1;
	board[size - 2 - position] = 0;
	board[position] = 0;
}

bool Board::checkEndGame() const {
	if (checkEndPlayer(0) || checkEndPlayer(1)) {
		return true;
	}
	return false;
}

bool Board::checkEndPlayer(int player) const {
	for (int i = 0 + size/2 * player; i < size / 2 - 1 + size / 2 * player; i++) {
		if (board[i] != 0) {
			return false;
		}
	}
	return true;
}

void Board::addEndMancala(int player) {
	for (int i = 0 + size / 2 * player; i < size / 2 - 1 + size / 2 * player; i++) {
		board[size / 2 - 1 + size / 2 * player] += board[i];
		board[i] = 0;
	}
}

int Board::getSize() {
	return size;
}

int Board::getStonesToWin() {
	return stonesToWin;
}

bool Board::checkLastMancala(int last, int player) {
	if (last == size / 2 - 1 + size / 2 * player) {
		return true;
	}
	return false;
}

int Board::getBasin(int index, int player) const {
	return (player == 0) ? board[index] : board[index+7];
}

void Board::print() const {
	std::cout << "     ";
	for (int i = size-2; i > size/2 - 1; i--) {
		std::cout << board[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "[" << std::setw(2) << std::setfill('0') << board[size-1] << "] ";
	for (int i = size-2; i > size/2-1; i--) {
		std::cout << "  ";
	}
	std::cout << "[" << std::setw(2) << std::setfill('0') << board[size/2-1] << "]" << std::endl;
	std::cout << "     ";
	for (int i = 0; i < size/2-1; i++) {
		std::cout << board[i] << " ";
	}
	std::cout << std::endl << std::endl;
}