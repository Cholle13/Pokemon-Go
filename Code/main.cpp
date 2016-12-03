#include <iostream>
#include "Pokemon.h"
#include "SDL_Plotter.h"
#include "Menu.h"
#include "Pokeball.h"

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
    
    
    if(!onMenu){
        
        SDL_Plotter g(1000, 1000);
        int x, y;
        //   int R,G,B;
        
        //sets up the Pokemon objects
        //there are two constructors...
        //this one(int)
        Pokemon BackGround(0);
        //and these(string)
        Pokemon test(getName(0));
        Pokemon boy(getCharMove(0));
        Pokemon pokeball("Pokeball");
        Pokemon poke_Collection[15];
        init_PokeDex(poke_Collection);
        
        x = g.getCol()/2;
        y = g.getRow()/2;
        
        //uncomment these when sound works?
        //  g.initSound("background1");
        //   g.playSound("background1");
        
        //declare some fun variables
        int spriteNum = 0, timer = 0, moveCount = 0;
        bool up, down, left, right;
        
        //keeps running until ESC key is pressed
        while (!g.getQuit())
        {
            //DRAWS TEXT
            // drawText("testText",g);
            //drawText ("drboothTextBox",g);
            
            //draw sprites
            BackGround.draw(g);
            
            //This test if pokemon are alive and if so keep drawing them
            alive_draw(poke_Collection, g);
            
            //this is to initialize the booleans
            if(timer == 0){
                up = down = right = left = false;
                //this is to only draw the pokeball when one of the booleans is true
            }else if(up || down || right || left)
                pokeball.draw(g);
            //Change this to change the pokeballs speed
            pokeball.setSpeed(10);
            boy.draw(g, getCharMove(spriteNum));
            g.update();
            pokeball.erase(g);
            
            //this if statement is pretty self-explanatory
            //Determines which Boy sprite to use
            if(g.kbhit()){
                //up arrow stuff
                if(g.getKey() == UP_ARROW &&  boy.loc.y > 1){
                    boy.move(UP);
                    if(spriteNum == 4)
                        spriteNum = 5;
                    else
                        spriteNum = 4;
                    //num = 3;
                }
                //down arrow stuff
                if(g.getKey() == DOWN_ARROW && boy.loc.y < 925){
                    boy.move(DOWN);
                    if(spriteNum == 1)
                        spriteNum = 2;
                    else
                        spriteNum = 1;
                    //num = 0;
                }
                //right arrow stuff
                if(g.getKey() == RIGHT_ARROW && boy.loc.x < 950){
                    boy.move(RIGHT);
                    if(spriteNum == 7)
                        spriteNum = 8;
                    else
                        spriteNum = 7;
                    // num = 6;
                }
                //left arrow stuff
                if(g.getKey() == LEFT_ARROW && boy.loc.x > 25){
                    boy.move(LEFT);
                    if(spriteNum == 10)
                        spriteNum = 11;
                    else
                        spriteNum = 10;
                }
                
                //Finds which way the pokeball needs to move(Make function that return loc of ball)
                //test if Spacebar is pressed if so set start location of pokeball
                if(g.getKey() == ' ' && !down && !up && !right && !left){
                    switch(spriteNum){
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
            
            //POKEBALL STUFF
            //these keep the ball moving - change the moveCount to increase distance shoot
            //if hits pokemon before moving the distance, stop movement
            if(down && moveCount != 20){
                pokeball.move(DOWN);
                moveCount++;
                if(hit(pokeball, poke_Collection[closest_Pokemon(pokeball, poke_Collection)])){
                    moveCount = 20;
                }
            }
            if(up && moveCount != 20){
                pokeball.move(UP);
                moveCount++;
                if(hit(pokeball, poke_Collection[closest_Pokemon(pokeball, poke_Collection)])){
                    moveCount = 20;
                }
            }
            if(right && moveCount != 20){
                pokeball.move(RIGHT);
                moveCount++;
                if(hit(pokeball, poke_Collection[closest_Pokemon(pokeball, poke_Collection)])){
                    moveCount = 20;
                }
            }
            if(left && moveCount != 20){
                pokeball.move(LEFT);
                moveCount++;
                if(hit(pokeball, poke_Collection[closest_Pokemon(pokeball, poke_Collection)])){
                    moveCount = 20;
                }
            }
            //this is for when it reaches it's destination, erases pokemon and changes them to dead
            if(moveCount == 20){
                moveCount = 0;
                up = right = left = down = false;
                if(hit(pokeball, poke_Collection[closest_Pokemon(pokeball, poke_Collection)])){
                    poke_Collection[closest_Pokemon(pokeball, poke_Collection)].setAlive(false);
                    pokeball.erase(g);
                    poke_Collection[closest_Pokemon(pokeball, poke_Collection)].erase(g);
                }
            }
            //Changes character back to still after a certain time
            timer++;
            if(!g.kbhit() && timer >= 30){
                boy_StandStill(spriteNum);
                timer = 1;
            }
            
            //random number for direction
            //random number to space out movement of pokemon
            random_Move(poke_Collection, g);
        }
        
    }
}
