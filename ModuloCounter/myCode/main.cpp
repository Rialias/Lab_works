/// Standard (system) header files
#include <iostream>

/// Custom header files required for Modulo Counter
#include "ModuloNDigit.h"
#include "ModuloNCounter.h"


using namespace std;

/// Main program
int main ()
{

	/// Single Digit Counter
    ModuloNDigit sdigit(10, 0);
    cout << "Single bit Counter" << endl;

    ///Logic : Call the setCounter and printCounter in a loop
	for(int j=0; j<10; j++)
	{
		sdigit.setCounter(2);
		sdigit.printCounter();
	}
    cout << endl;

    /// MultiDigit Counter
	cout << endl <<"Multiple bit Counter" << endl;

	///Input Block
	unsigned int digits =2;
	unsigned int type = 2;

	/**
	 * Takes the number of digits and the required type (2/8/16/10) from the user
	 *  And continues in a loop until the type is 0.
	 */

	while(type != 0)
	{
		cout << "Enter the Parameters for your counter" << endl;
		cout << "number of digits :" << endl;
		cin >> digits;
		cout << "Enter type(2/8/16/10) :" << endl;
		cin >> type;

		///Logic
		ModuloNCounter ncounter(digits, type);
		bool a = ncounter.isValid(digits,type);
		if(a)
		{
			for (unsigned int i = 0; i < 10; i++)
				{
					ncounter.setCounter(digits, type);
					ncounter.printCounter();
					cout << endl;
				}
		}
	}

	///< Operator Overloading
	ModuloNDigit digit1;
	ModuloNDigit digit2(10,2);
	digit1 = digit2;                            /**< Copy value of digit2 to digit1 */
	cout << "Before Increment" <<endl;
	digit1.printCounter();
	cout << endl;

	digit1 = ++digit2;                          /**< Pre-increment digit2. */
	cout << "After Pre-Increment" <<endl;
	digit2.printCounter();
	cout << endl;

	digit1 = (digit2)++;                       /**< Post-increment digit2. */
	cout << "After Post-Increment" <<endl;
	digit1.printCounter();
	cout << endl;
	digit2.printCounter();
	cout << endl;


	return 0;
}
