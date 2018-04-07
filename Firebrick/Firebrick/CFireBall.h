#pragma once
#include "CSpell.h"
#include "FirebrickMath.h"

class CFireBall : public CSpell
{
private:
public:
	CFireBall(string givenName, int givenDamage, CPlayer* enemy, vector<CDamageable*>* enemyField);
	virtual ~CFireBall();
	SAttackReport* Attack();
};

