#pragma once
#include "Player.h"

class ConsolePlayer : public Player {
public:
	virtual void start(bool b);
	virtual int move();
	virtual void tellMove(int move);
};