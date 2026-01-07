/*
 * Board.cpp
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#include "Board.h"

/**
 * Constructor of the board class
 * \param int rows: The number of rows of the board ,default value 10
 * \param int columns : The number of columns of the board ,default value 10
*/
Board::Board(int rows, int columns):ownGrid(10,10), opponentGrid(10,10){
	this->columns = columns;
	this->rows = rows;
}

/**
 * Gets the number of rows of the board
 * \return int rows : number of rows
 */
int Board::getRows()
{
	return rows;
}

/**
 * Gets the number of columns of the board
 * \return int columns : number of columns
 */
int Board::getColumns()
{
	return columns;
}

/**
 * Gets the OwnGrid board
 * \return OwnGrid ownGrid : the OwnGrid board
 */
OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

/**
 * Gets the OpponentGrid board
 * \return OpponentGrid opponentGrid : the OpponentGrid board
 */
OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}
