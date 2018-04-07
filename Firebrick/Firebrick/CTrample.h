#pragma once
#include "CMinion.h"
class CTrample : public CMinion
{
public:
	CTrample(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField);
	virtual ~CTrample();
	SAttackReport* Attack();
};

