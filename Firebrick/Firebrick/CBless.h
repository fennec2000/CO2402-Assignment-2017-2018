#pragma once
#include "CPlayer.h"
#include "CDamageable.h"


class CBless : public CDamageable
{
private:
	int heal;
	CPlayer* pEnemyPlayer;
	CPlayer* pPlayer;
	vector<CDamageable*>* pEnemyField;
	vector<CDamageable*>* pField;
public:
	CBless(string givenName, int givenDamage, int givenHeal, CPlayer* enemy, CPlayer* player, vector<CDamageable*>* enemyField, vector<CDamageable*>* playerField);
	virtual ~CBless();
	CDamageable* Attack();
};

