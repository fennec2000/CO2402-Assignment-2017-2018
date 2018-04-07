#include "CFireBall.h"



CFireBall::CFireBall(string givenName, int givenDamage, CPlayer* enemy, vector<CDamageable*>* enemyField)
{
	name = givenName;
	damage = givenDamage;
	health = -1;
	type = ECardType::Fireball;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
}


CFireBall::~CFireBall()
{
}

CDamageable* CFireBall::Attack()
{
	int enemySize = pEnemyField->size();
	int randPick = Random(enemySize);

	if (randPick == enemySize) // attack player
	{
		pEnemyPlayer->TakeDamage(this, damage);
		return pEnemyPlayer;
	}
	else // attack minion
	{
		pEnemyField->at(randPick)->TakeDamage(this, damage);
		return pEnemyField->at(randPick);
	}
}
