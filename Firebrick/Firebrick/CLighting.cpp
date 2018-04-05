#include "CLighting.h"



CLighting::CLighting(CPlayer* enemy, vector<CDamageable*>* enemyField)
{
	name = "Lighting";
	damage = 1;
	health = -1;
	type = ECardType::Lighting;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
}


CLighting::~CLighting()
{
}

CDamageable* CLighting::Attack()
{
	for (int i = 0; i < pEnemyField->size(); i++)
	{
		pEnemyField->at(i)->TakeDamage(this, damage);
	}
	pEnemyPlayer->TakeDamage(this, damage);
	return nullptr;
}
