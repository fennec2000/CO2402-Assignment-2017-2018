#pragma once
#include "CCard.h"
#include "FirebrickMath.h"
#include <iostream>

class CDamageable : public CCard
{
protected:
	int health;
	int damage;
	bool active = false;
	bool graveable = true;
public:
	CDamageable();
	virtual ~CDamageable();
	int TakeDamage(CDamageable* attacker, int damage);
	void SetHealth(int hp) { health = hp; };
	inline int GetHealth() { return health; };
	inline string GetName() { return name; };
	virtual CDamageable* Attack() = 0;
	inline void SetActiveStatus(bool givenStatus) { active = givenStatus; };
	inline bool GetActiveStatus() { return active; };
	bool GetGraveable() { return graveable; };
};

