#include <stdio.h>
#include<conio.h>
#include <graphics.h>
#include<math.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100;
    int x2 = 400, y2 = 300;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    float x_increment = (float)dx / steps;
    float y_increment = (float)dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(ceil(x), ceil(y), WHITE);
        x += x_increment;
        y += y_increment;
    }
    getch();


    closegraph();
    return 0;
}
