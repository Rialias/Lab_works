/*
 * Shot.h
 *
 *  Created on: Dec 9, 2022
 *      Author: riyaa
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"
/**
 * Shot Class.
 * Maintains information of all the Shots fired.
 */
class Shot
{
private:
	GridPosition targetPosition;      /**< The GridPosition for the shot target */
public:
	/**
	 * Constructor of the Shot class.
	 * Initializes the target Position for the shot
	 * \param GridPosition targetPosition: The target position for the shot
	 */
	Shot(GridPosition targetPosition);

	/**
	 * Gets the GridPosition of the target
	 * \return GridPosition targetPosition : the target position
	 */
	GridPosition getTargetPosition();

	/**
	 * An enumerator to show the impact of the shots
	 * NONE : if no ships have been hit
	 * HIT : if the ship has been hit
	 * SUNKEN : if the ship has sunk
	 */
	enum Impact
	{
		NONE,     /**< No ships have been hit */
		HIT,	  /**< Ships has been hit */
		SUNKEN    /**< The ship has sunk */
	};
};


#endif /* SHOT_H_ */
