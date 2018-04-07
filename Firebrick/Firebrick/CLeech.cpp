#include "CLeech.h"


// constructor
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
	SAttackReport* report = CMinion::Attack(); // attack
	pPlayer->TakeDamage(this, -damage); // heal
	return report;
}

