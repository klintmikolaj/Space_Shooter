#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Asteroid {
public:
    Asteroid(RenderWindow &);

    void loadTexture();
    void showSprite();
    void update();

    int get_enemy_HP() const;
private:
    int hp;
    int hpMAX;
    int size;
    int damage; /* jaki zadaje spritowi gracza */
    float speed;
    Texture asteroid1_Texture;
    Texture asteroid2_Texture;
    Sprite asteroid1_Sprite;
    Sprite asteroid2_Sprite;
};