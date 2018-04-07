#pragma once
#include "CEquipment.h"

class CArmour : public CEquipment
{
public:
	CArmour(string givenName, int givenDamage, CPlayer* player, vector<CDamageable*>* playerField);
	virtual ~CArmour();
	SAttackReport* Attack();
};

