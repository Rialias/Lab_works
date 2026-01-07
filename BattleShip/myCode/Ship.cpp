/*
 * Ship.cpp
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */
///Header files
#include <ostream>

#include "Ship.h"
#include "GridPosition.h"

using namespace std;

/**
 * Constructor of the Ship class.
 * \param GridPosition bow   : The GridPosition of the bow of the ship
 * \param GridPosition stern : The GridPosition of the stern of the ship
 */
Ship::Ship(const GridPosition& bow, const GridPosition& stern): bow(bow),stern(stern)
{
}

/**
 * Checks whether the ship positions are correct.
 * The length of the ship should be between 2 and 5 (including 2 & 5).
 * And the ship can be placed horizontally or vertically only.
 * \return bool : 1 if the shape is placed correctly or else 0.
 */
bool Ship::isValid()
{
	int l =length();
	if(bow.getRow() == stern.getRow() || bow.getColumn() == stern.getColumn())
	{
		if(l > 1 && l < 6)
		{
			return 1;
		}
		else return 0;

	}
	return 0;

}

/**
 * Gets the GridPosition of the bow.
 * \return GridPosition : The GridPositions of the bow
 */
GridPosition Ship::getBow()
{
	return bow;
}

/**
 * Gets the GridPosition of the stern.
 * \return GridPosition : The GridPositions of the stern
 */
GridPosition Ship::getStern()
{
	return stern;
}

/**
 * Calculates the length of the ship
 * \return int : length of the ship
 */
int Ship::length()
{
	int length= 0;
	if(bow.getRow() == stern.getRow())
	{
		length = (stern.getColumn()- bow.getColumn())+1;
	}
	else if(bow.getColumn() == stern.getColumn())
	{
		length = (int)(stern.getRow()- bow.getRow())+1;

	}
	return length;
}

/**
 * Creates a set of the occupied GridPositions of the Ship.
 * The cells from bow to stern will be occupied.
 * \return set<GridPosition> OccupiesSet : The occupied cells of the ship
 */
const std::set<GridPosition> Ship::OccupiedArea()
{
	set<GridPosition> OccupiedSet;
	char r = bow.getRow();
	int c = bow.getColumn();
	if (bow.getRow() == stern.getRow())
	{
		for (auto it = bow.getColumn(); it != stern.getColumn() + 1; it++)
		{
			OccupiedSet.insert(GridPosition{ r, c++ });
		}
	}
	else if (bow.getColumn() == stern.getColumn())
	{
		for (auto it = bow.getRow(); it != stern.getRow()+ 1; it++)
		{
			OccupiedSet.insert(GridPosition{ r++, c});
		}
	}
	return OccupiedSet;
}

/**
 * Creates a set of blocked areas of the ship.
 * All the Occupied cells and its surrounding cells are considered as blocked
 * \return set<GridPosition> blockedArea : the blocked areas of the ship
 */
const std::set<GridPosition> Ship::blockedArea()
{
	set<GridPosition> blockedSet;
	set<GridPosition> temp = OccupiedArea();

	for(GridPosition it : temp)
	{
		char r = it.getRow();
		int c = it.getColumn();
		blockedSet.insert(GridPosition{char(int(r)+1),c+1});
		blockedSet.insert(GridPosition{char(int(r)-1),c-1});
		blockedSet.insert(GridPosition{char(int(r)),c-1});
		blockedSet.insert(GridPosition{char(int(r)),c+1});
		blockedSet.insert(GridPosition{char(int(r)-1),c});
		blockedSet.insert(GridPosition{char(int(r)+1),c});
		blockedSet.insert(GridPosition{char(int(r)-1),c+1});
		blockedSet.insert(GridPosition{char(int(r)+1),c-1});
	}
	return blockedSet;
}

