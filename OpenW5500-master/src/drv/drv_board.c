/******************************************************************************
*        
*     Open source
*        
*******************************************************************************
*  file name:          drv_board.c
*  author:              Chen Hao
*  version:             1.00
*  file description:   driver utilities
*******************************************************************************
*  revision history:    date               version                  author
*
*  change summary:   2018-2-12      1.00                    Chen Hao
*
******************************************************************************/
/******************************************************************************
* Include Files
******************************************************************************/
#include "drv_board.h"

/******************************************************************************
* Macros
******************************************************************************/

/******************************************************************************
* Variables (Extern, Global and Static)
******************************************************************************/

/******************************************************************************
* Local Functions
******************************************************************************/

/******************************************************************************
* Function    : drv_board_init
* 
* Author      : Chen Hao
* 
* Parameters  : 
* 
* Return      : 
* 
* Description : board init
******************************************************************************/
void drv_board_init(void)
{
    SystemInit();

    NVIC_SetVectorTable(NVIC_VectTab_FLASH, DRV_BOARD_APP_OFFSET);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
}

/******************************************************************************
* Function    : drv_board_nvic_set_irq
* 
* Author      : Chen Hao
* 
* Parameters  : 
* 
* Return      : 
* 
* Description : set irq channel
******************************************************************************/
void drv_board_nvic_set_irq(uint8 IRQChannel, uint8 PreemptionPriority, uint8 SubPriority, FunctionalState Cmd)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PreemptionPriority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = SubPriority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = Cmd;
	NVIC_Init(&NVIC_InitStructure);		
}

