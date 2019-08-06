#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
#include "posnBall.h"
void animate_rht(uchar colInit, bool erase, uchar offsetUp, uchar offsetDwn)
{
    uchar col;
    for (col = colInit; col < colInit + 3; col++)   // show the ball at the start position col = 0, page 1
    {
        //set_address(col,page);   // x = 0, page = 1
        /*if(offsetUp >= 0)
        {
            lcdWrite(ball[0]>>offsetUp|gameplay_area[page][col], HIGH); 
        }
        else 
        {
           lcdWrite(ball[0]<<offsetDwn|gameplay_area[page][col], HIGH);  
        }*/
        //lcdWrite(ball[0]<<offsetDwn|gameplay_area[page][col], HIGH);  
        posnBall(col,offsetDwn,offsetUp,erase);
    }
}
