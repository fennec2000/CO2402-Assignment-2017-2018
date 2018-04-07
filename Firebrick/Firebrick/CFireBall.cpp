#include "CFireBall.h"


// constructor
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

/// <summary>
/// picks target and deals damage
/// </summary>
/// <returns>report of killed</returns>
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

		if (pEnemyField->at(randPick)->GetHealth() <= 0) // is dead
			currentAttackReport.killList.push_back(pEnemyField->at(randPick));	// add to report

		return &currentAttackReport;
	}
}
