/*
 * GridPosition.h
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>
/*
 * GridPosition class :
 *
 * It allocates an specific row and column for each grid position.
 * It has row and column as private attributes.
 */
class GridPosition
{
private:
	char row;             /**< The row of the grid position */
	int column;           /**< The column of the grid position */
public:
	/**
	 * Constructor of the GridPosition class
	 * \param char row   : row of the grid position
	 * \param int column : column of the grid position
	 */
	GridPosition(char row, int column);

	/**
	 * Constructor of the GridPosition class
	 * \param string position: row and column of the grid position are represented as a string
	 */
	GridPosition(std::string position);

	/**
	 * Checks if the given GridPosition is valid or not. Checks whether the row is between A and z
	 * column is greater than 0.
	 * \return bool : 1 if the GridPosition is valid
	 */
	bool isValid();

	/**
	 *  Returns the row of the Grid
	 *  \return char row : the current row
	 */
	char getRow();

	/**
	 * Returns the column of the grid
	 * \return int column : the current column
	 */
	int getColumn();

	/**
	 * Operator overloading of std::string function.
	 * Converts the GridPosition(rows,columns) into a string format.
	 * \return std::string : the converted string
	 */
	operator std::string();

	/**
	 * Operator Overloading of == .
	 * Checks whether the given 2 GridPositions are equal or not.
	 * \param GridPosition other : The second GridPosition
	 * \return bool : 1 if both GridPositons are equal
	 */
	bool operator== (GridPosition other) const;

	/**
	 * Operator Overloading of <.
	 * Checks whether one GridPosition is less than the other.
	 * Less than operator is used as it is required in std::<set> functions also.
	 * \param GridPosition other : The second GridPosition
	 * \return bool : 1 if GridPosition 1 is less than 2nd one.
	 */
	bool operator< (const GridPosition &other) const;

};

#endif /* GRIDPOSITION_H_ */
