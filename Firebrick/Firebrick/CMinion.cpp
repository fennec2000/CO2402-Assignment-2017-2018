#include "CMinion.h"


CMinion::CMinion(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CMinion*>* enemyField)
{
	name = givenName;
	attack = givenAttack;
	SetHealth(givenHealth);
	player = myPlayer;
	type = ECardType::Minion;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
}

CMinion::~CMinion()
{
}

void CMinion::Attack()
{
	pEnemyPlayer->TakeDamage(this, attack);
}

void CMinion::TakeDamage(CMinion * attacker, int damage)
{
	cout << "**TODO**: void CMinion::TakeDamage(CMinion * attacker, int damage)" << endl;
}

void CMinion::TakeDamage(CPlayer * attacker, int damage)
{
	cout << "**TODO**: void CMinion::TakeDamage(CPlayer * attacker, int damage)" << endl;
}
