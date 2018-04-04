// Firebrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CCore.h"


int main()
{
	// Creat core
	CCore* c = CCore::GetInstance();

	while (c->GameRunning())
		c->PlayTurn();

	system("pause");
	delete c;
    return 0;
}

