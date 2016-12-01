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
        Pokemon BackGround(0);
        Pokemon pokemon5(getName(4));
        Pokemon pokemon4(getName(3));
        Pokemon pokemon3(getName(2));
        Pokemon pokemon2(getName(1));
        Pokemon pokemon1(getName(0));
        string boyz[12] = {"Boy", "DownBoy1", "DownBoy2", "UpBoy", "UpBoy1", "UpBoy2", "RBoy", "RBoy1", "RBoy2", "LBoy", "LBoy1", "Lboy2"};
        Pokemon boy(boyz[0]);
        
        x = g.getCol()/2;
        y = g.getRow()/2;
      //  g.initSound("background1");
     //   g.playSound("background1");
        int num = 0, timer = 0;
        while (!g.getQuit())
        {
            BackGround.draw(g);
            pokemon5.draw(g);
            pokemon4.draw(g);
            pokemon3.draw(g);
            pokemon2.draw(g);
            pokemon1.draw(g);
            boy.draw(g, boyz[num]);
            g.update();
            if(g.kbhit()){
                if(g.getKey() == UP_ARROW &&  boy.loc.y > 1){
                    boy.move(UP);
                    if(num == 4)
                        num = 5;
                    else
                        num = 4;
                    //num = 3;
                }
                if(g.getKey() == DOWN_ARROW && boy.loc.y < 925){
                    boy.move(DOWN);
                    if(num == 1)
                        num = 2;
                    else
                        num = 1;
                    //num = 0;
                }
                if(g.getKey() == RIGHT_ARROW && boy.loc.x < 950){
                    boy.move(RIGHT);
                    if(num == 7)
                        num = 8;
                    else
                        num = 7;
                   // num = 6;
                }
                if(g.getKey() == LEFT_ARROW && boy.loc.x > 25){
                    boy.move(LEFT);
                    if(num == 10)
                        num = 11;
                    else
                        num = 10;
                }
                boy.erase(g);
            }
            timer++;
            if(!g.kbhit() && timer >= 30){
                if(num == 1 || num == 2)
                    num = 0;
                if(num == 4 || num == 5)
                    num = 3;
                if(num == 7 || num == 8)
                    num = 6;
                if(num == 10 || num == 11)
                    num = 9;
                timer = 0;
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
