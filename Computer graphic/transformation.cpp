#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to perform translation of triangle
void translate(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y += ty;
}

// Function to perform rotation of triangle
void rotate(int *x, int *y, int angle) {
    float radian = angle * (M_PI / 180.0);
    int x_temp = *x;
    *x = round(x_temp * cos(radian) - *y * sin(radian));
    *y = round(x_temp * sin(radian) + *y * cos(radian));
}

// Function to perform scaling of triangle
void scale(int *x, int *y, float sx, float sy) {
    *x = round(*x * sx);
    *y = round(*y * sy);
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Triangle coordinates
    int x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates of the triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Drawing original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Translation
    int tx, ty;
    printf("Enter translation values (tx ty): ");
    scanf("%d %d", &tx, &ty);
    translate(&x1, &y1, tx, ty);
    translate(&x2, &y2, tx, ty);
    translate(&x3, &y3, tx, ty);

    // Drawing translated triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Rotation
    int angle;
    printf("Enter rotation angle (in degrees): ");
    scanf("%d", &angle);
    rotate(&x1, &y1, angle);
    rotate(&x2, &y2, angle);
    rotate(&x3, &y3, angle);

    // Drawing rotated triangle
    setcolor(GREEN);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Scaling
    float sx, sy;
    printf("Enter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);
    scale(&x1, &y1, sx, sy);
    scale(&x2, &y2, sx, sy);
    scale(&x3, &y3, sx, sy);

    // Drawing scaled triangle
    setcolor(BLUE);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    printf("\nComplete");

    getch();
    closegraph();
    return 0;
}
