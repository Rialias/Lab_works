/*
 * Ringbuffer.h
 *
 *  Created on: 23-Oct-2022
 *      Author: riyaa
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include "global.h"

typedef unsigned int RB_content_t;


class Ringbuffer
{
private:
	RB_content_t* m_pBuffer;
	uint16_t m_size;
	uint16_t m_readIdx;
	uint16_t m_writeIdx;
	uint16_t m_fillLevel;

public:
	Ringbuffer(uint16_t size = 5);
	virtual ~Ringbuffer();

	RC_t put(RB_content_t data);
	RC_t get(RB_content_t *const data);
	RC_t clear();
};


#endif /* RINGBUFFER_H_ */
