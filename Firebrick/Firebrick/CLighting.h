#pragma once
#include "CPlayer.h"
#include "CSpell.h"


class CLighting : public CSpell
{
public:
	CLighting(string givenName, int givenDamage, CPlayer* enemy, vector<CDamageable*>* enemyField);
	virtual ~CLighting();
	SAttackReport* Attack();
};

