#pragma once
#include <iostream>

class CMinion;
class CPlayer;

class CDamageable
{
private:
	int health;
public:
	CDamageable();
	virtual ~CDamageable();
	virtual void TakeDamage(CMinion* attacker, int damage) = 0;
	virtual void TakeDamage(CPlayer* attacker, int damage) = 0;
	void TakeDamage(int damage);
	void SetHealth(int hp) { health = hp; };
	int GetHealth() { return health; };
};

