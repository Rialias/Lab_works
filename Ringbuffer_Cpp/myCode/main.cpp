// Standard (system) header files
#include <iostream>
#include <stdlib.h>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
#include "Ringbuffer.h"

// Main program
int main (void)
{
    // TODO: Add your program code here
	cout << "Day5_RingbufferFinallyInCpp started." << endl << endl;

	Ringbuffer myBuffer(10);

	myBuffer.put(1);
	myBuffer.put(2);
	myBuffer.put(3);

	while(1)
	{
		RB_content_t data = 0;
		RC_t ret = myBuffer.get(&data);

		if (RC_OK != ret) break;

		printf("Just read %d from the buffer \n", data);

	}

	return 0;
}
