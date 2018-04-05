#pragma once
#include "CDamageable.h"
#include <queue>	// queue
#include <iostream>	// cout
using namespace std;

class CField
{
private:
	queue<CCard*> sorceressDeck;
	queue<CCard*> wizardDeck;
	vector<CDamageable*> sorceressField;
	vector<CDamageable*> wizardField;
	queue<CCard*> sorceressGrave;
	queue<CCard*> wizardGrave;

public:
	CField();
	~CField();
	void AddCardToDeck(EPlayer player, CCard* givenCard);
	void AddCardToField(EPlayer player, CDamageable* givenCard);
	void AddCardToGrave(EPlayer player, CCard* givenCard);
	CCard* DrawFromDeck(EPlayer player);
	void DisplayTable(EPlayer player);
	vector<CDamageable*>* GetField(EPlayer player);
	bool ActiveMinions(EPlayer player);
	void RemoveFromField(EPlayer player, CDamageable* card);
	void SetFieldActive(EPlayer player);
};

