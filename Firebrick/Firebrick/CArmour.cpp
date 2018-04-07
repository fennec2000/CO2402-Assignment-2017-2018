#include "CArmour.h"


// constructor
CArmour::CArmour(string givenName, int givenDamage, CPlayer* player, vector<CDamageable*>* playerField)
{
	name = givenName;
	damage = givenDamage;
	health = -1;
	type = ECardType::Amour;
	pPlayer = player;
	pField = playerField;
}


CArmour::~CArmour()
{
}

/// <summary>
/// picks target and applies amour or heals if on player
/// </summary>
/// <returns>report</returns>
SAttackReport* CArmour::Attack()
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
		pField->at(randPick)->IncreaseAmour(this, damage);
		return &currentAttackReport;
	}
}