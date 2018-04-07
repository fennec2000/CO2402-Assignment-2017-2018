#pragma once
#include "CPlayer.h"
#include "CSpell.h"


class CLighting : public CSpell
{
private:
public:
	CLighting(string givenName, int givenDamage, CPlayer* enemy, vector<CDamageable*>* enemyField);
	virtual ~CLighting();
	CDamageable* Attack();
};

