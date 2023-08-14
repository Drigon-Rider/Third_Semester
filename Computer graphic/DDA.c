#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm, i;
    float x, y, dx, dy, steps;
    int x0, x1, y0, y1;
    initgraph(&gd, &gm, " ");   
    x0 = 300, y0 = 200, x1 = 1, y1 = 1;   
    int isSwapped = 0; 
    
    if (x0 > x1) {
        // Swap the points
        int tempX = x0, tempY = y0;
        x0 = x1;
        y0 = y1;
        x1 = tempX;
        y1 = tempY;
        isSwapped = 1;
    }
    
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);
    
    if (dx >= dy) {
        steps = dx;
    }
    else {
        steps = dy;
    }
    
    dx = dx / steps;
    dy = dy / steps;
    
    x = x0;
    y = y0;
    
    i = 1;
    
    while (i <= steps) {
        putpixel(x, y, RED);
        x += dx;
        y += dy;
        i = i + 1;
    }
    
    // Swap the points back for correct endpoint coordinates
    if (isSwapped) {
        int tempX = x0, tempY = y0;
        x0 = x1;
        y0 = y1;
        x1 = tempX;
        y1 = tempY;
    }
    
    // Draw the endpoint pixels
    putpixel(x0, y0, RED);
    putpixel(x1, y1, RED);
    
    getch();
    closegraph();
    return 0;
}
