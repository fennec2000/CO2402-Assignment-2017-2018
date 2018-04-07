#pragma once
#include "CMinion.h"
class CLeech : public CMinion
{
private:
	CPlayer* pPlayer;
public:
	CLeech(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField, CPlayer* allyPlayer);
	virtual ~CLeech();
	SAttackReport* Attack();
};

