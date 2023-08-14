#include<graphics.h>
#include<stdio.h>

int main() {
    int x[3], y[3], i;
    double put_x, put_y, t;
    int gr = DETECT, gm;
    
    initgraph(&gr, &gm, " ");
    printf("\n Please enter x and y coordinates ");
    
    for (i = 0; i < 3; i++) {
        scanf("%d%d", &x[i], &y[i]);
        putpixel(x[i], y[i], 3); // Control Points
    }
    
    for (t = 0.0; t <= 1.0; t += 0.001) {
        double mt = 1 - t;
        put_x = mt * mt * x[0] + 2 * t * mt * x[1] + t * t * x[2];
        put_y = mt * mt * y[0] + 2 * t * mt * y[1] + t * t * y[2];
        putpixel(put_x, put_y, WHITE); // putting pixel
    }
    
    getch();
    closegraph();
    return 0;
}
