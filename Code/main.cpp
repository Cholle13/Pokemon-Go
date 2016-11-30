#include <iostream>
#include "Pokemon.h"
#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{
    bool select = false;
    bool onMenu = true;
    SDL_Plotter menu(1000, 1000);
    Menu background("MenuBkrd");
    background.draw(menu);
    menu.update();
    while(!select){
        if(menu.kbhit()){
            if(menu.getKey() == 'S'){
                select = true;
                onMenu = false;
            }

        }

    }


    if(!onMenu){

        SDL_Plotter g(1000, 1000);
        int x, y;
        int mov, freq;
     //   int R,G,B;
        Pokemon pokemon5(getName());
        Pokemon pokemon4(getName());
        Pokemon pokemon3(getName());
        Pokemon pokemon2(getName());
        Pokemon pokemon1(getName());
        Pokemon boy("boypic.txt");

        x = g.getCol()/2;
        y = g.getRow()/2;
        g.initSound("background1");
        g.playSound("background1");
        while (!g.getQuit())
        {
            pokemon5.draw(g);
            pokemon4.draw(g);
            pokemon3.draw(g);
            pokemon2.draw(g);
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

            //random number for direction
             //random number to space out movement of pokemon
                pokemon5.pokMove(g);
                pokemon4.pokMove(g);
                pokemon3.pokMove(g);
                pokemon2.pokMove(g);
                pokemon1.pokMove(g);


            }

   }
}
