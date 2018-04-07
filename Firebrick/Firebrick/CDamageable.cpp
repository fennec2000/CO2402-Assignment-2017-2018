#include "CDamageable.h"


CDamageable::CDamageable()
{
}


CDamageable::~CDamageable()
{
}

int CDamageable::TakeDamage(CDamageable* attacker, int damage)
{
	if (damage > 0)
		damage -= defence;


	health -= damage;
	// report
	if (health > 0)
		cout << attacker->GetName() << ((damage >= 0) ? " attacks " : " heals ") << name << ": " << name << " health now " << health << endl;
	else
		cout << attacker->GetName() << " attacks " << name << ": " << name << " killed " << endl;

	return health;
}

void CDamageable::IncreaseDamage(CDamageable* caster, int damageIncrease)
{
	damage += damageIncrease;
	cout << caster->GetName() << " increases " << name << " damage to " << damage << endl;
}

void CDamageable::IncreaseAmour(CDamageable* caster, int amourIncrease)
{
	defence += amourIncrease;
	cout << caster->GetName() << " increases " << name << " amour to " << defence << endl;
}
