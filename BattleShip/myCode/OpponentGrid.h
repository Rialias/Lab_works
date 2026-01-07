/*
 * OpponentGrid.h
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_
///Header files
#include <vector>
#include "Ship.h"
#include "GridPosition.h"


/**
 * OpponentGrid Class
 *
 * It contains all the details of the opponent's grid.
 * It has rows, columns and std::vector of type Ship as its private attributes
 */
class OpponentGrid
{
private:
	int rows;            /**< The number of rows of the  opponent grid*/
	int columns;		/**< The number of columns of the  opponent grid*/
	std::vector<Ship> sunkenShips;    /**< A vector with details of the sunkenShips of the opponent */
public:
	/**
	 * Constructor of the OpponentGrid class
	 * \param int rows : The number of rows of the  opponent grid, default value 10
	 * \param int columns : The number of columns of the  OpponentGrid, default value 10
	 */
	OpponentGrid(int rows, int columns);

	/**
	 * Gets the rows of the OpponentGrid
	 * \return int rows : the number of rows
	 */
	int getRows();

	/**
	 * Gets the columns of the OpponentGrid
	 * \return int columns : the number of columns
	 */
	int getColumns();

};

#endif /* OPPONENTGRID_H_ */
