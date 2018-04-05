#include "CCore.h"

// Setup instance
CCore* CCore::pInstance = 0;

CCore* CCore::GetInstance()
{
	if (pInstance == 0)
	{
		pInstance = new CCore();
	}

	return pInstance;
}

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
			if (stoi(arr[0]) == Minion)
			{
				CCard* card;
				CMinion* newCard = new CMinion(arr[1], stoi(arr[2]), stoi(arr[3]), givenPlayer, pEnemyPlayer, pField->GetField(enemy));
				card = (CCard*)newCard;
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (stoi(arr[0]) == Fireball)
			{
				CCard* card;
				CFireBall* newCard = new CFireBall(pEnemyPlayer, pField->GetField(enemy));
				card = (CCard*)newCard;
				pField->AddCardToDeck(givenPlayer, card);
			}
			else if (stoi(arr[0]) == Lighting)
			{
				CCard* card;
				CLighting* newCard = new CLighting(pEnemyPlayer, pField->GetField(enemy));
				card = (CCard*)newCard;
				pField->AddCardToDeck(givenPlayer, card);
			}
		}
		myfile.close();
	}

	else
		cout << "Unable to open file" << endl;
}

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

void CCore::Turn(EPlayer player)
{
	// draw
	Draw(player);

	// play card in hand
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
 	EPlayer enemy = ((player) ? sorceress : wizard);

	vector<CDamageable*>* playerField = pField->GetField(player);
	while (pField->ActiveMinions(player) && GameRunning())
	{
		for (int i = 0; i < playerField->size(); i++)
		{
			if (playerField->at(i)->GetActiveStatus())
			{
				CDamageable* target = playerField->at(i)->Attack();
				playerField->at(i)->SetActiveStatus(false);
				if (target->GetHealth() <= 0 && target->GetGraveable())
				{
					SendCardToGraveyard(enemy, target);
					break;
				}
			}
			if (!GameRunning()) // stop if games ends
				break;
		}
	}
	// end
}

void CCore::ActivateCard(EPlayer player, CCard* givenCard)
{
	cout << ((player) ? "Wizard" : "Sorceress") << " plays " << givenCard->GetName() << endl;
	ECardType chosenCardType = givenCard->GetType();
	if (chosenCardType == Minion)
	{
		pField->AddCardToField(player, (CMinion*)givenCard);
	}
	else if (chosenCardType == Fireball)
	{
		CDamageable* target = static_cast<CFireBall*>(givenCard)->Attack();
		if (target->GetHealth() <= 0)
			SendCardToGraveyard(((player) ? sorceress : wizard), target);
	}
	else if (chosenCardType == Lighting)
	{
		static_cast<CLighting*>(givenCard)->Attack();
		vector<CDamageable*>* enemies = pField->GetField(((player) ? sorceress : wizard));
		// pass to see if any are dead
		bool cleanPass = false;
		while (!cleanPass)
		{
			cleanPass = true;
			for (int i = 0; i < enemies->size(); i++)
			{
				if (enemies->at(i)->GetHealth() <= 0)
				{
					SendCardToGraveyard(((player) ? sorceress : wizard), enemies->at(i));

					// reset and recheck
					cleanPass = false;
					break; 
				}
			}
		}
	}
	else
	{
		cout << "ActivateCard: Unknown Card.";
	}
}

void CCore::SendCardToGraveyard(EPlayer enemy, CDamageable* target)
{
	// remove from field
	pField->RemoveFromField(enemy, target);

	// add to grave
	pField->AddCardToGrave(enemy, (CCard*)target);
}

CCore::~CCore()
{
	// delete in reverse order
	delete pWizard;
	delete pSorceress;
	delete pField;
}

void CCore::LoadCards()
{
	LoadDeck(EPlayer::sorceress, "sorceress.txt");
	LoadDeck(EPlayer::wizard, "wizard.txt");
}

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
