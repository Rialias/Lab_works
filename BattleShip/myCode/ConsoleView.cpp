/*
 * ConsoleView.cpp
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#include <iostream>
#include <vector>
#include "Ship.h"
#include "ConsoleView.h"

using namespace std;

/**
 * Constructor of ConsoleView class.
 * Initializes the ownBoard and opponentBoard boards with ~ character.
 * \param Board* board : A pointer to Board class
 */
ConsoleView::ConsoleView(Board *board)
{
	this->board = board;

	ownBoard = new char[board->getOwnGrid().getRows() * board->getOwnGrid().getColumns()];
	for(int i=0; i<(board->getOwnGrid().getRows() * board->getOwnGrid().getColumns()); i++)
	{
		ownBoard[i]= '~';
	}
	opponentBoard = new char[board->getOpponentGrid().getRows() * board->getOpponentGrid().getColumns()];
	for(int i=0; i<(board->getOpponentGrid().getRows() * board->getOpponentGrid().getColumns()); i++)
	{
		opponentBoard[i]= '~';
	}

}

/**
 * Prints the OwnGrid and OpponentGrid
 */
void ConsoleView::print()
{
	///Sets all the occupied areas of the ship to '#' character.
	std::vector<Ship> ships =board->getOwnGrid().getShips();
	for(Ship i: ships)
	{
		for(GridPosition j: i.OccupiedArea())
		{
			int a= (int)(j.getRow()-'A') ;
			ownBoard[(a*board->getColumns()) + (j.getColumn()-1)] = '#';
		}
	}


	cout<<"  1 2 3 4 5 6 7 8 9 0          1 2 3 4 5 6 7 8 9 0" << endl;
	for(int r=0; r<(board->getOwnGrid().getRows()); r++)
	{
		cout << char(r+65);
		for(int c=0; c<(board->getOwnGrid().getColumns());c++)
		{
			cout <<" ";
			cout << *(ownBoard+(r*(board->getOwnGrid().getColumns()) + c));
		}
		cout << "         ";
		cout << char(r+65);
		for(int j=0; j<(board->getOpponentGrid().getColumns());j++)
		{
			cout <<" ";
			cout << *(opponentBoard+(r*(board->getOpponentGrid().getColumns()) + j));
		}
		cout << endl;
	}

}
