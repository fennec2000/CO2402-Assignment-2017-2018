#pragma once
#include "CCard.h"
#include "CMinion.h"
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
	void TakeDamage(CMinion* attacker, int damage);
	void TakeDamage(CPlayer* attacker, int damage);
	int GetHandSize() { return hand.size(); };
};

