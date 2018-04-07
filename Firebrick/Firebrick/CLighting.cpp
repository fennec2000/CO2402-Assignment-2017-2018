#include "CLighting.h"



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

SAttackReport* CLighting::Attack()
{
	for (int i = 0; i < pEnemyField->size(); i++)
	{
		pEnemyField->at(i)->TakeDamage(this, damage);
		if (pEnemyField->at(i)->GetHealth() <= 0)
			currentAttackReport.killList.push_back(pEnemyField->at(i));
	}
	pEnemyPlayer->TakeDamage(this, damage);
	return &currentAttackReport;
}
