#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX, centerY, radius;
    float scaleX, scaleY;

    printf("Enter the center of the circle (x y): ");
    scanf("%d %d", &centerX, &centerY);

    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    printf("Enter the scaling factors (scaleX scaleY): ");
    scanf("%f %f", &scaleX, &scaleY);

    setcolor(RED);
    circle(centerX, centerY, radius);

    centerX = round(centerX * scaleX);
    centerY = round(centerY * scaleY);
    radius = round(radius * (scaleX + scaleY) / 2);

    setcolor(YELLOW);
    circle(centerX, centerY, radius);

    getch();
    closegraph();
    return 0;
}
