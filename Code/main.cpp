#include <iostream>

#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{

	SDL_Plotter g(500, 500);
    int x, y, xd, yd;
    int R,G,B;
    x = g.getCol()/2;
    y = g.getRow()/2;
    R = 0;
    G = 0;
    B = 0;
    while (!g.getQuit())
    {
    	g.plotPixel(x,y, 0, 0, 0);
    	g.plotPixel(x+1,y, 0, 0, 0);
    	g.plotPixel(x-1,y, 0, 0, 0);
    	g.plotPixel(x,y+1, 0, 0, 0);
    	g.plotPixel(x,y-1, 0, 0, 0);
    	g.update();
    	if(g.kbhit()){
    	    if(g.getKey() == UP_ARROW){
    	    	y--;
    	    }
    	    if(g.getKey() == DOWN_ARROW){
				y++;
			}
    	    if(g.getKey() == RIGHT_ARROW){
				x++;
			}
    	    if(g.getKey() == LEFT_ARROW){
				x--;
			}
			g.clear();
    	}

    }
}
