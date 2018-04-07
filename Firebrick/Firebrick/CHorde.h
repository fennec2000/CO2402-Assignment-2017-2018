#pragma once
#include "CMinion.h"
class CHorde : public CMinion
{

private:
	vector<CDamageable*>* pAllyField;
public:
	CHorde(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField, vector<CDamageable*>* allyField);
	virtual ~CHorde();
	CDamageable* Attack();
};

