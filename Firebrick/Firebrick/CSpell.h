#pragma once
#include "CCard.h"
#include <string>

class CSpell : public CCard
{
protected:
	ECardType cardType;
	string name;
	int attack;

public:
	CSpell();
	virtual ~CSpell();
};

