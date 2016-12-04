#include <iostream>
#include "Pokemon.h"
#include "SDL_Plotter.h"
#include "Menu.h"
#include "Pokeball.h"

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(1000, 1000);
    int x, y;
    //int R,G,B;
    
    Menu background("Menubkrd");
    //Menu text("textbox2");
    
    //sets up the Pokemon objects
    Pokemon BackGround(0);
    
    bool select = false;
    bool onMenu = true;
    bool play = false;
    
    //and these(string)
    Pokemon boy(getCharMove(0));
    boy.setLoc(500, 700);
    
    Pokemon pokeball("Pokeball");
    //Pokemon victory("Victory");
    //victory.setLoc(111, 111);
    Pokemon pokedex[15];
    init_PokeDex(pokedex);
    
    x = g.getCol()/2;
    y = g.getRow()/2;
    
    //uncomment these when sound works?
    // g.initSound("background1");
    // g.playSound("background1");
    
    //declare some fun variables
    int spriteNum = 0, timer = 0, moveCount = 0, poke_Left = 15, inventory_Toggle = 0;
    bool up, down, left, right;
    
    
    //keeps running until ESC key is pressed
    while (!g.getQuit()){
        //loads menu and keeps open until the escape keyh is pressed or s is pressed
        while(!select && !g.getQuit()){
            background.draw(g);
            if(g.kbhit()){
                if(g.getKey() == 'S'){
                    select = true;
                    onMenu = false;
                }
            }
            g.update();
        }
        
        
        //EDIT   HAD TO  DO THIS BECAUSE THE DIALOGUE BOX NO WORKIN
        play = true;
        
        //plays game after done with menu
        if(!onMenu){
            
            //if(poke_Left == 0){
            //    victory.draw(g);
            //}
            
            //draw sprites
            BackGround.draw(g);
            
            //This test if pokemon are alive and if so keep drawing them
            alive_draw(pokedex, g);
            
            //this is to initialize the booleans
            if(timer == 0){
                up = down = right = left = false;
                //this is to only draw the pokeball when one of the booleans is true
            }
            else if(up || down || right || left){
                pokeball.draw(g);
            }
            
            //Change this to change the pokeball's speed
            pokeball.setSpeed(10);
            boy.draw(g, getCharMove(spriteNum));
            g.update();
            //pokeball.erase(g);
            
            //displays the text box and keeps it up until time expires
            /*  while(!play){
             text.drawNoWhite(g);
             g.update();
             g.Sleep(10000);
             text.change("textbox3");
             text.drawNoWhite(g);
             g.update();
             g.Sleep(5000);
             play = true;
             }*/
            
            //When done with textbox it allows for movement
            if(play){
                
                //Determines which boy sprite to use based on direction
                if(g.kbhit()){
                    //Up arrow stuff
                    if(g.getKey() == UP_ARROW &&  boy.loc.y > 1){
                        boy.move(UP);
                        if(spriteNum == 4)
                            spriteNum = 5;
                        else
                            spriteNum = 4;
                    }
                    //Down arrow stuff
                    if(g.getKey() == DOWN_ARROW && boy.loc.y < 925){
                        boy.move(DOWN);
                        if(spriteNum == 1)
                            spriteNum = 2;
                        else
                            spriteNum = 1;
                    }
                    //Right arrow stuff
                    if(g.getKey() == RIGHT_ARROW && boy.loc.x < 950){
                        boy.move(RIGHT);
                        if(spriteNum == 7)
                            spriteNum = 8;
                        else
                            spriteNum = 7;
                    }
                    //Left arrow stuff
                    if(g.getKey() == LEFT_ARROW && boy.loc.x > 25){
                        boy.move(LEFT);
                        if(spriteNum == 10)
                            spriteNum = 11;
                        else
                            spriteNum = 10;
                    }
                    
                    //Finds which way the pokeball needs to move (make function that return loc of ball)
                    //Test if spacebar is pressed. If so, set start location of pokeball
                    if(g.getKey() == ' ' && !down && !up && !right && !left){
                        switch(spriteNum){
                                //With no break if it is 0 it runs until it hits case 2(CLEVER AMIRITE?)
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
                    
                    //THIS TOGGLES INVENTORY ON/OFF
                    if(g.getKey() == 'I'){
                            inventory_Toggle = 1;
                    }if(g.getKey() == 'X'){
                        inventory_Toggle = 0;
                    }
                }
                
                //POKEBALL STUFF
                //These keep the ball moving - change the moveCount to increase distance shoot
                //If hits pokemon before moving the distance, stop movement
                if(down && moveCount != 20){
                    pokeball.move(DOWN);
                    moveCount++;
                    if(capture_Tester(pokedex, pokeball, g)){
                        moveCount = 20;
                        poke_Left--;
                    }
                }
                if(up && moveCount != 20){
                    pokeball.move(UP);
                    moveCount++;
                    if(capture_Tester(pokedex, pokeball, g)){
                        moveCount = 20;
                        poke_Left--;
                    }
                }
                if(right && moveCount != 20){
                    pokeball.move(RIGHT);
                    moveCount++;
                    if(capture_Tester(pokedex, pokeball, g)){
                        moveCount = 20;
                        poke_Left--;
                    }
                }
                if(left && moveCount != 20){
                    pokeball.move(LEFT);
                    moveCount++;
                    if(capture_Tester(pokedex, pokeball, g)){
                        moveCount = 20;
                        poke_Left--;
                    }
                }
                //This is for when it reaches its destination
                if(moveCount == 20){
                    moveCount = 0;
                    up = right = left = down = false;
                }
                //Changes character back to still after a certain time
                timer++;
                if(!g.kbhit() && timer >= 30){
                    spriteNum = boy_StandStill(spriteNum);
                    timer = 1;
                }
                
                //Random number for direction
                //Random number to space out movement of pokemon
                random_Move(pokedex, g);
                
                //INVENTORY TOGGLE ON/OFF
                if(inventory_Toggle == 1){
                    collect_Inventory(pokedex, g);
                }
                if(inventory_Toggle == 0){
                    inventory_Dissapear(pokedex, g);
                }
                
                
            }
        }
    }
    
    return 0;
}
//} Magical totem bracket - DO NOT TOUCH
