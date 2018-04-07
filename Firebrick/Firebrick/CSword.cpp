#include "CSword.h"


// constructor
CSword::CSword(string givenName, int givenDamage, CPlayer* player, vector<CDamageable*>* playerField)
{
	name = givenName;
	damage = givenDamage;
	health = -1;
	type = ECardType::Sword;
	pPlayer = player;
	pField = playerField;
}

CSword::~CSword()
{
}

/// <summary>
/// picks target and increases the power of the minion, if no minnion heal player
/// </summary>
/// <returns></returns>
SAttackReport* CSword::Attack()
{
	int fieldSize = pField->size();

	if (!fieldSize) // heal player
	{
		pPlayer->TakeDamage(this, -damage);
		return &currentAttackReport;
	}
	else // equipt minion
	{
		int randPick = Random(fieldSize - 1);
		pField->at(randPick)->IncreaseDamage(this, damage);
		return &currentAttackReport;
	}
}