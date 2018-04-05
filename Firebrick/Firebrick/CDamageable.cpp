#include "CDamageable.h"


CDamageable::CDamageable()
{
}


CDamageable::~CDamageable()
{
}

int CDamageable::TakeDamage(CDamageable* attacker, int damage)
{
	health -= damage;
	// report
	if (health > 0)
		cout << attacker->GetName() << " attacks " << name << ": " << name << " health now " << health << endl;
	else
		cout << attacker->GetName() << " attacks " << name << ": " << name << " killed " << endl;

	return health;
}
