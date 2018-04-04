#include "CMinion.h"


CMinion::CMinion(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer)
{
	name = givenName;
	attack = givenAttack;
	SetHealth(givenHealth);
	type = ECardType::Minion;
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

void CMinion::Activate()
{
	//c->GetFieldObj()->AddCardToField(player, this);
}
