#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
int main(){
	int gd = DETECT, gm, i;
	    int radius,c1,c2,p0,xi,yi,x0,y0;

    initgraph(&gd, &gm, " ");
	printf("Enter the center of circle: ");
    scanf("%d %d", &c1, &c2);
    printf("Enter the radus of circle:");
    scanf("%d",&radius);
    x0=0;
    y0=radius;
    p0=1-radius;
    while(x0<=y0){
    	
    if(p0<0){
    	
    	x0++;
    	xi=2*x0;
    	yi=2*y0;
		p0=p0+(xi);	
	}
	else{
		x0++;
		y0--;
		xi=2*x0;
    	yi=2*y0;
		p0=p0+xi+(1-yi);
	}
	putpixel(x0+c1,y0+c2,WHITE);
	putpixel((-x0+c1),y0+c2,WHITE);	
	putpixel(x0+c1,(-y0+c2),WHITE);
	putpixel((-x0+c1),(-y0+c2),WHITE);
	putpixel(y0+c2,x0+c1,WHITE);
	putpixel((-y0+c2),x0+c1,WHITE);
	putpixel(y0+c2,(-x0+c1),WHITE);
	putpixel((-y0+c2),(-x0+c1),WHITE);
  
}
getch();
closegraph();

return 0;
    
    
}