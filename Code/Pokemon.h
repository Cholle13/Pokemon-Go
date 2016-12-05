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
    
    /*
 * description: Constructs pokemon    
 * return: none                                        
 * precondition: string is valid                           
 * postcondition: creates pokemon                    
 *                                                        
*/
    Pokemon(string);
    
    /*
 * description: creates the background of the game
 * return: none                                           
 * precondition: integer is valid                           
 * postcondition: creates background               
 *                                                        
*/
    Pokemon(int);
    /*
 * description: constructs the player  
 * return: none                                           
 * precondition: string, int, int, int are valid                            
 * postcondition: creates the player                    
 *                                                        
*/
    Pokemon(string, int, int, int);
    /*
 * description: default constructor    
 * return: none                                         
 * precondition: pokemon is being contructed                            
 * postcondition: contructs a default pokemon               
 *                                                        
*/
    Pokemon();
   
    Point loc;
    
    /*
 * description: calculate total price of item with tax     
 * return: double                                           
 * precondition: price and tax are valid                             
 * postcondition: returns sum of price and tax                    
 *                                                        
*/
    void draw(SDL_Plotter&);
    /*
 * description: gets the x location of a pokemon    
 * return: int                                        
 * precondition: x location is set                            
 * postcondition: returns x location                   
 *                                                        
*/
    int getxLoc();
    /*
 * description: gets the y location of a pokemon   
 * return: int                                        
 * precondition: y locations is set                             
 * postcondition: returns y location                   
 *                                                        
*/
    int getyLoc();
    /*
 * description: gets pokemon height    
 * return: int                                        
 * precondition: height is set                             
 * postcondition: returns height                   
 *                                                        
*/
    int getHeight();
    /*
 * description: gets a pokemons alive status    
 * return: bool                                         
 * precondition: alive value is set                            
 * postcondition: returns alive or not alive               
 *                                                        
*/
    bool getAlive();
    /*
 * description: sets the alive value     
 * return: void                                          
 * precondition: bool is valid                              
 * postcondition: changes alive variable                    
 *                                                        
*/
    void setAlive(bool);
    /*
 * description: sees if pokemon has been collected    
 * return: bool                                          
 * precondition: pokemon has been made                            
 * postcondition: returns collected status                    
 *                                                        
*/
    bool getCollected();
    /*
 * description: sets if pokemon has been collected   
 * return: void                                       
 * precondition: bool is valid                             
 * postcondition: changes collected status                  
 *                                                        
*/
    void setCollected(bool);
    /*
 * description: draws the player
 * return: void                                           
 * precondition: sdl plotter, string, int, int, int are valid                          
 * postcondition: draws the player                   
 *                                                        
*/
    void draw(SDL_Plotter&, string, int, int, int);
    /*
 * description: erases the player     
 * return: void                                           
 * precondition: sdl plotter is valid                            
 * postcondition: erases player                   
 *                                                        
*/
    void erase(SDL_Plotter&);
    /*
 * description: moves the player in given direction     
 * return: void                                          
 * precondition: DIR is valid                            
 * postcondition: changes player location                  
 *                                                        
*/
    void move(DIR);
    /*
 * description: calculate total price of item with tax     
 * return: double                                           
 * precondition: price and tax are valid                             
 * postcondition: returns sum of price and tax                    
 *                                                        
*/
    Point getOldLoc();
    /*
 * description: moves pokemon     
 * return: void                                           
 * precondition: sdl plotter is valid        
 * postcondition: pokemon is moved
 *                                                        
*/
    void pokMove(SDL_Plotter& g);
    /*
 * description: sets the player speed     
 * return: void                                          
 * precondition: int is valid                           
 * postcondition: changes the speed                    
 *                                                        
*/
    void setSpeed(int a);
    /*
 * description: sets player location   
 * return: void                                           
 * precondition: int, int are valid                             
 * postcondition: location is changed                   
 *                                                        
*/
    void setLoc(int, int);
    /*
 * description: Checks to see if the pokemon is captured     
 * return: bool                                          
 * precondition: pokemon and SDL plotter are valid                            
 * postcondition: returns the captured status                
 *                                                        
*/
    bool poke_Captured(Pokemon, SDL_Plotter&);
    /*
 * description: changes the team of the player  
 * return: void                                          
 * precondition: pokemon, int, int, int are valid                             
 * postcondition: returns sum of price and tax                    
 *                                                        
*/
    void change_Team(Pokemon, int, int, int);
    
};


Point Pokemon::getOldLoc(){
    return oldLoc;
}

void Pokemon::setSpeed(int a){
    speed = a;
}


void Pokemon::setLoc(int x, int y){
    loc.x = x;
    loc.y = y;
}
int Pokemon::getxLoc(){
    return loc.x;
}

int Pokemon::getyLoc(){
    return loc.y;
}


bool Pokemon::getAlive(){
    return alive;
}

void Pokemon::setAlive(bool test){
    alive = test;
}


int Pokemon::getHeight(){
    return height;
}



bool Pokemon::getCollected(){
    return collected;
}
/
void Pokemon::setCollected(bool test){
    collected = test;
}


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


Pokemon::Pokemon(){
}

Pokemon::Pokemon(int a){
    picture.resize(1000, vector<Color>(1000));
    //add background text files to the array
    string bkgrds[5] = {"BabyBack.txt", "Victory", "InventoryBar"};
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
    
    file.close();
}


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
    
    file.close();
}


Pokemon::Pokemon(string filename, int red, int green, int blue){
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
            
            if(picture[r][c].R == 53 && picture[r][c].G == 103 && picture[r][c].B == 251){
                picture[r][c].R = red;
                picture[r][c].G = green;
                picture[r][c].B = blue;
            }
        }
    }
    
    file.close();
}

void Pokemon::change_Team(Pokemon boy, int red, int green, int blue){
    for(int r = 0; r < boy.height; r++){
        for(int c = 0; c < boy.width; c++){
            if(boy.picture[r][c].R == 53 && boy.picture[r][c].G == 103 && boy.picture[r][c].B == 251){
                boy.picture[r][c].R = red;
                boy.picture[r][c].G = green;
                boy.picture[r][c].B = blue;
            }
        }
    }
}


void Pokemon::draw(SDL_Plotter& g){
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            if(picture[r][c].R != 255 || picture[r][c].G != 255 || picture[r][c].B != 255){
                g.plotPixel(loc.x + c,loc.y + r,picture[r][c].R, picture[r][c].G, picture[r][c].B);
            }
        }
    }
}


void Pokemon::draw(SDL_Plotter& g, string boy, int red, int green, int blue){
    Pokemon sneak(boy, red, green, blue);
    sneak.loc = loc;
    sneak.draw(g);
    
}


void Pokemon::erase(SDL_Plotter& g){
    for(int r =0; r < height; r++){
        for(int c = 0; c < width; c++){
            if(picture[r][c].R != 255 || picture[r][c].G != 255 || picture[r][c].B != 255)
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
    int freq = rand()%200;
    if(freq == 100 && !collected){
       
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
#endif // POKEMON_H_INCLUDED
