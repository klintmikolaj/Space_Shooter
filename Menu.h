#include <SFML/Graphics.hpp>
#include <iostream>
#define MENU_ITEMS 5
using namespace std;
using namespace sf;

class Menu {
public:
    Menu(float x, float y, RenderWindow &, Font &);
    void draw();
    int menu_update();
    void Move_Up();
    void Move_Down();
    void Load_background();
    void Draw_background();
    void musicLoad();
private:
    RenderWindow &window;
    int Selected_index;
    Audio audio;
    Font & font;
    Text menu[MENU_ITEMS];
    Texture backgroundTexture;
    Sprite background;
};

