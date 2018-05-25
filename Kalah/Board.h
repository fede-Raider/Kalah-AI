#pragma once
#include<array>

class Board {
public:
	Board() = default;
	Board &Board::operator=(const Board &) = default;
	int getMancala(int player) const;
	int getTotalMancala(int player) const;
	bool moveBasin(int index, int player);
	int getBasin(int index, int player) const;
	void print() const;
	bool checkEndGame() const;
	void addEndMancala(int player);
	static int getSize();
	static int getStonesToWin();
private:
	bool checkEndPlayer(int player) const;
	void checkLastInternal(int index,int player);
	void addLastInternal(int index, int player);
	bool checkLastMancala(int index, int player);
	static constexpr int size = 14;
	static const int stonesToWin = (size - 2) * 2;
	static const int stonesForBasin = 4;
	// 0 is under_left
	std::array<int, size> board = { stonesForBasin, stonesForBasin, stonesForBasin, stonesForBasin, stonesForBasin, stonesForBasin, 0,
									stonesForBasin, stonesForBasin, stonesForBasin, stonesForBasin, stonesForBasin, stonesForBasin, 0 };
};