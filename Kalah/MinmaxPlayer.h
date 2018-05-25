#pragma once
#include "Player.h"
#include <limits>

class MinmaxPlayer : public Player {
public:
	virtual void start(bool b);
	virtual int move();
	virtual void tellMove(int move);
private:
	int minmax(int currentDepth,const Board& board, int player, int alpha, int beta, int repeatCheck) const;
	int maxDepth = 6;
	int turn = 0;
	bool first = false;
	static const int MAX_VALUE = std::numeric_limits<int>::max();
	static const int MIN_VALUE = std::numeric_limits<int>::min();
};