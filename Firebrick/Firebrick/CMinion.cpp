#include "CMinion.h"

/// <summary>
/// picks a target from the enemy field
/// walls are chosen first
/// minions are chosen second
/// if nothing attack enemy player
/// </summary>
/// <returns>pointer to chosen target</returns>
CDamageable* CMinion::PickTarget()
{
	int enemySize = pEnemyField->size();
	vector<CDamageable*> walls;

	// find walls
	for (int i = 0; i < enemySize; i++)
	{
		if (pEnemyField->at(i)->GetType() == ECardType::Wall)
			walls.push_back(pEnemyField->at(i));
	}

	if (walls.size() > 0) // random between walls
	{
		int randPick = Random(walls.size() - 1);
		return walls.at(randPick);
	}
	else if (enemySize > 0) // attack minion
	{
		int randPick = Random(enemySize - 1);
		return pEnemyField->at(randPick);
	}
	else // attack player
	{
		return pEnemyPlayer;
	}
}

CMinion::CMinion(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField)
{
	name = givenName;
	damage = givenAttack;
	health = givenHealth;
	player = myPlayer;
	type = ECardType::Minion;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
}

CMinion::~CMinion()
{
}

SAttackReport* CMinion::Attack()
{
	CDamageable* target = PickTarget();
	target->TakeDamage(this, damage);
	if (target->GetHealth() <= 0)
		currentAttackReport.killList.push_back(target);
	return &currentAttackReport;
}
