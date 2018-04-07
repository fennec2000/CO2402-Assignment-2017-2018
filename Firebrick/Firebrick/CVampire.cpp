#include "CVampire.h"


// constructor
CVampire::CVampire(string givenName, int givenAttack, int givenHealth, int givenLifesteal, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField)
{
	name = givenName;
	damage = givenAttack;
	health = givenHealth;
	lifesteal = givenLifesteal;
	player = myPlayer;
	type = ECardType::Vampire;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
}


CVampire::~CVampire()
{
}

SAttackReport* CVampire::Attack()
{
	SAttackReport* report = CMinion::Attack(); // attack
	TakeDamage(this, -lifesteal); // heal self
	return report;
}