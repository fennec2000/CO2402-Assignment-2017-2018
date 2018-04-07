#pragma once
#include "CPlayer.h"
#include <vector>

class CPlayer;

class CMinion : public CDamageable
{
protected:
	CPlayer* pEnemyPlayer;
	vector<CDamageable*>* pEnemyField;

	CDamageable* PickTarget();
public:
	inline CMinion() {};
	CMinion(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField);
	~CMinion();
	SAttackReport* Attack();
};

