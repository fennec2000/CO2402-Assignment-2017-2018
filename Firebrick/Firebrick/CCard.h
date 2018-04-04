#pragma once
#include <string> // string
using namespace std;

enum ECardType { Minion, Fireball, Lighting, Bless, Vampire, Wall, Trample, Leech, Sword, Amour };

class CCore;

class CCard
{
private:
protected:
	ECardType type;
	int cost;
	string name;
public:
	CCard();
	virtual ~CCard();
	ECardType GetType() { return type; };
	string GetName() { return name; };
	virtual void Activate() = 0;
};

