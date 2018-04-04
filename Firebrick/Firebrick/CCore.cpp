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
			CCard* card;
			switch (stoi(arr[0]))
			{
			case 1:
				card = new CMinion(arr[1], stoi(arr[2]), stoi(arr[3]), givenPlayer, ((givenPlayer) ? pWizard : pSorceress), pField->GetField(givenPlayer));
				pField->AddCardToDeck(givenPlayer, card);
				break;
			default:
				break;
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

	// attack
	vector<CMinion*>* playerField = pField->GetField(player);
	for (vector<CMinion*>::iterator it = playerField->begin(); it != playerField->end(); ++it)
	{
		if (!GameRunning())
			break;

		(*it)->Attack();
	}
		

	// end
}

void CCore::ActivateCard(EPlayer player, CCard* givenCard)
{
	cout << ((player) ? "Wizard" : "Sorceress") << " plays " << givenCard->GetName() << endl;
	switch (givenCard->GetType())
	{
	case Minion:
		pField->AddCardToField(player, (CMinion*)givenCard);
		break;
	default:
		cout << "ActivateCard: Unknown Card.";
		break;
	}
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
