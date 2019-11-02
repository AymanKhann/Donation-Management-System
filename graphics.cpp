#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main ()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:/TC/bgi");
setfillstyle(SOLID_FILL,WHITE);
fillellipse(160,47,45,45);
setfillstyle(EMPTY_FILL,GREEN);
fillellipse(210,47,45,45);
setfillstyle(SOLID_FILL,RED);
fillellipse(260,47,45,45);
setfillstyle(EMPTY_FILL,YELLOW);
fillellipse(310,47,45,45);
setfillstyle(SOLID_FILL,YELLOW);
fillellipse(360,47,45,45);
setfillstyle(SOLID_FILL,BLUE);
bar(120,100,400,400);
outtextxy(140,196,"************");
outtextxy(140,220,"WELCOME ");
outtextxy(140,240,"************");
outtextxy(140,260,"DONATIONS MANAGEMENT SYSTEM ");
setfillstyle(SOLID_FILL,WHITE);
bar(120,550,400,400);
line(50,0,50,480);
line(55,0,55,480);
line(500,0,500,480);
line(505,0,505,480);
getch();
return 0;
closegraph;
}
