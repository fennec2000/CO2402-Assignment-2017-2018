#pragma once
#include "CPlayer.h"
#include <vector>

class CPlayer;

class CMinion : public CDamageable
{
private:
	CPlayer* pEnemyPlayer;
	vector<CDamageable*>* pEnemyField;
protected:
public:
	CMinion(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField);
	~CMinion();
	CDamageable* CMinion::Attack();
};

