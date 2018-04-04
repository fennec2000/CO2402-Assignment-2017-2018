#include "CField.h"



CField::CField()
{
}


CField::~CField()
{
	CCard* current;
	// delete decks
	while (!sorceressDeck.empty())
	{
		current = sorceressDeck.front();
		sorceressDeck.pop();
		delete current;
	}
	while (!wizardDeck.empty())
	{
		current = wizardDeck.front();
		wizardDeck.pop();
		delete current;
	}

	// delete field
	while (!sorceressField.empty())
	{
		current = sorceressField.back();
		sorceressField.pop_back();
		delete current;
	}
	while (!wizardField.empty())
	{
		current = wizardField.back();
		wizardField.pop_back();
		delete current;
	}

	// delette grave
	while (!sorceressGrave.empty())
	{
		current = sorceressGrave.front();
		sorceressGrave.pop();
		delete current;
	}
	while (!wizardGrave.empty())
	{
		current = wizardGrave.front();
		wizardGrave.pop();
		delete current;
	}
}

void CField::AddCardToDeck(EPlayer player, CCard* givenCard)
{
	switch (player)
	{
	case sorceress:
		sorceressDeck.push(givenCard);
		break;
	case wizard:
		wizardDeck.push(givenCard);
		break;
	default:
		break;
	}
}

void CField::AddCardToField(EPlayer player, CMinion* givenCard)
{
	switch (player)
	{
	case sorceress:
		sorceressField.push_back(givenCard);
		break;
	case wizard:
		wizardField.push_back(givenCard);
		break;
	default:
		break;
	}
}

void CField::AddCardToGrave(EPlayer player, CCard* givenCard)
{
	switch (player)
	{
	case sorceress:
		sorceressGrave.push(givenCard);
		break;
	case wizard:
		wizardGrave.push(givenCard);
		break;
	default:
		break;
	}
}

CCard* CField::DrawFromDeck(EPlayer player)
{
	CCard* chosenCard;
	switch (player)
	{
	case sorceress:
		chosenCard = sorceressDeck.front();
		sorceressDeck.pop();
		break;
	case wizard:
		chosenCard = wizardDeck.front();
		wizardDeck.pop();
		break;
	default:
		break;
	}
	return chosenCard;
}

void CField::DisplayTable(EPlayer player)
{
	cout << "Cards on table: ";
	switch (player)
	{
	case sorceress:
		for (int i = 0; i < sorceressField.size(); i++)
			cout << sorceressField.at(i)->GetName() << "(" << sorceressField.at(i)->GetHealth() << ") ";
		break;
	case wizard:
		for (int i = 0; i < wizardField.size(); i++)
			cout << wizardField.at(i)->GetName() << "(" << wizardField.at(i)->GetHealth() << ") ";
		break;
	default:
		break;
	}
	cout << endl;
}

vector<CMinion*>* CField::GetField(EPlayer player)
{
	switch (player)
	{
	case sorceress:
		return &sorceressField;
		break;
	case wizard:
		return &wizardField;
		break;
	default:
		break;
	}
	return nullptr;
}

