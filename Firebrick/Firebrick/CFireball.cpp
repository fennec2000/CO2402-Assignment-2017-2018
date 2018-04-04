#include "CFireball.h"



CFireball::CFireball()
{
	cardType = ECardType::Fireball;
	name = "Fireball";
	attack = 3;
}

CFireball::~CFireball()
{
}

void CFireball::Cast(CPlayer* targetPlayer)
{

}

void CFireball::Cast(CMinion* targetMinion)
{

}
