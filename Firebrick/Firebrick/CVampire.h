#pragma once
#include "CMinion.h"

class CVampire : public CMinion
{
private:
	int lifesteal; // life stolen per attack
public:
	CVampire(string givenName, int givenAttack, int givenHealth, int givenLifesteal, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField);
	virtual ~CVampire();
	SAttackReport* Attack();
};

