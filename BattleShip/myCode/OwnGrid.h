/*
 * OwnGrid.h
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_
///Header files
#include "vector"
#include "Ship.h"
#include <set>
#include <vector>
#include <map>

/**
 * OwnGrid class
 *
 * Shows the properties of our grid. It is used to place our ships.
 * It has rows, columns and std::vector of type Ship as its private attributes.
 */
class OwnGrid
{
private:
	int rows;					/**< The number of rows of OwnGrid */
	int columns;				/**< The number of columns of OwnGrid */
	std::vector<Ship> ships;    /**< A std::vector of Ships */
public:
	/**
	 * Constructor of the OwnGrid class.
	 * \param rows: The number of rows of OwnGrid, default value 10
	 * \param columns : The number of columns of OwnGrid, default value 10
	 */
	OwnGrid(int rows, int columns);

	/**
	 * Gets the rows of the OwnGrid
	 * \return int rows : The number of rows
	 */
	int getRows();

	/**
	 * Gets the columns of the OwnGrid
	 * \return int columns : The number of columns
	 */
	int getColumns();

	/**
	 * Place the ships on the OwnBoard.
	 * Before placing the Ships check whether the ship positions are valid. Also it checks
	 * whether the Occupied Area of the new ship is overlapping with the blocked area of existing ships.
	 * \param Ship ship : the Ship to be placed on the grid
	 * \return bool : 1 if we are able to place the ships correctly else 0.
	 */
	bool placeShip(const Ship& ship);

	/**
	 * Gets a vector of all the placed ships
	 * \return std::vector ships : contains all the placed ships.
	 */
	const std::vector<Ship> getShips();

	/**
	 * Maps the length of the ship with the allowed number of ships
	 * \return std::map<length,numberofships> allowedShips: with a map of ship length and the allowed number
	 * 											of ships for each length
	 */
	const std::map<int,int> numberofShips();
};

#endif /* OWNGRID_H_ */
