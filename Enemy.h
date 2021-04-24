#pragma once

#include "HP.h"

class Enemy{
private:
	HP& hp;
public :
	Enemy(HP& hp) : hp(hp) {}

	int Damaged(int damage) {
		hp.Damaged(damage);
		return hp.GetHP();
	}

	//getter
	int GetHP() const {
		return hp.GetHP();
	}
	//setter

};