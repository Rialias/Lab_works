/*
 * ModuloNDigit.h
 *
 *  Created on: 27-Oct-2022
 *      Author: riyaa
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

/**
 * ModuloNDigit class
 *
 *  ModuloNDigit represents the class for single bit counter.
 */
class ModuloNDigit
{
protected:
	unsigned int type;     /**< base of the number (2/8/10/16) */
	unsigned int count;    /**< the count value */

public:
	/**
	 * Constructor
	 * Describes the constructor for the class ModuloNDigit.
	 * Initialises the attributes with the given values.
	 * if parameters are not specified take 10 and 0 as the default values for type and count respectively.
	 * \param unsigned int t : base of the number
	 * \param unsigned int c : the initial count value
	 */
	ModuloNDigit(unsigned int t=10, unsigned int c = 0);


	/**
	 * setCounter does the count operation on the given type.
	 * Increase the count till it reaches the maximum count value and then set it back to 0.
	 * \param unsigned int type : the type of the digit
	 * \return int - 0 ; if the count is less than the maximum value
	 * \return int - 1 ; if the count reaches the maximum value
	 */
	int setCounter(unsigned int type);

	/**
	 * printCounter prints the current count value.
	 * It takes no parameters and returns void.
	 */
	void printCounter();

	/**
	 *  Operator Overloading function for the pre-increment operation.
	 *  Increments the count value by 1 and then executes the operation.
	 *  \return this pointer of the ModuloNDigit class
	 */
	ModuloNDigit operator ++();

	/**
	 *  Operator Overloading function for the post-increment operation.
	 *  executes the operation and then increments the count value by 1
	 *  \param Dummy int value
	 *  \return this pointer of the ModuloNDigit class
	 */
	ModuloNDigit operator ++(int);
};


#endif /* MODULONDIGIT_H_ */
