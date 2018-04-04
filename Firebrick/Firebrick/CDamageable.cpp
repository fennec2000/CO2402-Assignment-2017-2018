#include "CDamageable.h"



void CDamageable::TakeDamage(int damage)
{
	health -= damage;
}

CDamageable::CDamageable()
{
}


CDamageable::~CDamageable()
{
}
