#pragma once
#include "CCard.h"
#include "FirebrickMath.h"
#include <iostream>

/// <summary>
/// report back from an attack
/// used to report a list of killed enemies
/// left for expansion
/// was used for reporting mulitple events
/// reduced to reporting only a list
/// TODO: change just to a vector
/// </summary>
struct SAttackReport
{
	vector<CCard*> killList;
};

class CDamageable : public CCard
{
protected:
	int health;				// health of the card
	int damage;				// damage of the card
	int defence = 0;		// defence of the card or 'amour' default: 0
	bool active = false;	// active, has the card hads taken its turn this turn
	bool graveable = true;	// can this card go to the graveyard
	SAttackReport currentAttackReport;	// report what was done, this report a vector of cards that have been killed and trample damage if aplicable
public:
	CDamageable();
	virtual ~CDamageable();
	int TakeDamage(CDamageable* attacker, int damage);
	void SetHealth(int hp) { health = hp; };
	inline int GetHealth() { return health; };
	inline string GetName() { return name; };
	virtual SAttackReport* Attack() = 0;
	inline void SetActiveStatus(bool givenStatus) { active = givenStatus; };
	inline bool GetActiveStatus() { return active; };
	bool GetGraveable() { return graveable; };
	void IncreaseDamage(CDamageable* caster, int damageIncrease);
	void IncreaseAmour(CDamageable* caster, int amourIncrease);
};
