#include<iostream>
#include<graphics.h>
#include<math.h>
void ddaline(int x1, int y1, int x2, int y2, int c)
{
int dx = x2 - x1;
int dy = y2 - y1;
int steps;
if(abs(dx) > abs(dy))
steps = abs(dx);
else
steps = abs(dy);
float x_inc = dx / (float)steps;
float y_inc = dy / (float)steps;
int x = x1, y = y1;
putpixel(x, y, c);
for (int i = 0; i < steps; ++i)
{
x += x_inc;
y += y_inc;
putpixel(round(x),round(y), c);
}
}
int main()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);
ddaline(100, 100, 500, 100, RED);
ddaline(100, 100, 100, 500, RED);
ddaline(500, 100, 500, 500, RED);
ddaline(100, 500, 500, 500, RED);

ddaline(300, 100, 100, 300, RED);
ddaline(100, 300, 300, 500, RED);
ddaline(300, 500, 500, 300, RED);
ddaline(500, 300, 300, 100, RED);
getch();
}




