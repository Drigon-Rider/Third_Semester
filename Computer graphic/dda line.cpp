#include<graphics.h>  
#include<conio.h>  
#include<stdio.h>  
int main()  
{  
    int gd = DETECT ,gm,i;  
    float x, y,dx,dy,steps;  
    int x0, x1, y0, y1;  
    initgraph(&gd, &gm, " ");  
    setbkcolor(WHITE); 
	printf("Enter the two points: "); 
	scanf("%d %d",&x0,&y0);
	printf("Enter the next two points: "); 
	scanf("%d %d",&x1,&y1);
	if (x0 > x1) {
        int tempX = x0, tempY = y0;
        x0 = x1;
        y0 = y1;
        x1 = tempX;
        y1 = tempY;
     
    }
    dx = (float)(x1 - x0);  
    dy = (float)(y1 - y0);  
    if(dx>=dy)  
           {  
        steps = dx;  
    }  
    else  
           {  
        steps = dy;  
    }  
    dx = dx/steps;  
    dy = dy/steps;  
    x = x0;  
    y = y0;  
    i = 1;  
    while(i<= steps)  
    {  
        putpixel(x, y, WHITE);  
        x += dx;  
        y += dy;  
        i=i+1;  
    }  
    getch();  
    closegraph();  
    return 0;
}  