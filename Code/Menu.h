#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "SDL_Plotter.h"
#include "Pokemon.h"

using namespace std;
// MENU STUFF (BEN'S AREA OF EXPERTISE STAY OUT)
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
    void change(string);
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
    //picture.clear();

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
