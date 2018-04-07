#pragma once
#include "CPlayer.h"
#include "CDamageable.h"


class CLighting : public CDamageable
{
private:
	CPlayer* pEnemyPlayer;
	vector<CDamageable*>* pEnemyField;
public:
	CLighting(string givenName, int givenDamage, CPlayer* enemy, vector<CDamageable*>* enemyField);
	virtual ~CLighting();
	CDamageable* Attack();
};

