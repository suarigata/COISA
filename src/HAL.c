/***************************************************************************
 *   Copyright (C) 2015 by                                                 *
 *   - Carlos Eduardo Millani (carloseduardomillani@gmail.com)             *
 *   - Edson Borin (edson@ic.unicamp.br)                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif    

#include "HAL.h"
#include "vm.h"
#if PRINTING
#include <stdio.h>
#endif

/*Defined peripherals ids:
	Ultrasonic		0
	Serial			1
	Encoder			2
*/

uint8_t hal_call(uint32_t sensid)//Call to hardware I/O
{
	uint8_t retval = -1;
	switch (sensid)
	{
#if HAS_ULTRASONIC // Verify if there is an ultrasonic sensor built
		case 0: { //Read Ultrasonic
#if PRINTING
			printf("(HAL)Read Ultra called\n");
#endif // PRINTING
			break;
		}
		case 1: {
#if PRINTING
			printf("(HAL)Config Ultra called\n");
#endif // PRINTING
			break;
		}
#endif // HAS_ULTRASONIC
		
#if HAS_ENCODER // Verify if there is an encoder built
		case 5 : {
#if PRINTING
			printf("(HAL)Read Encoder Count called\n");
#endif // PRINTING	
			// read_encoder_counter(0);
			break;
		}
		case 6 : {
#if PRINTING
			printf("(HAL)Read Encoder Time called\n");
#endif // PRINTING	
			break;
		}
#endif // HAS_ENCODER
		
#if HAS_SERIAL // Verify if there is a Serial IO built
		case 10: {
#if PRINTING
			printf("(HAL)Send Byte called\n");
#endif // PRINTING	
			send_byte(RF[4]);
			break;
		}
		case 11: {
#if PRINTING
			printf("(HAL)Read Byte called\n");
#endif // PRINTING
			RF[2] = read_byte();	
			break;	
		}
		case 12: {
#if PRINTING
			printf("(HAL)Configure serial called\n");
#endif // PRINTING	
			serial_configure(RF[4]); //TODO: Allow user to enable and disable interruptions later
			break;
		}
		case 13: {
#if PRINTING
			printf("(HAL)Print number called\n");
#endif // PRINTING	
			printnum(RF[4]); 
			break;
		}
		case 14: {
#if PRINTING
			printf("(HAL)Print string called\n");
			printf(">>%d\n",RF[4]);
#endif // PRINTING	
			print(&VM_memory[RF[4]]);
			break;
		}
#endif // HAS_SERIAL

#if HAS_MOTORS // Verify if there are configured motors output
		case 15: {
#if PRINTING
			printf("(HAL)Ahead called\n");
#endif		
			break;
		}
		case 16: { 
#if PRINTING
			printf("(HAL)Right called\n");
#endif		
			break;
		}
		case 17: {
#if PRINTING
			printf("(HAL)Left called\n");
#endif		
			break;
		}
		case 20: {
#if PRINTING
			printf("(HAL)PWM called\n");
#endif		
			break;
		}
#endif // HAS_MOTORS
		default:
#if PRINTING
			printf("(HAL) error - Unknown Hal Call number\n");
#endif		
			break;
	}
	return retval;
}

#ifdef __cplusplus
}
#endif