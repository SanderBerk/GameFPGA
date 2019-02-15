//Credits naar Marlon

#include "tasks.h" //Zie dit bestand voor extern "C" voorbeeld.
#include "Game.h"
#include "ssd1306.h"
#include "fonts.h"




void cpptest()
{
	ssd1306_UpdateScreen();
    ssd1306_Fill(Black);
    ssd1306_SetCursor(0,0);
    ssd1306_WriteString("test", Font_7x10, White);
    osDelay(1000);
}

void init()
{


}

void cppmaintask_1(void *pvParameters)
{
	for(;;)
	{
		cpptest();
	}


}

void cppmaintask_2(void *pvParameters)
{
	for(;;)
	{

	}
}

