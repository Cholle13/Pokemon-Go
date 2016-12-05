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
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "SDL_Plotter.h"
#include "Pokemon.h"

using namespace std;

class Menu{
private:
    Point loc;
    vector< vector<Color> > picture;
    int rows;
    int col;
    int x;
    int y;


public:
    /*
 * description: Contructs a menu     
 * return: none                                          
 * precondition: string is valid                           
 * postcondition: menu has been constructed                    
 *                                                        
*/
    Menu(string);
    /*
 * description: Draws the menu   
 * return: void                                          
 * precondition: sdl is valid                             
 * postcondition: menu is drawn                
 *                                                        
*/
    void draw(SDL_Plotter&);
    /*
 * description: erases the menu     
 * return: void                                        
 * precondition: sdl plotter is valid                        
 * postcondition: erases the menu                   
 *                                                        
*/
    void erase(SDL_Plotter&);
    /*
 * description: changes menu vector values   
 * return: void                                         
 * precondition: string is valid                           
 * postcondition: changes vector values of menu                   
 *                                                        
*/
    void change(string);
    /*
 * description: draws menu without the white     
 * return: void                                           
 * precondition: sdl plotter is valid                             
 * postcondition: draws with no white space                  
 *                                                        
*/
    void drawNoWhite(SDL_Plotter&);

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
    

}

void Menu::erase(SDL_Plotter& menu){
    for(int r =0; r < rows; r++){
        for(int c = 0; c < col; c++){
            menu.plotPixel(loc.x + c, loc.y + r, 255, 255, 255);
        }

    }
}

void Menu::change(string fileName){
string name = fileName;
ifstream file(name.c_str());
file >> rows >> col;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < col; c++){
            file >> picture[r][c].R;
            file >> picture[r][c].G;
            file >> picture[r][c].B;
        }
    }
}

void Menu::drawNoWhite(SDL_Plotter& g){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < col; c++){
            if(picture[r][c].R != 255 || picture[r][c].G != 255 || picture[r][c].B != 255){
                g.plotPixel(loc.x + c,loc.y + r,picture[r][c].R, picture[r][c].G, picture[r][c].B);
            }
        }
    }
}

#endif // MENU_H_INCLUDED
