/*
 * ModuloNCounter.h
 *
 *  Created on: 01-Nov-2022
 *      Author: riyaa
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

#include "ModuloNDigit.h"
/**
 * Class ModuloNCounter
 *
 * It represents the counter for multiple digits.
 * Inherits type and count value from ModuloNDigit
 */

class ModuloNCounter : public ModuloNDigit
{
private:
	unsigned int digits;     /**< The number of digits in the given value */
	ModuloNDigit *scounter;  /**<  pointer to the single digit counter */

public:
	/**
	 * Constructor for ModuloNCounter
	 * Initialises the attributes with the given values
	 * \param unsigned int d : The number of digits
	 * \param unsigned int t : The type of the number
	 */
	ModuloNCounter(unsigned int d,unsigned int t);

	/**
	 * Checks if the entered digits and type is valid
	 * \param unsigned int d :The number of digits
	 * \param unsigned int t : The type of the number
	 * \return bool : 1 if valid or else 0
	 */
	bool isValid(unsigned int d,unsigned int t);

	/**
	 * setCounter calls the setCounter in the ModuloNDigit in a loop until the max digit value is reached
	 * \param unsigned int d : The number of digits
	 * \param unsigned int t : The type of the number
	 */
	void setCounter(unsigned int digits, unsigned int type);

	/**
	 *  Member Function
	 *  printCounter calls the printCounter from ModuloNDigit in a loop from max digit until it reaches 0.
	 */
	void printCounter();

	/**
	 * Destructor of the class
	 * Frees the allocated memory
	 */
	~ModuloNCounter();

};

#endif /* MODULONCOUNTER_H_ */
