#include "CBless.h"



CBless::CBless(string givenName, int givenDamage, int givenHeal, CPlayer* enemy, CPlayer* player, vector<CDamageable*>* enemyField, vector<CDamageable*>* playerField)
{
	name = givenName;
	damage = givenDamage;
	heal = givenHeal;
	health = -1;
	type = ECardType::Bless;
	pEnemyPlayer = enemy;
	pPlayer = player;
	pEnemyField = enemyField;
	pField = playerField;
}


CBless::~CBless()
{
}

CDamageable* CBless::Attack()
{
	int enemySize = pEnemyField->size(); // enemy minions + enemy player
	int pickSize = enemySize + pField->size() + 1; // fiendly minions + player
	int randPick = Random(pickSize);

	/* Example
	* tttttEfffffP
	* 012345678901
	* t = enemy minion (target)	x5
	* E = enemy player			x1
	* f = friendly minion		x5
	* P = player				x1
	*/

	if (randPick == pickSize) // heal player
	{
		pPlayer->TakeDamage(this, -damage);
		return pPlayer;
	}
	else if (randPick > enemySize) // heal minion
	{
		int target = randPick - enemySize - 1; // -1 to get back to start at 0
		pField->at(target)->TakeDamage(this, -damage);
		return pField->at(target);
	}
	else if (randPick == enemySize) // attack player
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
