/*
 * Ship.h
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#ifndef SHIP_H_
#define SHIP_H_
///Header files
#include <iostream>
#include <set>
#include "GridPosition.h"


/**
 * Ship Class
 *
 * It deals with the characteristics of the Ship.
 * It has bow and stern as its private attributes.
 */
class Ship
{
private:
	GridPosition bow;         /**< The GridPosition of the bow of the ship */
	GridPosition stern;		  /**< The GridPosition of the stern of the ship */
public:
	/**
	 * Constructor of the Ship class.
	 * \param GridPosition bow   : The GridPosition of the bow of the ship
	 * \param GridPosition stern : The GridPosition of the stern of the ship
	 */
	Ship(const GridPosition& bow, const GridPosition& stern);

	/**
	 * Checks whether the ship positions are correct.
	 * The length of the ship should be between 2 and 5 (including 2 & 5).
	 * And the ship can be placed horizontally or vertically only.
	 * \return bool : 1 if the shape is placed correctly or else 0.
	 */
	bool isValid();

	/**
	 * Gets the GridPosition of the bow.
	 * \return GridPosition : The GridPositions of the bow
	 */
	GridPosition getBow();

	/**
	 * Gets the GridPosition of the stern.
	 * \return GridPosition : The GridPositions of the stern
	 */
	GridPosition getStern();

	/**
	 * Calculates the length of the ship
	 * \return int : length of the ship
	 */
	int length();

	/**
	 * Creates a set of the occupied GridPositions of the Ship.
	 * The cells from bow to stern will be occupied.
	 * \return set<GridPosition> OccupiesSet : The occupied cells of the ship
	 */
	const std::set<GridPosition> OccupiedArea();

	/**
	 * Creates a set of blocked areas of the ship.
	 * All the Occupied cells and its surrounding cells are considered as blocked
	 * \return set<GridPosition> blockedArea : the blocked areas of the ship
	 */
	const std::set<GridPosition> blockedArea();

};

#endif /* SHIP_H_ */
