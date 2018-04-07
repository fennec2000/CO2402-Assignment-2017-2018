// Firebrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CCore.h"


int main()
{
	// Creat core
	CCore* c = CCore::GetInstance();

	// run the game
	while (c->GameRunning())
		c->PlayTurn();
	delete c; // clean up the game

	system("pause");
    return 0;
}

