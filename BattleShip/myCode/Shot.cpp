/*
 * Shot.cpp
 *
 *  Created on: Dec 9, 2022
 *      Author: riyaa
 */

#include "Shot.h"

/**
* Constructor of the Shot class.
* Initializes the target Position for the shot
* \param GridPosition targetPosition: The target position for the shot
*/
Shot::Shot(GridPosition targetPosition):targetPosition(targetPosition)
{
}

/**
 * Gets the GridPosition of the target
 * \return GridPosition targetPosition : the target position
 */
GridPosition Shot::getTargetPosition()
{
	return targetPosition;
}
