#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

void draw();
void scale();
void pivot();
void rotate();
void multiplyMatrix(float a[3][3], float b[3][3], float result[3][3]);

int n = 3, x[100], y[100], i, sx, sy, fixedx, fixedy;
float theta;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    printf("Enter co-ordinates:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    
    printf("Enter the factor to be scaled (in both x and y direction): ");
    scanf("%d%d", &sx, &sy);

    printf("Enter the rotation angle in degrees: ");
    scanf("%f", &theta);

    setcolor(RED);
    draw();

    scale();  // Apply scaling first
    pivot();  // Apply pivot point transformation
    rotate(); // Apply rotation
    
    setcolor(YELLOW);
    draw();
    
    getch();
    closegraph();
    return 0;
}

void draw() {
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
        delay(500);
    }
}

void pivot() {
    printf("Enter the pivot point coordinates (px py)\n(0, 0) for origin: ");
    scanf("%d%d", &fixedx, &fixedy);
    putpixel(fixedx, fixedy, WHITE);
}

void scale() {
    for (i = 0; i < n; i++) {
        x[i] = fixedx + (int)((float)(x[i] - fixedx) * sx);
        y[i] = fixedy + (int)((float)(y[i] - fixedy) * sy);
    }
}

void rotate() {
    float rotationMatrix[3][3] = {
        {cos(theta), -sin(theta), 0},
        {sin(theta), cos(theta), 0},
        {0, 0, 1}
    };
    
    int tmpX, tmpY;
    
    for (i = 0; i < n; i++) {
        tmpX = x[i] - fixedx;
        tmpY = y[i] - fixedy;

        x[i] = fixedx + round(tmpX * rotationMatrix[0][0] + tmpY * rotationMatrix[0][1]);
        y[i] = fixedy + round(tmpX * rotationMatrix[1][0] + tmpY * rotationMatrix[1][1]);
    }
}
