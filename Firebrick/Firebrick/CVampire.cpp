#include "CVampire.h"



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

CDamageable* CVampire::Attack()
{
	CDamageable* target = CMinion::Attack();
	return target;
}