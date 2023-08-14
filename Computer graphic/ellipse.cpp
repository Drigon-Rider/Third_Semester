//lab 4: ellips
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void drawellipse(int x,int y,int xc,int yc)
{
	putpixel(xc+x,yc+y,4);
	putpixel(xc+x,yc-y,4);
	putpixel(xc-x,yc+y,4);
	putpixel(xc-x,yc-y,4);
	
}
int main(){
	long xc,yc,rx,ry,x,y,p,pl;
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");
	printf("Center: ");
	scanf("%d %d", &xc,&yc);
	printf("Value of rx:");
	scanf("%d",&rx);
	printf("Value of ry:");
	scanf("%d",&ry);
	x=0;
	y=ry;
	drawellipse(x,y,xc,yc);
	delay(50);
	p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
	while((2*ry*ry*x)<(2*rx*rx*y)){
		if(p<0){
			x=x+1;
			y=y;
			p=p+(2*ry*ry*x)*(ry*ry);
			drawellipse(x,y,xc,yc);
			delay(50);
			
		}
		else{
			x=x+1;
			y=y-1;
			p=p+(2*ry*ry*x)*(ry*ry)-(2*rx*rx*y);
			drawellipse(x,y,xc,yc);
			delay(50);
			
		}
	}
	pl=((ry*ry)*(float)(x+0.5))*((float)(x+0.5))+(((rx*rx)*(y-1)*(y-1))-(rx*rx*y*ry));
	
	while(y>=0){
		if(pl>0){
			x=x;
			y=y-1;
			pl+=(2*ry*ry*x)-(2*rx*rx*y)+(rx*rx);
			drawellipse(x,y,xc,yc);
			delay(50);
			}
			else{
			x=x+1;
			y=y-1;
			pl+=(2*ry*ry*x)-(2*rx*rx*y)+(rx*rx);
			drawellipse(x,y,xc,yc);
			delay(50);
				
			}
	}
	getch();
	closegraph();
	
}

