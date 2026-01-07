/*
 * GridPosition.cpp
 *
 *  Created on: 24-Nov-2022
 *      Author: riyaa
 */

#include "GridPosition.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Constructor of the GridPosition class
 * \param char row : row of the grid position
 * \param int column : column of the grid position
 */
GridPosition::GridPosition(char row, int column):row(row), column(column)
{
}

/**
 * Constructor of the GridPosition class
 * \param string position: row and column of the grid position are represented as a string
 */
GridPosition::GridPosition(std::string position)
{
	this->row = position[0];
	this->column = std::stoi(position.substr(1,2));

}

/**
 * Checks if the given GridPosition is valid or not. Checks whether the row is between A and z
 * column is greater than 0.
 * \return bool : 1 if the GridPosition is valid
 */
bool GridPosition::isValid()
{
	if(row < 'A' || row > 'Z' || column < 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/**
 *  Returns the row of the Grid
 *  \return char row : the current row
 */
char GridPosition::getRow()
{
	return row;
}

/**
 * Returns the column of the grid
 * \return int column : the current column
 */
int GridPosition::getColumn()
{
	return column;
}

/**
 * Operator Overloading of == .
 * Checks whether the given 2 GridPositions are equal or not.
 * \param GridPosition other : The second GridPosition
 * \return bool : 1 if both GridPositons are equal
 */
bool GridPosition::operator ==(GridPosition other) const
{
	if(row == other.row && column == other.column)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 * Operator Overloading of <.
 * Checks whether one GridPosition is less than the other.
 * Less than operator is used as it is required in std::<set> functions also.
 * \param GridPosition other : The second GridPosition
 * \return bool : 1 if GridPosition 1 is less than 2nd one.
 */
bool GridPosition::operator< (const GridPosition &other) const
{
	if((row < other.row) || (column < other.column))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 * Operator overloading of std::string function.
 * Converts the GridPosition(rows,columns) into a string format.
 * \return std::string : the converted string
 */
GridPosition::operator std::string()
{
	string a = "empty";
	char r = this->getRow();
	string c = to_string(this->getColumn());
	a = r;
	a = a+c;
	return a;
}

