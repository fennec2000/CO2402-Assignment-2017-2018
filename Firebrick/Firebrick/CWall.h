#pragma once
#include "CMinion.h"
class CWall : public CMinion
{
public:
	CWall(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField);
	virtual ~CWall();
};

