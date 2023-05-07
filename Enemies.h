#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Enemies {
public:
    Enemies(RenderWindow &);

    void loadTexture();
    void showSprite();

    int get_enemy_HP() const;
private:
    int hp;
    int hpMAX;
    Texture asteroid_Texture;
    Sprite asteroid_Sprite;
};

