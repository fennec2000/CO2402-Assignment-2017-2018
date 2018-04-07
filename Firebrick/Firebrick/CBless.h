#pragma once
#include "CSpell.h"


class CBless : public CSpell
{
private:
	int heal;	// amour the card can heal a minion or player
	CPlayer* pPlayer;
	vector<CDamageable*>* pField;
public:
	CBless(string givenName, int givenDamage, int givenHeal, CPlayer* enemy, CPlayer* player, vector<CDamageable*>* enemyField, vector<CDamageable*>* playerField);
	virtual ~CBless();
	SAttackReport* Attack();
};

