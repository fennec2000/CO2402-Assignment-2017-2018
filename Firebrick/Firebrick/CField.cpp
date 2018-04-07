#include "CField.h"



CField::CField()
{
}

/// <summary>
/// removes cards from the decks, field and graveyards
/// </summary>
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

/// <summary>
/// adds given card to the players deck
/// </summary>
/// <param name="player">player the card belongs to</param>
/// <param name="givenCard">the card being moved</param>
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

/// <summary>
/// adds a card to the field
/// </summary>
/// <param name="player">player the card belongs to</param>
/// <param name="givenCard">the card being moved</param>
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

/// <summary>
/// adds a card to the graveyard
/// </summary>
/// <param name="player">player the card belongs to</param>
/// <param name="givenCard">the card being moved</param>
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

/// <summary>
/// Draw card from players deck
/// </summary>
/// <param name="player">player that wants to draw</param>
/// <returns>the drawn card</returns>
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

/// <summary>
/// displays all cards on the the players field
/// </summary>
/// <param name="player">player to show</param>
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

/// <summary>
/// gives a pointer to a players field
/// </summary>
/// <param name="player">chosen plaeyr</param>
/// <returns>a pointer to the players field</returns>
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

/// <summary>
/// reports if there are any active minions on the field
/// </summary>
/// <param name="player">players field to check</param>
/// <returns>returns true if any minion is active</returns>
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

/// <summary>
/// finds and removes a card form the players field
/// </summary>
/// <param name="player">player to seach</param>
/// <param name="card">card to remove from field</param>
void CField::RemoveFromField(EPlayer player, CDamageable* card)
{
	switch (player)
	{
	case sorceress:
		for (int i = 0; i < sorceressField.size(); i++)
		{
			if (sorceressField.at(i) == card)
			{
				sorceressField.erase(sorceressField.begin() + i);
				break;
			}
		}
		break;
	case wizard:
		for (int i = 0; i < wizardField.size(); i++)
		{
			if (wizardField.at(i) == card)
			{
				wizardField.erase(wizardField.begin() + i);
				break;
			}
		}
		break;
	default:
		break;
	}
}

/// <summary>
/// Sets all the minions on the player side to active
/// </summary>
/// <param name="player">player that wants to have its field all activated</param>
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

/// <summary>
/// passes thought the deck and swaps cards randomly from srand
/// </summary>
/// <param name="player">players deck to shuffle</param>
void CField::ShuffleDeck(EPlayer player)
{
	vector<CCard*>* playerDeck = ((player) ? &wizardDeck : &sorceressDeck);

	for (int i = 0; i < playerDeck->size(); i++)
	{
		swap(playerDeck->at(i), playerDeck->at(Random(playerDeck->size())));
	}
}

/// <summary>
/// flip the order of the deck
/// </summary>
/// <param name="player">player deck to flip</param>
void CField::ReverseDeck(EPlayer player)
{
	switch (player)
	{
	case sorceress:
		reverse(sorceressDeck.begin(), sorceressDeck.end());
		break;
	case wizard:
		reverse(wizardDeck.begin(), wizardDeck.end());
		break;
	default:
		break;
	}
}

