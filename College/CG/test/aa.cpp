#include<iostream>
#include<graphics.h>
int main()
{
int gdriver = DETECT , gmode;
initgraph(&gdriver,&gmode,NULL);
line(100,125,250,250);
circle(50,50,50);
setcolor(RED);
rectangle(80,80,300,300);

delay(5000);
closegraph();
}
    
