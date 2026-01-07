/*
 * Ringbuffer.cpp
 *
 *  Created on: 23-Oct-2022
 *      Author: riyaa
 */


#include "Ringbuffer.h"



Ringbuffer::Ringbuffer(uint16_t size)
{
	m_size = size;
	m_pBuffer = new RB_content_t[m_size];

	clear();
}

Ringbuffer::~Ringbuffer()
{
	delete[] m_pBuffer;
}

RC_t Ringbuffer::put(RB_content_t data)
{
	if (m_fillLevel < m_size)
	{

		m_pBuffer[m_writeIdx] = data;

		m_writeIdx++;
		m_writeIdx %= m_size;

		m_fillLevel++;

		return RC_OK;


	}
	else
	{
		return RC_FULLBUFFER;
	}

	return RC_OK;
}

RC_t Ringbuffer::get(RB_content_t *const data)
{
	if (m_fillLevel > 0)
	{
		*data = m_pBuffer[m_readIdx];

		m_readIdx++;
		m_readIdx %= m_size;

		m_fillLevel--;

		return RC_OK;
	}
	else
	{
		return RC_EMPTYBUFFER;
	}
}

RC_t Ringbuffer::clear()
{
	m_fillLevel = 0;
	m_readIdx = 0;
	m_writeIdx = 0;

	return RC_OK;
}


