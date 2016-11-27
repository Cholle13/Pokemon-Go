#include <iostream>
#include "Pokemon.h"
#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(1000, 1000);
    int x, y;
    int mov, freq;
 //   int R,G,B;
    Pokemon boy("boypic.txt");
    Pokemon pokemon1("pokemon1");
    x = g.getCol()/2;
    y = g.getRow()/2;
    g.initSound("background1");
    g.playSound("background1");
    while (!g.getQuit())
    {
        pokemon1.draw(g);
        boy.draw(g);
        g.update();
        if(g.kbhit()){
            if(g.getKey() == UP_ARROW &&  boy.loc.y > 1){
                boy.move(UP);
            }
            if(g.getKey() == DOWN_ARROW && boy.loc.y < 925){
                boy.move(DOWN);
            }
            if(g.getKey() == RIGHT_ARROW && boy.loc.x < 950){
                boy.move(RIGHT);
            }
            if(g.getKey() == LEFT_ARROW && boy.loc.x > 25){
                boy.move(LEFT);
            }
            boy.erase(g);
        }

        mov = rand()%4; //random number for direction
        freq = rand()%500; //random number to space out movement of pokemon
        if(freq == 250){
            switch(mov){
                case 0: if(pokemon1.loc.y > 1)pokemon1.move(UP);
                    break;
                case 1: if(pokemon1.loc.y < 925)pokemon1.move(DOWN);
                    break;
                case 2: if(pokemon1.loc.x > 25)pokemon1.move(LEFT);
                    break;
                case 3: if(pokemon1.loc.x < 950)pokemon1.move(RIGHT);
            }
            pokemon1.erase(g);
        }
    }
}

