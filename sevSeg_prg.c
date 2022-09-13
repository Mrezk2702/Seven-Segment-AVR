#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "sevSeg_private.h"
#include "sevSeg_cfg.h"
u8 NUM[10]={0b00111111,0b00000110,0b01011011,
			0b01001111,0b01100110,0b01101101,
			0b01111101,0b00000111,0b01111111,0b01101111};




/* Function takes port number and the desired number to display
*  on the seven segment
*/
void sevSeg_VidDisplayNumber(u8 Copy_U8PortNum,u8 Copy_U8Number)
{
	if(Copy_U8PortNum>=0&&Copy_U8PortNum<4)
	{
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