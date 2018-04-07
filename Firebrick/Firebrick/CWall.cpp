#include "CWall.h"



CWall::CWall(string givenName, int givenAttack, int givenHealth, EPlayer myPlayer, CPlayer* enemy, vector<CDamageable*>* enemyField)
{
	name = givenName;
	damage = givenAttack;
	health = givenHealth;
	player = myPlayer;
	type = ECardType::Wall;
	pEnemyPlayer = enemy;
	pEnemyField = enemyField;
}


CWall::~CWall()
{
}
