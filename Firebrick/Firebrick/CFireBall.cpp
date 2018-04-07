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

SAttackReport* CFireBall::Attack()
{
	int enemySize = pEnemyField->size();
	int randPick = Random(enemySize);

	if (randPick == enemySize) // attack player
	{
		pEnemyPlayer->TakeDamage(this, damage);
		return &currentAttackReport;
	}
	else // attack minion
	{
		pEnemyField->at(randPick)->TakeDamage(this, damage);

		if (pEnemyField->at(randPick)->GetHealth() <= 0)
			currentAttackReport.killList.push_back(pEnemyField->at(randPick));

		return &currentAttackReport;
	}
}
