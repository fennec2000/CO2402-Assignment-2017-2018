#include "CSword.h"



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