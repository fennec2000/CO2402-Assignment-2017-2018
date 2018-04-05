#include "CMinion.h"


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

CDamageable* CMinion::Attack()
{
	int enemySize = pEnemyField->size();
	if (enemySize > 0) // attack minion
	{
		int randPick = Random(enemySize - 1);
		pEnemyField->at(randPick)->TakeDamage(this, damage);
		return pEnemyField->at(randPick);
	}
	else // attack player
	{
		pEnemyPlayer->TakeDamage(this, damage);
		return pEnemyPlayer;
	}
}