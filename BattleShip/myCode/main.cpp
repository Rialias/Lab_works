// Standard (system) header files
#include <iostream>


using namespace std;

///Header files
#include "GridPosition.h"
#include "Ship.h"
#include "OwnGrid.h"
#include "OpponentGrid.h"
#include "Board.h"
#include "ConsoleView.h"
#include "part1test.h"

// Main program
int main ()
{
	///Input
	Board myboard(10,10);
	ConsoleView console(&myboard);
	GridPosition grid1('B',2);
	GridPosition grid2('B',4);
	GridPosition grid3('D',4);
	GridPosition grid4('G',4);
	GridPosition grid5('F',6);
	GridPosition grid6('F',9);

	Ship ship1(grid1,grid2);
	Ship ship2(grid3,grid4);
	Ship ship3(grid5,grid6);

	///Logic
	myboard.getOwnGrid().placeShip(ship1);
	myboard.getOwnGrid().placeShip(ship2);
	myboard.getOwnGrid().placeShip(ship3);

	///Output
	part1tests();
	cout << endl;
	console.print();

	return 0;
}
