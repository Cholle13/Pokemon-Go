#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include "SDL_Plotter.h"
#include <fstream>
#include <vector>


using namespace std;
const int POKEDEX_COUNT = 15;
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
    //All these CLASSY MEMBERS... HAHAHA
    Point oldLoc;
    //Color picture[256][256];
    //I remember when we used ^ because vectors weren't our friends
    vector< vector<Color> > picture;
    //Pixel color R,G,B
    int speed;
    int height;
    int width;
    int x;
    int y;
    bool alive;
    bool collected;
    
public:
    // Look at all those fancy methods
    Pokemon(string);
    Pokemon(int);
    Pokemon();
    Point loc;
    void draw(SDL_Plotter&);
    int getxLoc();
    int getHeight();
    bool getAlive();
    void setAlive(bool);
    bool getCollected();
    void setCollected(bool);
    void draw(SDL_Plotter&, string);
    void erase(SDL_Plotter&);
    void move(DIR);
    Point getOldLoc();
    void pokMove(SDL_Plotter& g);
    void setSpeed(int a);
    void setLoc(int, int);
    bool poke_Captured(Pokemon, SDL_Plotter&);
    
};

string getName(int a);
string getCharMove(int a);
void random_Move(Pokemon[], SDL_Plotter&);
void init_PokeDex(Pokemon[]);
int boy_StandStill(int);
void alive_draw(Pokemon[], SDL_Plotter&);
bool capture_Tester(Pokemon[], Pokemon, SDL_Plotter&);
bool all_Captured(Pokemon[]);
void collect_Inventory(Pokemon[], SDL_Plotter&);
void inventory_Dissapear(Pokemon[], SDL_Plotter&);

//Don't think I had to use this but hey here it is
Point Pokemon::getOldLoc(){
    return oldLoc;
}
//This is for setting the speed of the ball and anything really
void Pokemon::setSpeed(int a){
    speed = a;
}

// This function is for if you need to put something in a specific spot other than the
// Random placement that the constructor gives
void Pokemon::setLoc(int x, int y){
    loc.x = x;
    loc.y = y;
}
int Pokemon::getxLoc(){
    return loc.x;
}

//This is used to return if the Pokemon is alive or not
bool Pokemon::getAlive(){
    return alive;
}
//This is to set if pokemon got hit or not
void Pokemon::setAlive(bool test){
    alive = test;
}

//Gets height of pokemon
int Pokemon::getHeight(){
    return height;
}


//Gets if the pokemon has been taken into inventory
bool Pokemon::getCollected(){
    return collected;
}
//Sets if the Pokemon has been taken into inventory
void Pokemon::setCollected(bool test){
    collected = test;
}

//This is to make all the pokemon move randomly (automates it for us)
void random_Move(Pokemon pokedex[], SDL_Plotter& g){
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(!pokedex[i].getCollected())
            pokedex[i].pokMove(g);
    }
}

// Initializing the Pokedex/poke_Collection
void init_PokeDex(Pokemon pokedex[]){
    for(int i = 0; i < POKEDEX_COUNT; i++){
        Pokemon init(getName(i));
        pokedex[i] = init;
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
//this is used in correlation with poke_Captured to return if hit with the pokeball
bool capture_Tester(Pokemon pokedex[], Pokemon pokeball, SDL_Plotter& g){
    bool test = false;
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(pokedex[i].poke_Captured(pokeball, g))
            test = true;
    }
    return test;
}

//This is how the pokemon know to erase themselves and pokeball erases (WHEN POKEBALL AND POKEMON BECOME FRIENDS)
// This is also where we control the inventory not disapearing
bool Pokemon::poke_Captured(Pokemon pokeball, SDL_Plotter& g){
    bool test;
    if(pokeball.loc.x >= loc.x && pokeball.loc.x <= loc.x + width
       && pokeball.loc.y >= loc.y && pokeball.loc.y <= loc.y + height && !collected){
        erase(g);
        test = true;
        pokeball.erase(g);
        setAlive(false);
        setCollected(true);
    }else
        test = false;
    return test;
}

// STUFF USED FOR INVENTORY

bool all_Captured(Pokemon pokedex[]){
    bool test = true;
    for(int i = 0; i < POKEDEX_COUNT; i++){
        if(pokedex[i].getAlive()){
            test = false;
        }
    }
    return test;
}

//for this the spacer is what is giving me problems.. need to come up with a good formula
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


//Empty constructor for pokemon array
Pokemon::Pokemon(){
}
//Constructor for the Background(we can have multiple backgrounds)
Pokemon::Pokemon(int a){
    picture.resize(1000, vector<Color>(1000));
    //add background text files to the array
    string bkgrds[5] = {"BabyBack.txt"};
    string name = bkgrds[a];
    ifstream file(name.c_str());
    loc.x = 0;
    loc.y = 0;
    oldLoc = loc;
    file >> height >> width;
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            file >> picture[r][c].R;
            file >> picture[r][c].G;
            file >> picture[r][c].B;
        }
    }
    //Can't forget to close our files!
    file.close();
}

//Constructor for PokemAns
Pokemon::Pokemon(string filename){
    picture.resize(256, vector<Color>(256));
    string name = filename;
    ifstream file(name.c_str());
    loc.x = (rand()%900) + 2;
    loc.y = (rand()%700) + 100;
    oldLoc = loc;
    alive = true;
    collected = false;
    speed = 10;
    file >> height >> width;
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            file >> picture[r][c].R;
            file >> picture[r][c].G;
            file >> picture[r][c].B;
        }
    }
    //Can't forget to close our files!
    file.close();
}

//Basic Draw Function
void Pokemon::draw(SDL_Plotter& g){
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            if(picture[r][c].R != 255 || picture[r][c].G != 255 || picture[r][c].B != 255){
                g.plotPixel(loc.x + c,loc.y + r,picture[r][c].R, picture[r][c].G, picture[r][c].B);
            }
        }
    }
}

//Sneaky way to change the Sprite to one of your choosing(CLEVER AMIRITE?)
void Pokemon::draw(SDL_Plotter& g, string boy){
    Pokemon sneak(boy);
    sneak.loc = loc;
    sneak.draw(g);
    //picture.clear();
}

//Erases the sprite in its old location(HANDY DANDY)
void Pokemon::erase(SDL_Plotter& g){
    for(int r =0; r < height; r++){
        for(int c = 0; c < width; c++){
            if(picture[r][c].R != 255 || picture[r][c].G != 255 || picture[r][c].B != 255)
                g.plotPixel(oldLoc.x + c, oldLoc.y + r, 255, 255, 255);
        }
    }
}

//This makes are lives easier(PHEWWW)
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
//This is so that the PokemAns move randomly(COOLIO)
void Pokemon::pokMove(SDL_Plotter& g){
    int mov = rand()%4;
    int freq = rand()%200;
    if(freq == 100 && !collected){
        //Looks like we are Switchin things up... HAHAHAHA puns
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
    //hey look they erase themselves when the move :)
    erase(g);
    
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

// DRAWS PICTURES
/*void drawText(string filename, SDL_Plotter& g)
 {
 vector< vector<Color> > picture;
 //Pixel color R,G,B
 int speed;
 int rows;
 int col;
 int x;
 int y;
 Point oldLoc;
 Point loc;
 picture.resize(500, vector<Color>(500));
 string name = filename;
 ifstream file(name.c_str());
 loc.x = (300);
 loc.y = (600);
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
 //Can't forget to close our files!
 file.close();
 for(int r = 0; r < rows; r++){
 for(int c = 0; c < col; c++){
 if(picture[r][c].R != 255 || picture[r][c].G != 255 || picture[r][c].B != 255){
 g.plotPixel(loc.x + c,loc.y + r,picture[r][c].R, picture[r][c].G, picture[r][c].B);
 }
 }
 }
 }*/

#endif // POKEMON_H_INCLUDED
