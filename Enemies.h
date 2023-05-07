#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Enemies {
public:
    Enemies(RenderWindow &);

    void loadTexture();
    void showSprite();
    void update();

    int get_enemy_HP() const;
private:
    int type; /* Zalozmy ze 1 - zwykla asteroida, 2 - statek niestrzelajacy, 3 - statek strzelajacy */
    int hp;
    int hpMAX;
    float speed;
    Texture asteroid_Texture;
    Sprite asteroid_Sprite;
};

