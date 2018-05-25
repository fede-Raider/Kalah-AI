#pragma once
#include "Board.h"

class Player {
public:
	virtual ~Player() = default;
	virtual void start(bool b) = 0;
	virtual int move() = 0;
	virtual void tellMove(int move) = 0;
protected:
	Board board;
};