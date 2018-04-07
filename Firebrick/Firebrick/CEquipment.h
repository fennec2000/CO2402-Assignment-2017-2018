#pragma once
#include "CPlayer.h"
#include "CDamageable.h"

class CEquipment : public CDamageable
{
protected:
	CPlayer* pPlayer;
	vector<CDamageable*>* pField;
public:
	CEquipment();
	virtual ~CEquipment();
};

