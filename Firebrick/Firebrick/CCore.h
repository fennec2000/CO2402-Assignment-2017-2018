#pragma once
#include "CPlayer.h"
#include "CVampire.h"
#include "CBless.h"
#include "CLighting.h"
#include "CFireBall.h"
#include "CMinion.h"
#include "CField.h"
#include <string> // string
#include <iostream> // cout
#include <fstream> // ifstream
#include <sstream>
using namespace std;

// CCore the core to the application, this is a singleton class
class CCore
{
private:
	// vatiables
	static CCore* pInstance;	// Here will be the instance stored.
	CPlayer* pSorceress;	// pointer to the sorc
	CPlayer* pWizard;	// pointer to the wiz
	CField* pField;	// the field / table
	int round = 0;	// current round
	const int MAX_ROUNDS = 30;	// maximum number of rounds

	// functions
	CCore();
	void LoadDeck(EPlayer playerName, string inputFile);
	void Draw(EPlayer player);
	void Turn(EPlayer player);
	void ActivateCard(EPlayer player, CCard* givenCard);
	void SendCardToGraveyard(CDamageable* target);
public:
	//Static access method.
	static CCore* GetInstance();
	~CCore();

	void LoadCards();
	void PlayTurn();
	int GetRounds() { return round; };
	bool GameRunning();
};

