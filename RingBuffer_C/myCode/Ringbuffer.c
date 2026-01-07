/*
 * Ringbuffer.c
 *
 *  Created on: Jan 18, 2023
 *      Author: riyaa
 */


#include <stdlib.h>
#include "Ringbuffer.h"

//Todo:error checking at many places

RC_t RB_init(RB_t *const me, uint16_t size)
{
	me->m_size = size;
	me->m_pBuffer = (RB_content_t*)malloc(size * sizeof(RB_content_t));

	return RB_clear(me);


}
RC_t RB_deinit(RB_t *const me)
{
	free(me->m_pBuffer);

	return RC_OK;
}

RC_t RB_put(RB_t *const me, RB_content_t data)
{
	if (me->m_fillLevel < me->m_size)
	{
		me->m_pBuffer[me->m_writeIdx] = data;

		me->m_writeIdx++;
		me->m_writeIdx %= me->m_size;

		me->m_fillLevel++;

		return RC_OK;

	}
	else
	{
		return RC_FULLBUFFER;
	}

	return RC_OK;
}


RC_t RB_get(RB_t *const me, RB_content_t *const data)
{
	if (me->m_fillLevel > 0)
	{
		*data = me->m_pBuffer[me->m_readIdx];

		me->m_readIdx++;
		me->m_readIdx %= me->m_size;

		me->m_fillLevel--;

		return RC_OK;
	}
	else
	{
		return RC_EMPTYBUFFER;
	}
}

RC_t RB_clear(RB_t *const me)
{
	me->m_fillLevel = 0;
	me->m_readIdx = 0;
	me->m_writeIdx = 0;

	return RC_OK;
}



