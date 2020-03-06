#include<stdio.h>
#include<graphics.h>
void drawCircle(int cx,int cy,int x,int y){
    putpixel(cx+x,cy+y,1);
    putpixel(cx-x,cy+y,1);
    putpixel(cx+x,cy-y,1);
    putpixel(cx-x,cy-y,1);
    putpixel(cx+y,cy+x,1);
    putpixel(cx-y,cy+x,1);
    putpixel(cx+y,cy-x,1);
    putpixel(cx-y,cy-x,1);
}
main(){
    int gd = DETECT,gm,cx,cy,r,p;
    printf("Enter the center(x): ");
    scanf("%d",&cx);
    printf("Enter the center(y): ");
    scanf("%d",&cy);

    printf("Enter the radius(r): ");
    scanf("%d",&r);
    p=1-r;
    int x = 0;
    int y = r;

    initgraph(&gd,&gm,"");
    drawCircle(cx,cy,x,y);
    while(x<y){
        x++;
        if(p<0){
            p +=2*x + 1;
        }
        else{
            y--;
            p+=2*(x-y)+1;
        }
        drawCircle(cx,cy,x,y);
    }
    getch();
    closegraph();
    return 0;
}
