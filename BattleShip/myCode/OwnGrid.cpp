/*
 * OwnGrid.cpp
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */
///Header files
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include "OwnGrid.h"

using namespace std;

/**
 * Constructor of the OwnGrid class.
 * \param rows: The number of rows of OwnGrid, default value 10
 * \param columns : The number of columns of OwnGrid, default value 10
 */
OwnGrid::OwnGrid(int rows, int columns):rows(10),columns(10)
{
	this->rows = rows;
	this->columns = columns;

}

/**
 * Gets the rows of the OwnGrid
 * \return int rows : The number of rows
 */
int OwnGrid::getRows()
{
	return rows;
}

/**
 * Gets the columns of the OwnGrid
 * \return int columns : The number of columns
 */
int OwnGrid::getColumns()
{
	return columns;
}

/**
 * Place the ships on the OwnBoard.
 * Before placing the Ships check whether the ship positions are valid. Also it checks
 * whether the Occupied Area of the new ship is overlapping with the blocked area of existing ships.
 * \param Ship ship : the Ship to be placed on the grid
 * \return bool : 1 if we are able to place the ships correctly else 0.
 */
bool OwnGrid::placeShip(const Ship &ship)
{
	Ship ship1 = ship;
	if(ship1.isValid())
	{

		std::vector<Ship> existing_ships = getShips();
		if(existing_ships.size()==0)
		{
			ships.push_back(ship);
			return 1;
		}
		else{
			for(Ship it: existing_ships)
			{
				std::set<GridPosition> new_occupiedarea = ship1.OccupiedArea();
				std::set<GridPosition> existing_blockedSet = it.blockedArea();
				std::vector<GridPosition> intersection;
				std::set_intersection(new_occupiedarea.begin(), new_occupiedarea.end(), existing_blockedSet.begin(),
					                              existing_blockedSet.end(),std::back_inserter(intersection));
				if(intersection.size()==0)
				{
					ships.push_back(ship);
					return 1;
				}
			}
		}
		return 0;
	}
	return 0;
}

/**
 * Gets a vector of all the placed ships
 * \return std::vector ships : contains all the placed ships.
 */
const std::vector<Ship> OwnGrid::getShips()
{
	return ships;
}

/**
 * Maps the length of the ship with the allowed number of ships
 * \return std::map<length,numberofships> allowedShips: with a map of ship length and the allowed number
 * 											of ships for each length
 */
const std::map<int, int> OwnGrid::numberofShips()
{
	map<int,int> allowedShips;
		allowedShips[5] = 1;
		allowedShips[4] = 2;
		allowedShips[3] = 3;
		allowedShips[2] = 4;
	return allowedShips;

}
