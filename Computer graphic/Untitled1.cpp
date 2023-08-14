// Lab 1: Introduction to graphic of dda algorithm
//sample program
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main(){
	int i;
	int gd = DETECT,gm;
	initgraph(&gd,&gm," ");
	for (i=1;i<=100;i++){
		putpixel(i,i,5);
		
	}
	getch();
	closegraph();
}