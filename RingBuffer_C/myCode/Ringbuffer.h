/*
 * Ringbuffer.h
 *
 *  Created on: Jan 18, 2023
 *      Author: riyaa
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_


#include "global.h"

typedef unsigned int RB_content_t;

typedef struct {
	RB_content_t* m_pBuffer;
	uint16_t m_size;
	uint16_t m_readIdx;
	uint16_t m_writeIdx;
	uint16_t m_fillLevel;
} RB_t;

RC_t RB_init(RB_t *const me, uint16_t size);
RC_t RB_deinit(RB_t *const me);
RC_t RB_put(RB_t *const me, RB_content_t data);
RC_t RB_get(RB_t *const me, RB_content_t *const data);
RC_t RB_clear(RB_t *const me);





#endif /* RINGBUFFER_H_ */
