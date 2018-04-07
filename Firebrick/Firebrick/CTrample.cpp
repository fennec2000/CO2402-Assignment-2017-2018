#include "CTrample.h"



CTrample::CTrample(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField)
{
	name = givenName;
	damage = givenAttack;
	health = givenHealth;
	player = myPlayer;
	type = ECardType::Trample;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
}


CTrample::~CTrample()
{
}

SAttackReport* CTrample::Attack()
{
	int damageLeft = damage;

	do
	{
		CDamageable* target = PickTarget();
		int damageDelt = target->GetHealth();
		target->TakeDamage(this, damage);
		if (target->GetHealth() <= 0)
			currentAttackReport.killList.push_back(target);
		damageLeft -= damageDelt;
	} while (damageLeft > 0 && pEnemyPlayer->GetHealth() > 0);

	return &currentAttackReport;
}
