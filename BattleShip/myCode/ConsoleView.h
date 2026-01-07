/*
 * ConsoleView.h
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

/**
 * ConsoleView Class
 * Displays all the boards.
 */
class ConsoleView
{
private:
	Board* board;          /**< A Board pointer to display any general board */
	char* ownBoard;        /**< A pointer to character array to display OwnBoard */
	char* opponentBoard;	/**< A pointer to character array to display OpponentBoard */
public:
	/**
	 * Constructor of ConsoleView class.
	 * Initializes the ownBoard and opponentBoard boards with ~ character.
	 * \param Board* board : A pointer to Board class
	 */
	ConsoleView(Board* board);

	/**
	 * Prints the OwnGrid and OpponentGrid
	 */
	void print();
};

#endif /* CONSOLEVIEW_H_ */
