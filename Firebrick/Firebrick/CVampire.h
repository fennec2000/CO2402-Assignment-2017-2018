#pragma once
#include "CMinion.h"

class CVampire : protected CMinion
{
private:
	int lifesteal;
public:
	CVampire(string givenName, int givenAttack, int givenHealth, int givenLifesteal, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField);
	virtual ~CVampire();
	CDamageable* Attack();
};

