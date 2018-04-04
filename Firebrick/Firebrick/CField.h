#pragma once
#include "CCard.h"
#include "CMinion.h"
#include <queue>	// queue
#include <iostream>	// cout
using namespace std;

class CField
{
private:
	queue<CCard*> sorceressDeck;
	queue<CCard*> wizardDeck;
	vector<CMinion*> sorceressField;
	vector<CMinion*> wizardField;
	queue<CCard*> sorceressGrave;
	queue<CCard*> wizardGrave;

public:
	CField();
	~CField();
	void AddCardToDeck(EPlayer player, CCard* givenCard);
	void AddCardToField(EPlayer player, CMinion* givenCard);
	void AddCardToGrave(EPlayer player, CCard* givenCard);
	CCard* DrawFromDeck(EPlayer player);
	void DisplayTable(EPlayer player);
	vector<CMinion*>* GetField(EPlayer player);
};

