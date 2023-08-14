#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void draw(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int c) {
    setcolor(c);
    line((int)x1, (int)y1, (int)x2, (int)y2);
    line((int)x2, (int)y2, (int)x3, (int)y3);
    line((int)x3, (int)y3, (int)x4, (int)y4);
    line((int)x4, (int)y4, (int)x1, (int)y1);
}

int main() {
    int gd = DETECT, gm;
    float x, y, x1, y1, x2, y2, x3, y3, shear_x = 0, shear_y = 0;

    initgraph(&gd, &gm, " ");
//     x=100;
//    y=100;
//    x1=300;
//    y1=100;
//    x2=300;
//    y2=300;
//    x3=100;
//    y3=300;
    printf("Enter the four coordinates (x y):\n");
    scanf("%f %f %f %f %f %f %f %f", &x, &y, &x1, &y1, &x2, &y2, &x3, &y3);

    printf("Choose a shearing option:\n1. Horizontal Shearing\n2. Vertical Shearing\n3. Combined Shearing\n");
    int so;
    scanf("%d", &so);

    if (so == 1 || so == 3) printf("Enter the shearing factor for x: "), scanf("%f", &shear_x);
    if (so == 2 || so == 3) printf("Enter the shearing factor for y: "), scanf("%f", &shear_y);

    cleardevice();

    // Draw the original rectangle
    draw(x, y, x1, y1, x2, y2, x3, y3, WHITE);

    // Calculate the midpoint of the original rectangle
    float mid_x = (x + x1 + x2 + x3) / 4.0;
    float mid_y = (y + y1 + y2 + y3) / 4.0;

    // Apply shearing transformation
    float sheared_x1 = x1 + shear_x * y1;
    float sheared_x2 = x2 + shear_x * y2;
    float sheared_x3 = x3 + shear_x * y3;
    float sheared_x = x + shear_x * y;

    float sheared_y1 = y1 + shear_y * x1;
    float sheared_y2 = y2 + shear_y * x2;
    float sheared_y3 = y3 + shear_y * x3;
    float sheared_y = y + shear_y * x;

    // Calculate the adjusted coordinates for the sheared rectangle
    float adjust_x = mid_x - (sheared_x + sheared_x1 + sheared_x2 + sheared_x3) / 4.0;
    float adjust_y = mid_y - (sheared_y + sheared_y1 + sheared_y2 + sheared_y3) / 4.0;

    // Update the sheared coordinates with adjustments
    sheared_x += adjust_x;
    sheared_y += adjust_y;
    sheared_x1 += adjust_x;
    sheared_y1 += adjust_y;
    sheared_x2 += adjust_x;
    sheared_y2 += adjust_y;
    sheared_x3 += adjust_x;
    sheared_y3 += adjust_y;

    // Draw the sheared rectangle
    draw(sheared_x, sheared_y, sheared_x1, sheared_y1, sheared_x2, sheared_y2, sheared_x3, sheared_y3, RED);

    getch();
    closegraph();
    return 0;
}
