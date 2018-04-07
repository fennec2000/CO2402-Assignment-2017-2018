#include "CLeech.h"



CLeech::CLeech(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField, CPlayer* allyPlayer)
{
	name = givenName;
	damage = givenAttack;
	health = givenHealth;
	player = myPlayer;
	type = ECardType::Leech;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
	pPlayer = allyPlayer;
}

CLeech::~CLeech()
{
}

SAttackReport* CLeech::Attack()
{
	SAttackReport* report = CMinion::Attack();
	pPlayer->TakeDamage(this, -damage);
	/*int playerNewHealth = pPlayer->GetHealth() + 2;
	pPlayer->SetHealth(playerNewHealth);
	cout << name << " heals " << pPlayer->GetName() << ": " << pPlayer->GetName() << " health now " << playerNewHealth << endl;*/
	return report;
}

