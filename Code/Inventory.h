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
//  Inventory.h
//  PokemonGO
//
//  Created by Chris Holle on 12/4/16.
//  Copyright © 2016 Chris Holle. All rights reserved.
//

#ifndef Inventory_h
#define Inventory_h
#include "Pokemon.h"

/*
 * description: created the inventory     
 * return: void                                          
 * precondition: Pokemon array and SDL plotter are valid                             
 * postcondition: inventory created                   
 *                                                        
*/
void collect_Inventory(Pokemon[], SDL_Plotter&);
/*
 * description: puts away inventory when the player asks     
 * return: void                                          
 * precondition: pokemon array and sdl plotter are valid                            
 * postcondition: inventory closed                  
 *                                                        
*/
void inventory_Dissapear(Pokemon[], SDL_Plotter&);
/*
 * description: initialized the pokedex     
 * return: void                                           
 * precondition: pokemon array is valid                             
 * postcondition: creates the pokedex                    
 *                                                        
*/
void init_PokeDex(Pokemon[]);
/*
 * description: gets the name of the pokemon   
 * return:string                                           
 * precondition: a is valid                            
 * postcondition: returns the name of the pokemon                    
 *                                                        
*/
string getName(int a);
/*
 * description: gets the character facing position     
 * return: string                                        
 * precondition: a is valid                            
 * postcondition: gets the postion the pokemon is facing                   
 *                                                        
*/
string getCharMove(int a);
/*
 * description: captures the pokemon   
 * return: bool                                           
 * precondition: pokemon array, pokemon, and sdl plotter are valid                            
 * postcondition: pokemon is captured                    
 *                                                        
*/
bool capture_Tester(Pokemon[], Pokemon, SDL_Plotter&);




void collect_Inventory(Pokemon pokedex[], SDL_Plotter& g){
    int spacer = 700;
    inventory_Dissapear(pokedex, g);
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(!pokedex[i].getAlive()){
            spacer -= pokedex[i].getHeight() + 10;
            pokedex[i].setLoc(950, spacer);
            pokedex[i].setAlive(true);
        }
    }
}

void inventory_Dissapear(Pokemon pokedex[], SDL_Plotter& g){
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(pokedex[i].getxLoc() == 950){
            pokedex[i].erase(g);
            pokedex[i].setAlive(false);
        }
    }
}



void init_PokeDex(Pokemon pokedex[]){
    for(int i = 0; i < POKEDEX_COUNT; i++){
        Pokemon init(getName(i));
        pokedex[i] = init;
    }
}


string getName(int a){
    string pokemon[POKEDEX_COUNT] = {"Pikachu", "Squirtle", "Marill", "pokemon1", "Snorlax", "Eevee", "Magikarp", "Omanyte", "Weedle", "Bulbasaur", "Gloom", "Hypno", "Charmander", "Abra", "Jigglypuff"};
    
    return pokemon[a];
}


string getCharMove(int a){
    string character[12] = {"Boy", "DownBoy1", "DownBoy2", "UpBoy", "UpBoy1", "UpBoy2", "RBoy", "RBoy1", "RBoy2",
        "LBoy", "LBoy1", "LBoy2"};
    
    return character[a];
}


bool capture_Tester(Pokemon pokedex[], Pokemon pokeball, SDL_Plotter& g){
    bool test = false;
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(pokedex[i].poke_Captured(pokeball, g))
            test = true;
    }
    return test;
}

#endif /* Inventory_h */
