#include "CCore.h"

// Setup instance
CCore* CCore::pInstance = 0;

/// <summary>
/// Get the single instance of the core component
/// </summary>
/// <returns>pointer to the singleton</returns>
CCore* CCore::GetInstance()
{
	if (pInstance == 0)
	{
		pInstance = new CCore();
	}

	return pInstance;
}

/// <summary>
/// Core, sets up the game
/// </summary>
CCore::CCore()
{
	// setup srand
	string line;
	ifstream myfile("seed.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			srand(static_cast<unsigned int>(stoi(line)));
			//srand(0);
		}
		myfile.close();
	}
	else
		cout << "Unable to open seed file";

	// setup classes
	pField = new CField();
	pSorceress = new CPlayer(sorceress);
	pWizard = new CPlayer(wizard);

	// setup players
	LoadCards();
	ShuffleCardsQuestion();
	Draw(EPlayer::sorceress);
	Draw(EPlayer::wizard);
	round++;
	cout << endl;
}

/// <summary>
/// Function to load a deck from a txt file and add it to the given CPlayer
/// </summary>
/// <param name="playerName">Pointer to the player's class</param>
/// <param name="inputFile">name of the file which contains the deck of cards</param>
void CCore::LoadDeck(EPlayer givenPlayer, string inputFile)
{
	EPlayer enemy = ((givenPlayer) ? sorceress : wizard);
	CPlayer* pEnemyPlayer = ((givenPlayer) ? pSorceress : pWizard);

	string line;
	string section;
	ifstream myfile(inputFile);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			const int ARRAY_SIZE = 5; // current maximumn options is 5
			string arr[ARRAY_SIZE];
			int i = 0;

			istringstream currentLine(line);
			while (getline(currentLine, section, ' '))
			{
				if (i < ARRAY_SIZE) // check to not go out of bounds
				{
					arr[i] = section;
					i++;
				}
			}

			// create the card and add it to the deck
			ECardType newCardType = static_cast<ECardType>(stoi(arr[0]));
			CCard* card;

			if (newCardType == Minion)
			{
				CMinion* newCard = new CMinion(arr[1], stoi(arr[2]), stoi(arr[3]), givenPlayer, pEnemyPlayer, pField->GetField(enemy));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Fireball)
			{
				CFireBall* newCard = new CFireBall(arr[1], stoi(arr[2]), pEnemyPlayer, pField->GetField(enemy));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Lighting)
			{
				CLighting* newCard = new CLighting(arr[1], stoi(arr[2]), pEnemyPlayer, pField->GetField(enemy));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Bless)
			{
				CBless* newCard = new CBless(arr[1], stoi(arr[2]), stoi(arr[3]), pEnemyPlayer, ((givenPlayer) ? pWizard : pSorceress), pField->GetField(enemy), pField->GetField(givenPlayer));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Vampire)
			{
				CVampire* newCard = new CVampire(arr[1], stoi(arr[2]), stoi(arr[3]), stoi(arr[4]), givenPlayer, pEnemyPlayer, pField->GetField(enemy));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Wall) // I wanna build a wall...
			{
				CWall* newCard = new CWall(arr[1], stoi(arr[2]), stoi(arr[3]), givenPlayer, pEnemyPlayer, pField->GetField(enemy));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Horde)
			{
				CHorde* newCard = new CHorde(arr[1], stoi(arr[2]), stoi(arr[3]), givenPlayer, pEnemyPlayer, pField->GetField(enemy), pField->GetField(givenPlayer));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Trample)
			{
				CTrample* newCard = new CTrample(arr[1], stoi(arr[2]), stoi(arr[3]), givenPlayer, pEnemyPlayer, pField->GetField(enemy));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Leech)
			{
				CLeech* newCard = new CLeech(arr[1], stoi(arr[2]), stoi(arr[3]), givenPlayer, pEnemyPlayer, pField->GetField(enemy), ((givenPlayer) ? pWizard : pSorceress));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Sword)
			{
				CSword* newCard = new CSword(arr[1], stoi(arr[2]), ((givenPlayer) ? pWizard : pSorceress), pField->GetField(givenPlayer));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (newCardType == Amour)
			{
				CArmour* newCard = new CArmour(arr[1], stoi(arr[2]), ((givenPlayer) ? pWizard : pSorceress), pField->GetField(givenPlayer));
				card = static_cast<CCard*>(newCard);
				pField->AddCardToDeck(givenPlayer, card);
			}
		}
		myfile.close();
	}

	else
		cout << "Unable to open file" << endl;

	// flip the deck over so the top of the text file is the top of the deck
	pField->ReverseDeck(givenPlayer);
}

/// <summary>
/// draws a card from that players deck and adds it to there hand
/// </summary>
/// <param name="player">play to draw</param>
void CCore::Draw(EPlayer player)
{
	CCard* current;
	current = pField->DrawFromDeck(player);
	
	if (!round)
		cout << ((player) ? "Wizard" : "Sorceress") << " begins with " << current->GetName() << endl;
	else
		cout << ((player) ? "Wizard" : "Sorceress") << " draws " << current->GetName() << endl;

	switch (player)
	{
	case sorceress:
		pSorceress->AddCardToHand(current);
		break;
	case wizard:
		pWizard->AddCardToHand(current);
		break;
	default:
		break;
	}
}

/// <summary>
/// The turn for the given play, will draw, play a card, display the table, set all minions active and finally attack
/// </summary>
/// <param name="player">player to take a turn</param>
void CCore::Turn(EPlayer player)
{
	// draw
	Draw(player);

	// play card from hand
	CPlayer** currentPlayer;
	switch (player)
	{
	case sorceress:
		currentPlayer = &pSorceress;
		break;
	case wizard:
		currentPlayer = &pWizard;
		break;
	default:
		break;
	}
	CCard* card = (*currentPlayer)->PlayCard();
	ActivateCard(player, card);

	// display table
	pField->DisplayTable(player);

	// Set minions active
	pField->SetFieldActive(player);

	// attack
	vector<CDamageable*>* playerField = pField->GetField(player);

	for (int i = 0; i < playerField->size(); i++)
	{
		if (playerField->at(i)->GetActiveStatus())
		{
			SAttackReport* report = playerField->at(i)->Attack();
			playerField->at(i)->SetActiveStatus(false);
			while(!report->killList.empty())
			{
				SendCardToGraveyard(static_cast<CDamageable*>(report->killList.at(0)));
				report->killList.erase(report->killList.begin());
			}
		}
		if (!GameRunning()) // stop if games ends
			break;
	}
	// end
}

/// <summary>
/// uses the given card for a player
/// </summary>
/// <param name="player">player who used the card</param>
/// <param name="givenCard">card to be played</param>
void CCore::ActivateCard(EPlayer player, CCard* givenCard)
{
	cout << ((player) ? "Wizard" : "Sorceress") << " plays " << givenCard->GetName() << endl;
	ECardType chosenCardType = givenCard->GetType();

	if (chosenCardType == Minion || chosenCardType == Vampire || chosenCardType == Wall ||
		chosenCardType == Horde || chosenCardType == Trample || chosenCardType == Leech) // summon minion
	{
		pField->AddCardToField(player, static_cast<CMinion*>(givenCard));
	}
	else if (chosenCardType == Fireball || chosenCardType == Bless || chosenCardType == Lighting) // cast spell
	{
		SAttackReport* report = static_cast<CSpell*>(givenCard)->Attack();
		while (!report->killList.empty())
		{
			SendCardToGraveyard(static_cast<CDamageable*>(report->killList.at(0)));
			report->killList.erase(report->killList.begin());
		}
	}
	else if (chosenCardType == Sword || chosenCardType == Amour) // cast equipment
	{
		SAttackReport* report = static_cast<CEquipment*>(givenCard)->Attack();
	}
	else
	{
		cout << "ActivateCard: Unknown Card.";
	}
}

/// <summary>
/// Sends a card from the field to the graveyard
/// can send non field cards to the graveyard but will still check to see if that card is on the field
/// </summary>
/// <param name="target">card to send to the graveyard</param>
void CCore::SendCardToGraveyard(CDamageable* target)
{
	// remove from field
	pField->RemoveFromField(target->GetPlayer(), target);

	// add to grave
	pField->AddCardToGrave(target->GetPlayer(), (CCard*)target);
}

/// <summary>
/// clean up the players and field when game is over
/// </summary>
CCore::~CCore()
{
	// delete in reverse order
	delete pWizard;
	delete pSorceress;
	delete pField;
}

/// <summary>
/// Sets up both players decks
/// </summary>
void CCore::LoadCards()
{
	LoadDeck(EPlayer::sorceress, "sorceress.txt");
	LoadDeck(EPlayer::wizard, "wizard.txt");
}

/// <summary>
/// plays a full round of both players
/// </summary>
void CCore::PlayTurn()
{
	cout << "Round " << round << endl;
	Turn(EPlayer::sorceress);
	cout << endl;

	if (GameRunning())
	{
		Turn(EPlayer::wizard);
		cout << endl;
	}
		
	round++;
}

/// <summary>
/// check to see if game should keep running
/// </summary>
/// <returns>is the game over false = game over</returns>
bool CCore::GameRunning()
{
	if (round > 30)
		return false;
	if (pSorceress->GetHealth() <= 0)
		return false;
	if (pWizard->GetHealth() <= 0)
		return false;

	return true;
}

/// <summary>
/// ask if the player wants to shuffle the deck and then call if shuffle if so
/// </summary>
void CCore::ShuffleCardsQuestion()
{
	string input;
	bool ans = false;

	while (true)
	{
		cout << "Would you like to shuffle the decks? (yes or no)" << endl;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::tolower);

		if ("yes" == input || "y" == input)
		{
			ans = true;
			break;
		}
		else if ("no" == input || "n" == input)
		{
			ans = false;
			break;
		}
		cout << "Please only answer with 'yes' or 'no'" << endl;
	}

	if (ans)
	{
		pField->ShuffleDeck(sorceress);
		pField->ShuffleDeck(wizard);
		cout << "Decks shuffled" << endl;
	}
}
