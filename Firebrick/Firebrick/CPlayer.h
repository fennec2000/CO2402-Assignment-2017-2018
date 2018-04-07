#pragma once
#include "CDamageable.h"
#include "FirebrickMath.h"
#include <vector>	// vector
using namespace std;

class CPlayer : public CDamageable
{
private:
	vector<CCard*> hand;
	EPlayer player;

	CCard* PlayCard(int cardIndex);
public:
	CPlayer(EPlayer givenPlayer);
	~CPlayer();
	inline void AddCardToHand(CCard* givenCard) { hand.push_back(givenCard); };
	CCard* PlayCard();
	int GetHandSize() { return hand.size(); };
	SAttackReport* Attack() { return nullptr; };
};

