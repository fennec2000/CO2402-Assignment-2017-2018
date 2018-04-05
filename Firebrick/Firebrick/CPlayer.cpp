#include "CPlayer.h"


CPlayer::CPlayer(EPlayer givenPlayer)
{
	SetHealth(30);
	player = givenPlayer;
	graveable = false;

	switch (givenPlayer)
	{
	case sorceress:
		name = "Sorceress";
		break;
	case wizard:
		name = "Wizard";
		break;
	default:
		break;
	}
}

CPlayer::~CPlayer()
{
}

CCard* CPlayer::PlayCard()
{
	return PlayCard(Random(hand.size() - 1));
}

CCard* CPlayer::PlayCard(int cardIndex)
{
	CCard* current;
	current = hand.at(cardIndex);
	hand.erase(hand.begin() + cardIndex);
	return current;
}