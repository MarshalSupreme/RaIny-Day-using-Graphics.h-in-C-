// C program to implement
// the above approach
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight * 0.75
int ldisp = 0;
  
// Creating a hut
void hut()
{
    setcolor(WHITE);
    rectangle(150, 180, 250, 300);
    rectangle(250, 180, 420, 300);
    rectangle(180, 250, 220, 300);
  
    line(200, 100, 150, 180);
    line(200, 100, 250, 180);
    line(200, 100, 370, 100);
    line(370, 100, 420, 180);
  
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(152, 182, WHITE);
    floodfill(252, 182, WHITE);
    setfillstyle(SLASH_FILL, BLUE);
    floodfill(182, 252, WHITE);
    setfillstyle(HATCH_FILL, RED);
    floodfill(200, 105, WHITE);
    floodfill(210, 105, WHITE);
}

// Drawing a Man with
// an umbrella
void DrawManAndUmbrella(int x,
			int ldisp)
{
	x=x+50;
    circle(x, GroundY - 90, 10);
    line(x, GroundY - 80, x,
	 GroundY - 30);
    line(x, GroundY - 70,
	 x + 10, GroundY - 60);
    line(x, GroundY - 65, x + 10,
	 GroundY - 55);
    line(x + 10, GroundY - 60,
	 x + 20, GroundY - 70);
    line(x + 10, GroundY - 55,
	 x + 20, GroundY - 70);

    line(x, GroundY - 30,
	 x + ldisp, GroundY);
    line(x, GroundY - 30,
	 x - ldisp, GroundY);
	setfillstyle(SOLID_FILL,
		     LIGHTMAGENTA);
	floodfill(ScreenWidth - 100,
		  50, WHITE);
    pieslice(x + 20, GroundY - 120,
	     0, 180, 40);
	setfillstyle(SOLID_FILL,
		     YELLOW);
	floodfill(ScreenWidth - 100,
		  50, WHITE);
    line(x + 20, GroundY - 120,
	 x + 20, GroundY - 70);
}

// Driver code
void main()
{
    int gd = DETECT, gm, x = 0;

    initgraph(&gd, &gm,
	      "C:\\TurboC3\\BGI");
	hut();
	circle(ScreenWidth - 100,
	       50, 30);
	line(0, GroundY, ScreenWidth,
	     GroundY);
	x = (x + 2) % ScreenWidth;
    ldisp = (ldisp + 2) % 20;
    DrawManAndUmbrella(x, ldisp);
    getch();
}