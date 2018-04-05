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
		current = (CCard*)sorceressField.back();
		sorceressField.pop_back();
		delete current;
	}
	while (!wizardField.empty())
	{
		current = (CCard*)wizardField.back();
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

void CField::AddCardToField(EPlayer player, CDamageable* givenCard)
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

vector<CDamageable*>* CField::GetField(EPlayer player)
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

bool CField::ActiveMinions(EPlayer player)
{
	switch (player)
	{
	case sorceress:
		for (std::vector<CDamageable*>::iterator it = sorceressField.begin(); it != sorceressField.end(); ++it)
		{
			if ((*it)->GetActiveStatus())
				return true;
		}
		break;
	case wizard:
		for (std::vector<CDamageable*>::iterator it = wizardField.begin(); it != wizardField.end(); ++it)
		{
			if ((*it)->GetActiveStatus())
				return true;
		}
		break;
	default:
		break;
	}
	return false;
}

void CField::RemoveFromField(EPlayer player, CDamageable* card)
{
	switch (player)
	{
	case sorceress:
		sorceressField.erase(remove(sorceressField.begin(), sorceressField.end(), card), sorceressField.end());
		break;
	case wizard:
		wizardField.erase(remove(wizardField.begin(), wizardField.end(), card), wizardField.end());
		break;
	default:
		break;
	}
}

void CField::SetFieldActive(EPlayer player)
{
	switch (player)
	{
	case sorceress:
		for (std::vector<CDamageable*>::iterator it = sorceressField.begin(); it != sorceressField.end(); ++it)
		{
			(*it)->SetActiveStatus(true);
		}
		break;
	case wizard:
		for (std::vector<CDamageable*>::iterator it = wizardField.begin(); it != wizardField.end(); ++it)
		{
			(*it)->SetActiveStatus(true);
		}
		break;
	default:
		break;
	}
}

