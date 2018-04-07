#pragma once
#include <string> // string
using namespace std;

enum ECardType { Minion = 1, Fireball, Lighting, Bless, Vampire, Wall, Horde, Trample, Leech, Sword, Amour };
enum EPlayer { sorceress, wizard };

class CCard
{
protected:
	ECardType type;	// card type of the card
	string name;	// name of the card
	EPlayer player;	// player that the card belongs to enum
public:
	CCard();
	virtual ~CCard();
	ECardType GetType() { return type; };
	string GetName() { return name; };
	EPlayer GetPlayer() { return player; };
};

