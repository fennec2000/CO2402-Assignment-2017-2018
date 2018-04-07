#include "CTrample.h"


// constructor
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

/// <summary>
/// attacks
/// loops through till all damage is delt
/// </summary>
/// <returns>report</returns>
SAttackReport* CTrample::Attack()
{
	int damageLeft = damage;

	do // untill all damage is delt
	{
		CDamageable* target = PickTarget(); // get target
		int damageDelt = target->GetHealth(); // get its health

		target->TakeDamage(this, damage); // attack
		if (target->GetHealth() <= 0) // check to see if killed
			currentAttackReport.killList.push_back(target); // add to report

		damageLeft -= damageDelt; // solves remaining damage
	} while (damageLeft > 0 && pEnemyPlayer->GetHealth() > 0);	// while there is still damage and
																// check to see if it won the game

	return &currentAttackReport;
}
