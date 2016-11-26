#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include "SDL_Plotter.h"
#include <fstream>


using namespace std;

enum DIR {UP,DOWN,LEFT,RIGHT};
enum RGB {R, G, B};
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
    int x;
    int y;
    
public:
    Pokemon();
    void draw(SDL_Plotter&);
    void erase(SDL_Plotter&);
    void move(DIR);
    
};

Pokemon::Pokemon(){
    ifstream file ("boypic.txt");
    loc.x = 200;
    loc.y = 200;
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


void Pokemon::move(DIR d){
    oldLoc = loc;
    switch(d){
        case UP: loc.y -= speed;
            break;
        case DOWN: loc.y += speed;
            break;
        case LEFT: loc.x -= speed;
            break;
        case RIGHT: loc.x += speed;
            break;
    }
    
}


#endif // POKEMON_H_INCLUDED
