#include <stdio.h>
#include <conio.h>
#include <graphics.h>

// Function to reflect a point along the line y = x
void reflectAlongYEqualsX(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to reflect a point along the line y = mx + c
void reflectAlongYEqualsMXPlusC(int *x, int *y, float m, float c) {
    int reflectedX = (*x - 2 * m * *y + 2 * m * c) / (1 + m * m);
    int reflectedY = (2 * m * *x + (m * m - 1) * *y + 2 * c) / (1 + m * m);
    *x = reflectedX;
    *y = reflectedY;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");

    // Scaling factor to fit the drawing within the window
    float scaleFactor = 0.5;

    int x1 = 300 * scaleFactor, y1 = 100 * scaleFactor;
    int x2 = 300 * scaleFactor, y2 = 300 * scaleFactor;
    int x3 = 500 * scaleFactor, y3 = 200 * scaleFactor;

    // Drawing the original triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Reflection along y = x
    reflectAlongYEqualsX(&x1, &y1);
    reflectAlongYEqualsX(&x2, &y2);
    reflectAlongYEqualsX(&x3, &y3);

    // Drawing the reflected triangle
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Resetting vertices to their original values
    x1 = 300 * scaleFactor; y1 = 100 * scaleFactor;
    x2 = 300 * scaleFactor; y2 = 300 * scaleFactor;
    x3 = 500 * scaleFactor; y3 = 200 * scaleFactor;

    // Reflection along y = mx + c
    float m = 1;
    float c = 150 * scaleFactor;
    reflectAlongYEqualsMXPlusC(&x1, &y1, m, c);
    reflectAlongYEqualsMXPlusC(&x2, &y2, m, c);
    reflectAlongYEqualsMXPlusC(&x3, &y3, m, c);

    // Drawing the second reflected triangle
    setcolor(GREEN);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();
    return 0;
}
