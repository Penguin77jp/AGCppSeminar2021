#pragma once

#include "HP.h"

class Player {
private :
	HP& hp;
public:
	Player(HP& hp) : hp(hp) {}

	//getter
	int GetHP() const { return hp.GetHP(); }
	//setter
};