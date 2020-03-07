#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

#define Left 1
#define Right 2
#define Bottom 4
#define Top 8

#define Inside(a) (!a)
#define Reject(a,b) (a&b)
#define Accept(a,b) (!(a|b))

char encode(int x, int y, int xmin, int ymin, int xmax, int ymax)
{
   char code=0;

   if (x<xmin)
   code=code|Left;
   if (x>xmax)
   code=code|Right;
   if (y<ymin)
   code=code|Bottom;
   if (y>ymax)
   code=code|Top;

   return code;
}

void ClipLine(int xmin, int ymin, int xmax, int ymax, int x1, int y1, int x2, int y2)
{
   char code1, code2;
   int done=0,draw=0,t;
   float m;

   while(!done)
   {
      code1=encode(x1,y1, xmin,ymin, xmax,ymax);
      code2=encode(x2,y2, xmin,ymin, xmax,ymax);

      if (Accept(code1,code2))
      {
	 done=1;
	 draw=1;
      }
      else if (Reject(code1,code2))
      done=1;
      else
      {
	 if (Inside(code1))
	 {
	    t=x1;
	    x1=x2;
	    x2=t;

	    t=y1;
	    y1=y2;
	    y2=t;

	    t=code1;
	    code1=code2;
	    code2=t;
	 }

	 if (x1!=x2)
	 m=(float)(y2-y1)/(x2-x1);
	 if (code1 & Left)
	 {
	    y1+=(xmin-x1)*m;
	    x1=xmin;
	 }
	 else if (code1 & Right)
	 {
	    y1+=(xmax-x1)*m;
	    x1=xmax;
	 }
	 else if (code1 & Bottom)
	 {
	    if (x2!=x1)
	    x1+=(ymin-y1)/m;
	    y1=ymin;
	 }
	 else if (code1 & Top)
	 {
	    if (x2!=x1)
	    x1+=(ymax-y1)/m;
	    y1=ymax;
	 }
      }
   }

   if (draw)
   {
      setcolor(0);
    line(320+x1,240-y1,320+x2,240-y2);
       setcolor(4);

   line(320+x1,240-y1,320+x2,240-y2);
   }
}

int main()
{
   int x1,y1,x2,y2,xmax,ymax,xmin,ymin;
   int gd=0,gm;
      initgraph(&gd,&gm,"..\\bgi");
   setcolor(4);
   line(0,240,640,240);
   line(320,0,320,480);

//   clrscr();
   printf("Xmin= ");
   scanf("%d",&xmin);
   printf("Ymin= ");
   scanf("%d",&ymin);
   printf("Xmax= ");
   scanf("%d",&xmax);
   printf("Ymax= ");
   scanf("%d",&ymax);

   setcolor(6);
   rectangle(xmin,ymin,xmax,ymax);
   printf("X1= ");
   scanf("%d",&x1);
   printf("Y1= ");
   scanf("%d",&y1);
   printf("X2= ");
   scanf("%d",&x2);
   printf("Y2= ");
   scanf("%d",&y2);

   line(x1,y1,x2,y2);
   printf("enter T to to transform to window");
   char p;
   scanf("%s",&p);

   setcolor(3);
   rectangle(320+xmin,240-ymin,320+xmax,240-ymax);
   line(320+x1,240-y1,320+x2,240-y2);

   printf("\nEnter C to clip");
   char p1;
   scanf("%s",&p1);

   ClipLine(xmin,ymin,xmax,ymax,x1,y1,x2,y2);
   getch();
   return 0;
}
