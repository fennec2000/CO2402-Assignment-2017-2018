#include "CHorde.h"



CHorde::CHorde(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField, vector<CDamageable*>* allyField)
{
	name = givenName;
	damage = givenAttack;
	health = givenHealth;
	player = myPlayer;
	type = ECardType::Horde;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
	pAllyField = allyField;
}


CHorde::~CHorde()
{
}

CDamageable* CHorde::Attack()
{
	// horde count
	int hordeCount = 0;
	for (int i = 0; i < pEnemyField->size(); i++)
	{
		if (pEnemyField->at(i)->GetType() == Horde)
			hordeCount++;
	}
	for (int i = 0; i < pAllyField->size(); i++)
	{
		if (pAllyField->at(i)->GetType() == Horde)
			hordeCount++;
	}

	// damage
	CDamageable* target = PickTarget();
	target->TakeDamage(this, damage * hordeCount);
	return target;
}
