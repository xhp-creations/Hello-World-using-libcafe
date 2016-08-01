#include "main.h"
#include "draw.h"

void _osscreeninit()
{
	OSScreenInit();
	int buf0_size = OSScreenGetBufferSizeEx(0);
	OSScreenSetBufferEx(0, (void *)0xF4000000);
	OSScreenSetBufferEx(1, (void *)0xF4000000 + buf0_size);
    OSScreenEnableEx(0, 1);
    OSScreenEnableEx(1, 1);
}

void _clearscreen()
{
	int ii;
	for( ii = 0; ii < 2; ii++ )
	{
		fillScreen(0, 0, 0);
		flipBuffers();
	}
}

int main()
{
	_osscreeninit();
	_clearscreen();
    
    VPADInit();
	
	VPADStatus vpad_data;
	int error;
	while(1)
	{
		VPADRead(0, &vpad_data, 1, &error);
        
        fillScreen(0, 0, 0);
        
        drawString(0, 0, 0, 0, "Hello World!");

		if (vpad_data.hold & VPAD_BUTTON_A) {
            fillScreen(0, 0, 0);
            drawString(0, 0, 0, 0, "A Button Pressed!");
		}
        
        flipBuffers();

		if (vpad_data.trig & VPAD_BUTTON_HOME) {
			break;
		}
	}
	_clearscreen();
    
    return 0;
}
