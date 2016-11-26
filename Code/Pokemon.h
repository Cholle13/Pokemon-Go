#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include "SDL_Plotter.h"
#include <fstream>
#include <string>


using namespace std;

enum DIR {UP,DOWN,LEFT,RIGHT}; //directions
enum RGB {R, G, B}; //color values


struct Point{
    int x, y; 
    Point(int x = 0, int y =0);
};


Point::Point(int a, int b){
    x = a;
    y = b;

}

struct Color{
    int R, G, B;
    Color(){
        R = G = B = 255; 
    }
};

class Pokemon{
    private:
        Point loc; 
        Point oldLoc;
        Color picture[256][256];  //Pixel color R,G,B
        int speed;
        int rows;
        int col;

    public:
        Pokemon();
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void move(DIR);

};

Pokemon::Pokemon(){
    ifstream file;
    string fileName;
    int pmon = rand() % 15; //random number modulus the number of pokemon we will have
    
    switch(pmon){
        case 0: fileName = "Pokemon1.txt";
            break;
        case 1: fileName = "Pokemon2.txt";
            break;
        case 2: fileName = "Pokemon3.txt";
            break;
         //continue if more pokemon
            
    }
    
    file.open(c_str(fileName));
    
    loc.x = 250; 
    loc.y = 300;
    oldLoc = loc;
    speed = 10;
    file >> rows >> col;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < col; c++){
            file >> picture[r][c].R;
            file >> picture[r][c].G;
            file >> picture[r][c].B;
        }
    }
    file.close(); // don't know if this is needed
}

void Pokemon::draw(SDL_Plotter& g){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < col; c++){
            g.plotPixel(loc.x + c,loc.y + r,picture[r][c].R, picture[r][c].G, picture[r][c].B);
        }
    }
}

void Pokemon::erase(SDL_Plotter& g){

    for(int r =0; r < rows; r++){
        for(int c = 0; c < col; c++){
            g.plotPixel(oldLoc.x + c, loc.y + r, 255, 255, 255);
        }
    }


}


void Pokemon::move(){ //in main we can create a loop that makes the pokemon move and sleep
    oldLoc = loc;
    int d = rand() % 4; // picks a random direction
    
    
    switch(d){
        case 1: loc.y -= speed;
            break;
        case 2: loc.y += speed;
            break;
        case 3: loc.x -= speed;
            break;
        case 4: loc.x += speed;
            break;
    }

}


#endif // POKEMON_H_INCLUDED
