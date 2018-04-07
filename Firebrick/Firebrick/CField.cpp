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
		current = sorceressDeck.back();
		sorceressDeck.pop_back();
		delete current;
	}
	while (!wizardDeck.empty())
	{
		current = wizardDeck.back();
		wizardDeck.pop_back();
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
		current = sorceressGrave.back();
		sorceressGrave.pop_back();
		delete current;
	}
	while (!wizardGrave.empty())
	{
		current = wizardGrave.back();
		wizardGrave.pop_back();
		delete current;
	}
}

void CField::AddCardToDeck(EPlayer player, CCard* givenCard)
{
	switch (player)
	{
	case sorceress:
		sorceressDeck.push_back(givenCard);
		break;
	case wizard:
		wizardDeck.push_back(givenCard);
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
		sorceressGrave.push_back(givenCard);
		break;
	case wizard:
		wizardGrave.push_back(givenCard);
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
		chosenCard = sorceressDeck.back();
		sorceressDeck.pop_back();
		break;
	case wizard:
		chosenCard = wizardDeck.back();
		wizardDeck.pop_back();
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

void CField::ShuffleDeck(EPlayer player)
{
	vector<CCard*>* playerDeck = ((player) ? &wizardDeck : &sorceressDeck);

	for (int i = 0; i < playerDeck->size(); i++)
	{
		swap(playerDeck->at(i), playerDeck->at(Random(playerDeck->size())));
	}
}

