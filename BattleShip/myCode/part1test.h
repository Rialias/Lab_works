/*
 * part1test.h
 *
 *  Created on: Dec 8, 2022
 *      Author: riyaa
 */


#ifndef PART1TEST_H_
#define PART1TEST_H_
///Header files
#include "Board.h"
#include <iostream>
#include <string>

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */

void assertTrue(bool condition, string failedMessage);

/**
 * Tests all the conditions of the part1
 */
void part1tests();


#endif /* PART1TEST_H_ */

