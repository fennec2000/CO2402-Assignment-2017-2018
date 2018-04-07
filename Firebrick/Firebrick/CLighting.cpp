#include "CLighting.h"


// constructor
CLighting::CLighting(string givenName, int givenDamage, CPlayer* enemy, vector<CDamageable*>* enemyField)
{
	name = givenName;
	damage = givenDamage;
	health = -1;
	type = ECardType::Lighting;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
}


CLighting::~CLighting()
{
}

/// <summary>
/// attacks all minions and playerss
/// </summary>
/// <returns>report</returns>
SAttackReport* CLighting::Attack()
{
	for (int i = 0; i < pEnemyField->size(); i++)
	{
		pEnemyField->at(i)->TakeDamage(this, damage); // attack each minion
		if (pEnemyField->at(i)->GetHealth() <= 0)
			currentAttackReport.killList.push_back(pEnemyField->at(i)); // add deaths to report
	}
	pEnemyPlayer->TakeDamage(this, damage); // attack player
	return &currentAttackReport;
}
