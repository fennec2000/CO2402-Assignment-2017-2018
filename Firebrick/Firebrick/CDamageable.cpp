#include "CDamageable.h"


CDamageable::CDamageable()
{
}


CDamageable::~CDamageable()
{
}

/// <summary>
/// Deals damage to the player and reports it, negative damage heals the player
/// </summary>
/// <param name="attacker">who delt the damage</param>
/// <param name="damage">damage to deal</param>
/// <returns></returns>
int CDamageable::TakeDamage(CDamageable* attacker, int damage)
{
	// apply amour
	if (damage > 0)
		damage -= defence;

	// deal damage
	health -= damage;

	// report
	if (health > 0)
		cout << attacker->GetName() << ((damage >= 0) ? " attacks " : " heals ") << name << ": " << name << " health now " << health << endl;
	else
		cout << attacker->GetName() << " attacks " << name << ": " << name << " killed " << endl;

	return health;
}

/// <summary>
/// increases the damage of the monster
/// </summary>
/// <param name="caster">who casted the spell or equiptment</param>
/// <param name="damageIncrease">value to change</param>
void CDamageable::IncreaseDamage(CDamageable* caster, int damageIncrease)
{
	damage += damageIncrease;
	cout << caster->GetName() << " increases " << name << " damage to " << damage << endl;
}

/// <summary>
/// increases the defence/amour of the monster
/// </summary>
/// <param name="caster">who casted the spell or equiptment</param>
/// <param name="damageIncrease">value to change</param>
void CDamageable::IncreaseAmour(CDamageable* caster, int amourIncrease)
{
	defence += amourIncrease;
	cout << caster->GetName() << " increases " << name << " amour to " << defence << endl;
}
