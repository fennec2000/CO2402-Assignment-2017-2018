#pragma once
#include "CPlayer.h"
#include "FirebrickMath.h"

class CFireBall : public CDamageable
{
private:
	CPlayer* pEnemyPlayer;
	vector<CDamageable*>* pEnemyField;
public:
	CFireBall(CPlayer* enemy, vector<CDamageable*>* enemyField);
	virtual ~CFireBall();
	CDamageable* Attack();
};

