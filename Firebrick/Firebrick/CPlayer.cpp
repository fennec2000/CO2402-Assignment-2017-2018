#include "CPlayer.h"



CPlayer::CPlayer(EPlayer givenPlayer)
{
	SetHealth(30);
	player = givenPlayer;
}


CPlayer::~CPlayer()
{
}

CCard* CPlayer::PlayCard()
{
	return PlayCard(Random(hand.size() - 1));
}

void CPlayer::TakeDamage(CMinion* attacker, int damage)
{
	CDamageable::TakeDamage(damage);
	string defendant = ((player) ? "Wizard" : "Sorceress");
	/*if (GetHealth() > 0)
		cout << attacker->GetName() << " attacks " << defendant << ": " << defendant << " health now " << GetHealth() << endl;
	else
		cout << attacker->GetName() << " attacks " << defendant << ": " << defendant << " killed " << endl;*/
}

void CPlayer::TakeDamage(CPlayer* attacker, int damage)
{
	cout << "**TODO**: void CPlayer::TakeDamage(CPlayer* attacker, int damage)" << endl;
}

CCard* CPlayer::PlayCard(int cardIndex)
{
	CCard* current;
	current = hand.at(cardIndex);
	hand.erase(hand.begin() + cardIndex);
	return current;
}