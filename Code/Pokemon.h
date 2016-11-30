#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include "SDL_Plotter.h"
#include <fstream>
#include <vector>


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

    Point oldLoc;
    //Color picture[256][256];
    vector< vector<Color> > picture;
     //Pixel color R,G,B
    int speed;
    int rows;
    int col;
    int x;
    int y;

public:

    Pokemon(string);
    Point loc;
    void draw(SDL_Plotter&);
    void erase(SDL_Plotter&);
    void move(DIR);
    void pokMove(SDL_Plotter& g);

};


Pokemon::Pokemon(string filename){
    picture.resize(256, vector<Color>(256));
    string name = filename;
    ifstream file(name.c_str());
    loc.x = (rand()%900) + 2;
    loc.y = (rand()%900) + 2;
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
            if(picture[r][c].R != 255 || picture[r][c].G != 255 || picture[r][c].B != 255){
                g.plotPixel(loc.x + c,loc.y + r,picture[r][c].R, picture[r][c].G, picture[r][c].B);
            }
        }
    }
    //picture.clear();
}

void Pokemon::erase(SDL_Plotter& g){

    for(int r =0; r < rows; r++){
        for(int c = 0; c < col; c++){
            g.plotPixel(oldLoc.x + c, oldLoc.y + r, 255, 255, 255);
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

void Pokemon::pokMove(SDL_Plotter& g){
    int mov = rand()%4;
    int freq = rand()%500;
    if(freq == 250){
                switch(mov){
                    case 0: if(loc.y > 1)move(UP);
                        break;
                    case 1: if(loc.y < 925)move(DOWN);
                        break;
                    case 2: if(loc.x > 25)move(LEFT);
                        break;
                    case 3: if(loc.x < 950)move(RIGHT);
                }

    }
    erase(g);

}


class Menu{
    private:
        Point loc;
        //Color picture[1080][1920];
        vector< vector<Color> > picture;
        int rows;
        int col;
        int x;
        int y;


    public:
    Menu(string);
    void draw(SDL_Plotter&);
    void erase(SDL_Plotter&);

};

Menu::Menu(string fileName){
    picture.resize(1000, vector<Color>(1000));
    string name = fileName;
    ifstream file(name.c_str());
    loc.x = 0;
    loc.y = 0;
    file >> rows >> col;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < col; c++){
            file >> picture[r][c].R;
            file >> picture[r][c].G;
            file >> picture[r][c].B;
        }
    }


}

void Menu::draw(SDL_Plotter& menu){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < col; c++){
            menu.plotPixel(loc.x + c,loc.y + r,picture[r][c].R, picture[r][c].G, picture[r][c].B);
        }
    }
    //picture.clear();

}

void Menu::erase(SDL_Plotter& menu){
    for(int r =0; r < rows; r++){
        for(int c = 0; c < col; c++){
            menu.plotPixel(loc.x + c, loc.y + r, 255, 255, 255);
        }

    }
}

string getName(){
    string pokemon;
    string name = "marill", name2 = "Omanyte", name3 = "Pikachu", name4 = "Pokemon1", name5= "Squirtle";
    int num = rand() % 4;
    switch(num){
        case 0: pokemon = name;
            break;
        case 1: pokemon = name2;
            break;
        case 2: pokemon = name3;
            break;
        case 3: pokemon = name4;
            break;

    }
    return pokemon;
}

#endif // POKEMON_H_INCLUDED
