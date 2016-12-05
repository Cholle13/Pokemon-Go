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

#ifndef SpriteAlt_h
#define SpriteAlt_h
#include "Pokemon.h"

/*
 * description: moves the pokemon
 * return: void                                          
 * precondition:array of pokemon and SDL plotter are valid                             
 * postcondition: modifies the location of the pokemon in the 
    given SDL plotter                                                     
*/
void random_Move(Pokemon[], SDL_Plotter&);

/*
 * description: Changes the cahracter sprite to idle    
 * return: int                                          
 * precondition: integer is valid                             
 * postcondition: retunrs the sprite index                 
 *                                                        
*/
int boy_StandStill(int);

/*
 * description: draws pokemon that are still alive  
 * return: void                                           
 * precondition: array of pokemon and SDL plotter are valid                            
 * postcondition: continues drawing live pokemon in SDL plotter passed by reference                   
 *                                                        
*/
void alive_draw(Pokemon[], SDL_Plotter&);

//This is to make all the pokemon move randomly (automates it for us)
void random_Move(Pokemon pokedex[], SDL_Plotter& g){
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(!pokedex[i].getCollected())
            pokedex[i].pokMove(g);
    }
}

//returns boy to stationary sprite
int boy_StandStill(int num){
    
    if(num == 1 || num == 2)
        num = 0;
    if(num == 4 || num == 5)
        num = 3;
    if(num == 7 || num == 8)
        num = 6;
    if(num == 10 || num == 11)
        num = 9;
    return num;
}

//used to draw each frame if the pokemon are still "alive"
void alive_draw(Pokemon pokedex[], SDL_Plotter& g){
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(pokedex[i].getAlive())
            pokedex[i].draw(g);
    }
}


#endif /* SpriteAlt_h */
