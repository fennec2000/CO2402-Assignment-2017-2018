#pragma once
#include "CCard.h"
#include "FirebrickMath.h"
#include <iostream>

struct SAttackReport
{
	vector<CCard*> killList;
	int trampleDamage;
};

class CDamageable : public CCard
{
protected:
	int health;
	int damage;
	int defence = 0;
	bool active = false;
	bool graveable = true;
	SAttackReport currentAttackReport;
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
