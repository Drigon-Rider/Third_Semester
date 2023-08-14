#include <stdio.h>
#include <conio.h>
#include <graphics.h>


void drawellipse(int x, int y, int xc, int yc) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Center and axes of the ellipse
    long xc, yc, rx, ry, x, y, p, pl;
    printf("Center: ");
    scanf("%ld %ld", &xc, &yc);
    printf("Value of rx:");
    scanf("%ld", &rx);
    printf("Value of ry:");
    scanf("%ld", &ry);

    x = 0;
    y = ry;
    drawellipse(x, y, xc, yc);
    delay(50);

    p = ry * ry - rx * rx * ry + rx * rx / 4;

    while (2 * ry * ry * x < 2 * rx * rx * y) {
        if (p < 0) {
            x = x + 1;
            y = y;
            p = p + 2 * ry * ry * x + ry * ry;
            drawellipse(x, y, xc, yc);
            delay(50);
        } else {
            x = x + 1;
            y = y - 1;
            p = p + 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
            drawellipse(x, y, xc, yc);
            delay(50);
        }
    }

    pl = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;

    while (y >= 0) {
        if (pl > 0) {
            x = x;
            y = y - 1;
            pl = pl - 2 * rx * rx * y + rx * rx;
            drawellipse(x, y, xc, yc);
            delay(50);
        } else {
            x = x + 1;
            y = y - 1;
            pl = pl + 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
            drawellipse(x, y, xc, yc);
            delay(50);
        }
    }

    getch();
    closegraph();
    return 0;
}
