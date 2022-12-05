/*!
	@file   lib_chronos.c
    @brief  <brief description here>

	@t.odo	-
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
