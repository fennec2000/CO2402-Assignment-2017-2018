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
		walls.at(randPick)->TakeDamage(this, damage); // take down that wall like the coolaid man oh-yeah!
		return walls.at(randPick);
	}
	else if (enemySize > 0) // attack minion
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