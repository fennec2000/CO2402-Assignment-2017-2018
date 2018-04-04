#pragma once
#include "CSpell.h"
#include "CPlayer.h"
#include "CMinion.h"
class CFireball : public CSpell
{
private:

public:
	CFireball();
	virtual ~CFireball();
	void Cast(CPlayer* targetPlayer);
	void Cast(CMinion* targetMinion);
};

