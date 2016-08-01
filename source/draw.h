#ifndef DRAW_H
#define DRAW_H
#include "main.h"
#include <wiiu.h>

void flipBuffers();
void fillScreen(char r, char g, char b);
void drawString(int x1, int y1, int x2, int y2, char * string);

#endif /* DRAW_H */