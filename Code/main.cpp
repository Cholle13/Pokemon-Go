#include <iostream>
#include "Pokemon.h"
#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{
    //MENU STUFF(BEN'S AREA OF EXPERTISE STAY OUT)
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
    
    //SOMEONE PLEASE EXPLAIN THIS CONFUSING IF STATEMENT - CHRIS
    if(!onMenu){
        
        SDL_Plotter g(1000, 1000);
        int x, y;
        //   int R,G,B;
        
        //sets up the Pokemon objects
        //there are two constructors...
        //this one(int)
        Pokemon BackGround(0);
        //and these(string)
        Pokemon pokemon5(getName(4));
        Pokemon pokemon4(getName(3));
        Pokemon pokemon3(getName(2));
        Pokemon pokemon2(getName(1));
        Pokemon pokemon1(getName(0));
        Pokemon boy(getCharMove(0));
        Pokemon pokeball("Pokeball");
        
        x = g.getCol()/2;
        y = g.getRow()/2;
        //uncomment these when sound works?
        //    g.initSound("background1");
        //    g.playSound("background1");
        
        //declare some fun variables
        int num = 0, timer = 0, moveCount = 0;
        bool up, down, left, right;
        
        //keeps running until ESC key is pressed
        while (!g.getQuit())
        {
            BackGround.draw(g);
            pokemon5.draw(g);
            pokemon4.draw(g);
            pokemon3.draw(g);
            pokemon2.draw(g);
            pokemon1.draw(g);
            //this is to initialize the booleans
            if(timer == 0){
                up = down = right = left = false;
                //this is to only draw the pokeball when one of the booleans is true
            }else if(up || down || right || left)
                pokeball.draw(g);
            //Change this to change the pokeballs speed
            pokeball.setSpeed(10);
            boy.draw(g, getCharMove(num));
            g.update();
            pokeball.erase(g);
            
            //this if statement is pretty self-explanatory
            if(g.kbhit()){
                //up arrow stuff
                if(g.getKey() == UP_ARROW &&  boy.loc.y > 1){
                    boy.move(UP);
                    if(num == 4)
                        num = 5;
                    else
                        num = 4;
                    //num = 3;
                }
                //down arrow stuff
                if(g.getKey() == DOWN_ARROW && boy.loc.y < 925){
                    boy.move(DOWN);
                    if(num == 1)
                        num = 2;
                    else
                        num = 1;
                    //num = 0;
                }
                //right arrow stuff
                if(g.getKey() == RIGHT_ARROW && boy.loc.x < 950){
                    boy.move(RIGHT);
                    if(num == 7)
                        num = 8;
                    else
                        num = 7;
                   // num = 6;
                }
                //left arrow stuff
                if(g.getKey() == LEFT_ARROW && boy.loc.x > 25){
                    boy.move(LEFT);
                    if(num == 10)
                        num = 11;
                    else
                        num = 10;
                }
                //test if Spacebar is pressed if so set start location of pokeball
                if(g.getKey() == ' ' && !down && !up && !right && !left){
                    switch(num){
                        //with no break if it is 0 it runs until it hits case 2(CLEVER AMIRITE?)
                        case 0:
                        case 1:
                        case 2:
                            down = true;
                            pokeball.setLoc(boy.loc.x, boy.loc.y + 15);
                            break;
                        case 3:
                        case 4:
                        case 5:
                            up = true;
                            pokeball.setLoc(boy.loc.x+10, boy.loc.y + 15);
                            break;
                        case 6:
                        case 7:
                        case 8:
                            right = true;
                            pokeball.setLoc(boy.loc.x + 30, boy.loc.y + 15);
                            break;
                        case 9:
                        case 10:
                        case 11:
                            left = true;
                            pokeball.setLoc(boy.loc.x, boy.loc.y + 15);
                            break;
                    }
                    
                }
                boy.erase(g);
            }
            //these keep the ball moving - change the moveCount to increase distance shoot
            if(down && moveCount != 20){
                pokeball.move(DOWN);
                moveCount++;
            }
            if(up && moveCount != 20){
                pokeball.move(UP);
                moveCount++;
            }
            if(right && moveCount != 20){
                pokeball.move(RIGHT);
                moveCount++;
            }
            if(left && moveCount != 20){
                pokeball.move(LEFT);
                moveCount++;
            }
            if(moveCount == 20){
                moveCount = 0;
                up = right = left = down = false;
                pokeball.erase(g);
            }
            //this timer thing is to make the dude assume the stationary position after not moving
            //    for a certain amount of time...
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
                timer = 1;
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
