/*
Author: Mahfujar Rahman Noyon
Rangpur Engineering College,Ranpur
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
main(){
int gd = DETECT,gm;

int x,y,x1,y1,x2,y2,dx,dy,xEnd,i;

printf("Enter the value of starting point(x1,y1): ");
scanf("%d%d",&x1,&y1);

printf("Enter the value of starting point(x2,y2): ");
scanf("%d%d",&x2,&y2);

dx = abs(x2-x1);
dy = abs(y2-y1);

int towDy = 2*dy;
int towDyDx = 2*(dy-dx);

int  p = 2*dy-dx;

if(x1>x2){
    x = x2;
    y = y2;
    xEnd = x1;
}
else{
    x = x1;
    y = y1;
    xEnd = x2;
}
initgraph(&gd,&gm,NULL);
putpixel(x,y,5);

while(x<xEnd){
    x++;
    if(p<0){
        p = p+towDy;
    }
    else{
        y++;
        p = p+towDyDx;
    }
    putpixel(x,y,5);
}
scanf("%d",&i);
}
