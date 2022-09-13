/*********************************************************************/
/*********************************************************************/
/**********Author: Mohamed Rezk Bayoumi*******************************/
/**********File: sevSeg_prg.c.h***********************************/
/**********Date: 2nd sep 2022*****************************************/
/**********Version: V1************************************************/
/********* Desc: In order to use this driver you must include ********/
/****************the dio driver check for its repo in my profile******/
/*************** https://github.com/Mrezk2702/DIO_Driver ************/


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "sevSeg_private.h"
#include "sevSeg_cfg.h"
u8 NUM[10]={ZERO,ONE,TWO,
			THREE,FOUR,FIVE,
			SIX,SEVEN,EIGHT,NINE};




/* Function takes port number and the desired number to display
*  on the seven segment
*/
void sevSeg_VidDisplayNumber(u8 Copy_U8PortNum,u8 Copy_U8Number)
{

	if(Copy_U8PortNum>=PORTA&&Copy_U8PortNum<=PORTD)
	{
		DIO_VidSetPortDirection(Copy_U8PortNum,0xff);
		if(Copy_U8Number>=0&&Copy_U8Number<10)
		{
			#if SEVSEG_TYPE == COM_CATHODE
				DIO_VidSetPortValue(Copy_U8PortNum,NUM[Copy_U8Number]);
			#elif  SEVSEG_TYPE == COM_ANODE
				DIO_VidSetPortValue(Copy_U8PortNum,(~NUM[Copy_U8Number]));
			#else 
				#error  "Wrong input !!!"
			#endif
		}
	}
	
}