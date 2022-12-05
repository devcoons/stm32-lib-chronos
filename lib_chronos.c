/*!
	@file   lib_chronos.c
    @brief  <brief description here>
	@t.odo	-

	MIT License
	Copyright (c) 2020 Ioannis Deligiannis, Federico Carnevale
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/
/******************************************************************************
* Preprocessor Definitions & Macros
******************************************************************************/

/******************************************************************************
* Includes
******************************************************************************/

#include "lib_chronos.h"

/******************************************************************************
* Enumerations, structures & Variables
******************************************************************************/

/******************************************************************************
* Declaration | Static Functions
******************************************************************************/

/******************************************************************************
* Definition  | Static Functions
******************************************************************************/

/******************************************************************************
* Definition  | Public Functions
******************************************************************************/

i_status chronos_tl_init()
{
	__disable_irq();
	__enable_irq();
	return I_OK;
}

i_status chronos_tl_start(timelapse_t * arg)
{
	__disable_irq();
	arg->start_tick = HAL_GetTick();
	arg->end_tick = 0;
	arg->diff_ms = 0;
	arg->timeout = 0;
	__enable_irq();
	return I_OK;
}

i_status chronos_tl_stop(timelapse_t* arg)
{
	__disable_irq();
	arg->end_tick = HAL_GetTick();
	arg->diff_ms =  ((arg->start_tick < arg->end_tick) ? (arg->end_tick - arg->start_tick) : (arg->start_tick - arg->end_tick)) ;
	__enable_irq();
	return I_OK;
}

i_status chronos_tout_start(timelapse_t * arg,uint32_t timeout)
{
	__disable_irq();
	arg->start_tick = HAL_GetTick();
	arg->end_tick = 0;
	arg->diff_ms = 0;
	arg->timeout = timeout;
	__enable_irq();
	return I_OK;
}

i_status chronos_tout_is_expired(timelapse_t* arg)
{
	return iTIMEOUT(HAL_GetTick(),arg->start_tick, arg->timeout) == 1 ? I_EXPIRED : I_OK;
}

i_status chronos_tout_refresh(timelapse_t * arg)
{
	__disable_irq();
	arg->start_tick = HAL_GetTick();
	__enable_irq();
	return I_OK;
}

i_status chronos_tout_set_timeout(timelapse_t* arg, uint32_t timeout)
{
	__disable_irq();
	arg->timeout = timeout;
	__enable_irq();
	return I_OK;
}

/******************************************************************************
* EOF - NO CODE AFTER THIS LINE
******************************************************************************/
