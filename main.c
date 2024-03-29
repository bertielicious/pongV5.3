/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 20 July 2019, 11:07
 */
/*                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
 *Player select  2 |RA5      | 19
 * Paddle up  L  3 |RA4      | 18
 *    MCLR/ RST  4 |         | 17
 *    GREEN LED  5 |RC5      | 16
 *           CE  6 |RC4      | 15
 *RST op to 5110 7 |         | 14  RC2 Paddle down L
 *           SS  8 |         | 13 
 *           SDO 9 |         | 12
 *           TX 10 |         | 11  SCK
 *                  ---------
 
 */



#include "config.h"
#include <stdio.h>
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "set_usart.h"
#include "putch.h"
#include "lcd_setup.h"
#include "TMR0_setup.h"
#include "TMR1_setup.h"
#include "interrupt isr.h"
#include "lcdWrite.h"
#include "set_address.h"
#include "set_game_area.h"
#include "TMR1_setup.h"
#include "eraseBall.h"
#include "animate_rht.h"
#include "posnBall.h"

void main(void) 
{
config_osc();       // internal clock frequency = 8MHz
setup_ports();      
init_spi();
set_usart();
lcd_setup();        // configures the LCD
set_game_area();
static uchar x, col, row, offsetDwn, offsetUp = 0;
//offsetDwn = 46;


while(1)
    {
 
    for (col = 0; col < 82; col++)
{
       
    animate_rht(col,0,offsetDwn,offsetUp); //erase = 0, offsetDwn = 5, offsetUp = 0;
    __delay_ms(50);
    
     if(col<80)
    animate_rht(col,1, offsetDwn,offsetUp);  
    if(col%5 == 0)
    {
        offsetDwn++;
    }
}
for (col = 81; col >=1; col--)
{
    animate_rht(col,0,offsetDwn,offsetUp); //erase = 0, offsetDwn = 5, offsetUp = 0;
    __delay_ms(50);
    
     if(col>=2)
    animate_rht(col,1, offsetDwn,offsetUp); 
    if(col%6 == 0)
    {
        offsetDwn--;
    }
}
    
    
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
}