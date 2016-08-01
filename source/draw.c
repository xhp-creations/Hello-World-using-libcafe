#include "draw.h"

void flipBuffers()
{
    int buf0_size = OSScreenGetBufferSizeEx(0);
    int buf1_size = OSScreenGetBufferSizeEx(1);
    DCFlushRange((void *)0xF4000000, buf0_size);
    DCFlushRange((void *)0xF4000000 + buf0_size, buf1_size);
    OSScreenFlipBuffersEx(0);
    OSScreenFlipBuffersEx(1);
}

void fillScreen(char r,char g,char b)
{
    uint32_t num = (r << 24) | (g << 16) | (b << 8) | 0;
    OSScreenClearBufferEx(0, num);
    OSScreenClearBufferEx(1, num);
}

void drawString(int x1, int y1, int x2, int y2, char * string)
{
    OSScreenPutFontEx(0, x2, y2, string); // Draw Text to TV
    OSScreenPutFontEx(1, x1, y1, string); // Draw Text to DRC
}
