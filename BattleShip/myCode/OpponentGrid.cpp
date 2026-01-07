/*
 * OpponentGrid.cpp
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#include "OpponentGrid.h"

/**
* Constructor of the OpponentGrid class
* \param int rows : The number of rows of the  opponent grid, default value 10
* \param int columns : The number of columns of the  OpponentGrid, default value 10
*/
OpponentGrid::OpponentGrid(int rows, int columns):rows(10),columns(10)
{
	this->columns = columns;
	this->rows = rows;
}

/**
 * Gets the rows of the OpponentGrid
 * \return int rows : the number of rows
 */
int OpponentGrid::getRows()
{
	return rows;
}

/**
 * Gets the columns of the OpponentGrid
 * \return int columns : the number of columns
 */
int OpponentGrid::getColumns()
{
	return columns;
}
