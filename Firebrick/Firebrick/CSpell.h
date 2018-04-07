#pragma once
#include "CPlayer.h"
#include "CDamageable.h"

class CSpell : public CDamageable
{
protected:
	CPlayer* pEnemyPlayer;
	vector<CDamageable*>* pEnemyField;
public:
	CSpell();
	virtual ~CSpell();
};

