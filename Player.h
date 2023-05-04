using namespace std;
using namespace sf;

class Player
{
    public:
        explicit Player(string &, RenderWindow &);
        Player(string &, RenderWindow &, int);

        void move(bool direction);
        void loadTexture();
        void showSprite();

        int getHP() const;
        string getName() const;

    private:
        RenderWindow & window;
        const string name;
        int hp;
        Texture playerTexture;
        Sprite playerSprite;
};
