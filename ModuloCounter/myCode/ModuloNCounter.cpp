/*
 * ModuloNCounter.cpp
 *
 *  Created on: 01-Nov-2022
 *      Author: riyaa
 */
#include <iostream>
//Custom header files for the program
#include "ModuloNDigit.h"
#include "ModuloNCounter.h"

using namespace std;
/**
 * Constructor for ModuloNCounter
 * Initialises the attributes with the given values
 * \param unsigned int d : The number of digits
 * \param unsigned int t : The type of the number
 */
ModuloNCounter::ModuloNCounter(unsigned int d,unsigned int t)
{
		digits = d;
		type = t;
		scounter = new ModuloNDigit[digits];
}

/**
 * setCounter calls the setCounter in the ModuloNDigit in a loop until the max digit value is reached
 * \param unsigned int d : The number of digits
 * \param unsigned int t : The type of the number
 */
void ModuloNCounter::setCounter(unsigned int digits, unsigned int type)
{

	for(unsigned short i =0; i < digits; i++)
	{

		int overflow = scounter[i].setCounter(type);
		if(overflow == 0)
		{
			break;
		}
	}
}

/**
 *  Member Function
 *  printCounter calls the printCounter from ModuloNDigit in a loop from max digit until it reaches 0.
 */
void ModuloNCounter::printCounter()
{

	for(short i = (digits-1); i >=0; i--)
	{
		scounter[i].printCounter();
	}
}

/**
 * Checks if the entered digits and type is valid
 * \param unsigned int d :The number of digits
 * \param unsigned int t : The type of the number
 * \return bool : 1 if valid or else 0
 */
bool ModuloNCounter::isValid(unsigned int d, unsigned int t)
{
	if(((t == 2) || (t ==8) || (t ==16) || (t ==10)) && (d > 0) && (d<8))
	{
		return 1;
	}
	else
	{
		std::cout << "Invalid base or digits" << endl;
		return 0;
	}

}

/**
 * Destructor of the class
 * Frees the allocated memory
 */
ModuloNCounter::~ModuloNCounter()
{
	delete [] scounter;
}
