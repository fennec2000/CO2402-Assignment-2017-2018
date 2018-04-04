#pragma once
#include "CCard.h"
#include "CPlayer.h"
#include <queue>	// queue
#include <iostream>	// cout
using namespace std;

class CField
{
private:
	queue<CCard*> sorceressDeck;
	queue<CCard*> wizardDeck;
	vector<CCard*> sorceressField;
	vector<CCard*> wizardField;
	queue<CCard*> sorceressGrave;
	queue<CCard*> wizardGrave;

public:
	CField();
	~CField();
	void AddCardToDeck(EPlayer player, CCard* givenCard);
	void AddCardToField(EPlayer player, CCard* givenCard);
	void AddCardToGrave(EPlayer player, CCard* givenCard);
	CCard* DrawFromDeck(EPlayer player);
	void DisplayTable(EPlayer player);
	vector<CMinion*>* GetField(EPlayer player);
	int GetFieldSize(EPlayer player);
};

