#include "SDL_Plotter.h"
#include "Pokemon.h"
#include <cmath>

#ifndef Pokeball_h
#define Pokeball_h

// Split up into cpp and header files
bool hit(Pokemon, Pokemon[]);

int distance(Point, Point);

int closest_Pokemon(Pokemon ball, Pokemon poke_Collection[]);

//finds distance between two points
int distance(Point a, Point b){
    int dist, x1, x2, y1, y2;
    x1 = a.x;
    x2 = b.x;
    y1 = a.y;
    y2 = b.y;
    
    dist = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    
    return dist;
}

//Test if pokemon is hit... this needs to be refined to each pokemone sadly
bool hit(Pokemon ball, Pokemon sprite){
    bool test;
    if((ball.loc.x >= sprite.loc.x && ball.loc.x <= sprite.loc.x + 20)
       && (ball.loc.y >= sprite.loc.y && ball.loc.y <= sprite.loc.y + 20)){
        test = true;
    }else
        test = false;
    return test;
}

//finds closest pokemon and returns the index of that pokemon
int closest_Pokemon(Pokemon ball, Pokemon poke_Collection[]){
    int dist;
    int indexPoke;
    dist = distance(ball.loc, poke_Collection[0].loc);
    indexPoke = 0;
    
    for(int i = 1; i < 5; i++){
        if(dist > distance(ball.loc, poke_Collection[i].loc)){
            indexPoke = i;
        }
    }
    
    return indexPoke;
}
#endif /* Pokeball_h */
