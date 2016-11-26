#include <iostream>
#include "Pokemon.h"
#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(1000, 1000);
    int x, y;
 //   int R,G,B;
    Pokemon boy;
    x = g.getCol()/2;
    y = g.getRow()/2;
    while (!g.getQuit())
    {
        boy.draw(g);
        g.update();
        if(g.kbhit()){
            if(g.getKey() == UP_ARROW){
                boy.move(UP);
            }
            if(g.getKey() == DOWN_ARROW){
                boy.move(DOWN);
            }
            if(g.getKey() == RIGHT_ARROW){
                boy.move(RIGHT);
            }
            if(g.getKey() == LEFT_ARROW){
                boy.move(LEFT);
            }
            boy.erase(g);
            boy.draw(g);
            g.update();
        }
        
    }
}
