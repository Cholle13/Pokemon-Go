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

void collect_Inventory(Pokemon[], SDL_Plotter&);
void inventory_Dissapear(Pokemon[], SDL_Plotter&);
void init_PokeDex(Pokemon[]);
string getName(int a);
string getCharMove(int a);
bool capture_Tester(Pokemon[], Pokemon, SDL_Plotter&);

// STUFF USED FOR INVENTORY

//This is used with the inventory toggles and spacing it
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
//this erases the inventory but doesn't change the pokemon inside
void inventory_Dissapear(Pokemon pokedex[], SDL_Plotter& g){
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(pokedex[i].getxLoc() == 950){
            pokedex[i].erase(g);
            pokedex[i].setAlive(false);
        }
    }
}


// Initializing the Pokedex/poke_Collection
void init_PokeDex(Pokemon pokedex[]){
    for(int i = 0; i < POKEDEX_COUNT; i++){
        Pokemon init(getName(i));
        pokedex[i] = init;
    }
}

//File names of pokemon stored here
string getName(int a){
    string pokemon[POKEDEX_COUNT] = {"Pikachu", "Squirtle", "Marill", "pokemon1", "Snorlax", "Eevee", "Magikarp", "Omanyte", "Weedle", "Bulbasaur", "Gloom", "Hypno", "Charmander", "Abra", "Jigglypuff"};
    
    return pokemon[a];
}

//File names of character movements here
string getCharMove(int a){
    string character[12] = {"Boy", "DownBoy1", "DownBoy2", "UpBoy", "UpBoy1", "UpBoy2", "RBoy", "RBoy1", "RBoy2",
        "LBoy", "LBoy1", "LBoy2"};
    
    return character[a];
}

//this is used in correlation with poke_Captured to return if hit with the pokeball
bool capture_Tester(Pokemon pokedex[], Pokemon pokeball, SDL_Plotter& g){
    bool test = false;
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(pokedex[i].poke_Captured(pokeball, g))
            test = true;
    }
    return test;
}

#endif /* Inventory_h */
