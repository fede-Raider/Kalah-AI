#pragma once
#include "Player.h"

class RandomPlayer : public Player {
public:
	virtual void start(bool b);
	virtual int move();
	virtual void tellMove(int move);
};