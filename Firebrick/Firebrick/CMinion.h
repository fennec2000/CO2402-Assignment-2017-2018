#pragma once
#include "CCore.h"
#include "CCard.h"
#include "CDamageable.h"
#include <vector>

class CMinion : public CCard, public CDamageable
{
private:
	int attack;
	CPlayer* pEnemyPlayer;
	vector<CMinion*>* pEnemyField;
protected:
public:
	CMinion(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer);
	~CMinion();
	void Attack();
	int GetAttack() { return attack; };
	void TakeDamage(CMinion* attacker, int damage);
	void TakeDamage(CPlayer* attacker, int damage);
	void Activate();
};

