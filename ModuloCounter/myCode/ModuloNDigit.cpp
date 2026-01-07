/*
 * ModuloNDigit.cpp
 *
 *  Created on: 27-Oct-2022
 *      Author: riyaa
 */

// Standard header files
#include <iostream>
//Custom header files required for the Modulo Counter
#include "ModuloNDigit.h"

using namespace std;

/**
 * Constructor
 * Describes the constructor for the class ModuloNDigit.
 * Initialises the attributes with the given values.
 * if parameters are not specified take 10 and 0 as the default values for type and count respectively.
 * \param unsigned int s : base of the number
 * \param unsigned int count : the initial count value
 */
ModuloNDigit::ModuloNDigit(unsigned int t, unsigned int c)
{
	type = t;
	count = c;
}

/**
 * setCounter does the count operation on the given type.
 * Increase the count till it reaches the maximum count value and then set it back to 0.
 * \param unsigned int type : the type of the digit
 * \return int - 0 ; if the count is less than the maximum value
 * \return int - 1 ; if the count reaches the maximum value
 */
int ModuloNDigit::setCounter(unsigned int type)
{
	if((type-1) > count)
	{
		count++;
		return 0;
    }
	else{
		count = 0;
		return 1;
	}

}

/**
 * printCounter prints the current count value.
 * It takes no parameters and returns void.
 */
void ModuloNDigit::printCounter()
{
	cout << std::hex << count;
}

/**
 *  Operator Overloading function for the pre-increment operation.
 *  Increments the count value by 1 and then executes the operation.
 *  \return this pointer of the ModuloNDigit class
 */

ModuloNDigit ModuloNDigit::operator ++()
{
	++(this->count);
	return *this;
}

/**
 *  Operator Overloading function for the post-increment operation.
 *  executes the operation and then increments the count value by 1
 *  \param Dummy int value
 *  \return this pointer of the ModuloNDigit class
 */
ModuloNDigit ModuloNDigit::operator ++(int)
{
	ModuloNDigit temp(0,0);

	temp.count = (this->count)++;
	return temp;
}
