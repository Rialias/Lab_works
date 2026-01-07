#include <stdio.h>
#include "Ringbuffer.h"

int main (void)
{

	RB_t myRingbuffer = {};
	//RB_t myRingbuffer2 = {};


	//Todo: Check return values
	RB_init(&myRingbuffer, 10);

	RB_put(&myRingbuffer, 1);
	RB_put(&myRingbuffer, 2);
	RB_put(&myRingbuffer, 3);

	while(1)
	{
		RB_content_t data = 0;
		RC_t ret = RB_get(&myRingbuffer, &data);

		if (RC_OK != ret) break;

		printf("Just read %d from the buffer \n", data);

	}

	return 0;
}
