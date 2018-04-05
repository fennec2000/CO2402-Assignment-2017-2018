#pragma once
#include <string> // string
using namespace std;

enum ECardType { Minion = 1, Fireball, Lighting, Bless, Vampire, Wall, Trample, Leech, Sword, Amour };
enum EPlayer { sorceress, wizard };

class CCard
{
private:
protected:
	ECardType type;
	int cost;
	string name;
	EPlayer player;
public:
	CCard();
	virtual ~CCard();
	ECardType GetType() { return type; };
	string GetName() { return name; };
};

