#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
int main()
{
    int gd = DETECT, gm, i;
    initgraph(&gd, &gm, " ");
    int x0, y0, x1, y1, x, y, p;
    int dx, dy;
    printf("Enter the two points: ");
    scanf("%d %d", &x0, &y0);
    printf("Enter the next two points: ");
    scanf("%d %d", &x1, &y1);
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;

    p = 2 * dy - dx;

    while (x < x1)
    {
        if (p >= 0)
        {
            putpixel(x, y, 7);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, 7);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
    getch();
    closegraph();
    return 0;
}