#pragma once
#include "CDamageable.h"
#include "FirebrickMath.h"
#include <queue>	// queue
#include <iostream>	// cout
using namespace std;

class CField
{
private:
	vector<CCard*> sorceressDeck;
	vector<CCard*> wizardDeck;
	vector<CDamageable*> sorceressField;
	vector<CDamageable*> wizardField;
	vector<CCard*> sorceressGrave;
	vector<CCard*> wizardGrave;

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
	void ShuffleDeck(EPlayer player);
	void ReverseDeck(EPlayer player);
};

