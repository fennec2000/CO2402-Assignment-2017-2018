#pragma once
#include "CEquipment.h"

class CSword : public CEquipment
{
public:
	CSword(string givenName, int givenDamage, CPlayer* player, vector<CDamageable*>* playerField);
	virtual ~CSword();
	SAttackReport* Attack();
};

