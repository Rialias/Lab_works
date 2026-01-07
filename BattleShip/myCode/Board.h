/*
 * Board.h
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#ifndef BOARD_H_
#define BOARD_H_
///Header files
#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * The Board Class
 *
 * Describes the attributes of a board. We have a OwnBoard and an OpponentBoard.
 */
class Board
{
private:
	int rows;            	/**< The number of rows of the board */
	int columns;			/**< The number of columns of the board */
	OwnGrid ownGrid;		/**< Our Own board */
	OpponentGrid opponentGrid;  /**< The opponent board */
public:
	/**
	 * Constructor of the board class
	 * \param int rows: The number of rows of the board ,default value 10
	 * \param int columns : The number of columns of the board ,default value 10
	 */
	Board(int rows, int columns);

	/**
	 * Gets the number of rows of the board
	 * \return int rows : number of rows
	 */
	int getRows();
	/**
	 * Gets the number of columns of the board
	 * \return int columns : number of columns
	 */
	int getColumns();

	/**
	 * Gets the OwnGrid board
	 * \return OwnGrid ownGrid : the OwnGrid board
	 */
	OwnGrid& getOwnGrid();

	/**
	 * Gets the OpponentGrid board
	 * \return OpponentGrid opponentGrid : the OpponentGrid board
	 */
	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
