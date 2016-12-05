/*
* Author: Benjamin Agueros, Chris Holle, Parakh Jaggi, 
    Josh Moisand, Luke Barron
* Assignment Title:  Group Project
* Assignment Description: This program creates a game 
    using the SDL plotter.
* Due Date: 12/04/2016
* Date Created: 11/20/2016
* Date Last Modified: 12/04/2016
 */

//
//  Game_Init.h
//  PokemonGO
//
//  Created by Chris Holle on 12/4/16.
//  Copyright © 2016 Chris Holle. All rights reserved.
//

#ifndef Game_Init_h
#define Game_Init_h
#include "Pokemon.h"
#include "SDL_Plotter.h"
#include "Menu.h"
#include "Inventory.h"
#include "SpriteAlt.h"

/*
 * description: Plays the game     
 * return: void                                          
 * precondition: the game has been created                             
 * postcondition: runs the game                   
 *                                                        
*/
void game_Init();

void game_Init(){
    SDL_Plotter g(1000, 1000);
    
    Menu background("Menubkrd");
    Menu text("textbox2");
    
    //sets up the Pokemon objects
    Pokemon BackGround(0);
    
    bool select = false;
    bool onMenu = true;
    bool play = false;
    
    //and these(string)
    Pokemon boy(getCharMove(0));
    boy.setLoc(500, 700);
    Pokemon pokeball("Pokeball");
    Pokemon victory(1);
    Pokemon inventoryBar(2);
    Pokemon inventoryBag("InventoryBag");
    inventoryBar.setLoc(940, 165);
    inventoryBag.setLoc(935, 750);
    Pokemon pokedex[15];
    init_PokeDex(pokedex);
    
    
    //SOUND
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_Music *music = NULL;
    music = Mix_LoadMUS( "101-opening.mp3" );
    Mix_Music *music_after_menu = NULL;
    music_after_menu = Mix_LoadMUS( "background5.mp3" );
    Mix_Chunk *sound = NULL;
    sound = Mix_LoadWAV( "Laser_Shoot22.wav" );
    
    
   
    int spriteNum = 0, timer = 0, moveCount = 0, poke_Left = 15, inventory_Toggle = 0;
    int red, green, blue;
    bool up, down, left, right;
    // play music
    Mix_PlayMusic( music, -1 );
    
    
    while (!g.getQuit()){
        
        while(!select && !g.getQuit()){
            background.draw(g);
            if(g.kbhit()){
                if(g.getKey() == 'T'){
                    background.change("TeamSelect");
                    bool back = false;
                    while(!back){
                        background.draw(g);
                        if(g.kbhit()){
                            if(g.getKey() == 'V'){
                                red = 248;
                                green = 0;
                                blue = 0;
                                Pokemon boy(getCharMove(0), red, green, blue);
                                boy.setLoc(500, 700);
                                background.change("Menubkrd");
                                back = true;
                            }else
                                if(g.getKey() == 'M'){
                                    red = 53;
                                    green = 103;
                                    blue = 251;
                                    Pokemon boy(getCharMove(0), red, green, blue);
                                    boy.setLoc(500, 700);
                                    background.change("Menubkrd");
                                    back = true;
                                }else
                                    if(g.getKey() == 'N'){
                                        red = 253;
                                        green = 206;
                                        blue = 0;
                                        Pokemon boy(getCharMove(0), red, green, blue);
                                        boy.setLoc(500, 700);
                                        background.change("Menubkrd");
                                        back = true;
                                    }
                                    else
                                        if(g.getKey() == 'B'){
                                            background.change("Menubkrd");
                                            back = true;
                                        }
                                        else{
                                            background.change("TeamSelect");
                                        }
                            
                        }
                        
                        g.update();
                    }
                }
                else if(g.getKey() == 'S'){
                    select = true;
                    onMenu = false;
                    //SOUND
                    Mix_PlayMusic( music_after_menu, -1 );
                }
            }
            g.update();
        }
        
        
        
        
        if(!onMenu){
            
            BackGround.draw(g);
            
            if(inventory_Toggle != 1)
                inventoryBag.draw(g);
            else
                inventoryBar.draw(g);
            
            alive_draw(pokedex, g);
            
            if(poke_Left == 0)
                victory.draw(g);
            
            
            if(timer == 0){
                up = down = right = left = false;
               
            }
            else if(up || down || right || left){
                pokeball.draw(g);
            }
            
            
            pokeball.setSpeed(10);
            boy.draw(g, getCharMove(spriteNum), red, green, blue);
            g.update();
            
            
            
            while(!play){
                text.drawNoWhite(g);
                g.update();
                g.Sleep(9000);
                text.change("textbox3");
                text.drawNoWhite(g);
                g.update();
                g.Sleep(5000);
                play = true;
            }
            
            
            if(play){
                
                
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
                    
                    
                    if(g.getKey() == ' ' && !down && !up && !right && !left){
                        Mix_PlayChannel(-1, sound, 0);
                        switch(spriteNum){
                                
                                
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
                    
                    F
                    if(g.getKey() == 'I'){
                        inventory_Toggle = 1;
                    }if(g.getKey() == 'X'){
                        inventory_Toggle = 0;
                    }
                }
                
                
                if(down && moveCount != 20){
                    pokeball.move(DOWN);
                    moveCount++;
                    if(capture_Tester(pokedex, pokeball, g)){
                        moveCount = 20;
                        poke_Left--;
                    }
                    if(pokeball.getyLoc() > 989)
                        moveCount = 20;
                }
                if(up && moveCount != 20){
                    pokeball.move(UP);
                    moveCount++;
                    if(capture_Tester(pokedex, pokeball, g)){
                        moveCount = 20;
                        poke_Left--;
                    }
                    if(pokeball.getyLoc() < 11)
                        moveCount = 20;
                }
                if(right && moveCount != 20){
                    pokeball.move(RIGHT);
                    moveCount++;
                    if(capture_Tester(pokedex, pokeball, g)){
                        moveCount = 20;
                        poke_Left--;
                    }
                    if(pokeball.getxLoc() > 989)
                        moveCount = 20;
                }
                if(left && moveCount != 20){
                    pokeball.move(LEFT);
                    moveCount++;
                    if(capture_Tester(pokedex, pokeball, g)){
                        moveCount = 20;
                        poke_Left--;
                    }
                    if(pokeball.getxLoc() < 11)
                        moveCount = 20;
                }
                
                if(moveCount == 20){
                    moveCount = 0;
                    up = right = left = down = false;
                }
                
                timer++;
                if(!g.kbhit() && timer >= 30){
                    spriteNum = boy_StandStill(spriteNum);
                    timer = 1;
                }
                
                
                
                random_Move(pokedex, g);
                
                
                if(inventory_Toggle == 1){
                    collect_Inventory(pokedex, g);
                    inventoryBag.erase(g);
                }
                if(inventory_Toggle == 0){
                    inventory_Dissapear(pokedex, g);
                    inventoryBar.erase(g);
                    
                }
                
                
            }
        }
    }

    
    
}


#endif /* Game_Init_h */
