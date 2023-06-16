#ifndef SPACE_SHOOTER_GAME_H
#define SPACE_SHOOTER_GAME_H

#include "Player.h"
#include "Audio.h"
#include "Shoot.h"
#include "Asteroid.h"
#include "Alien.h"
#include "ShootingAlien.h"
#include <vector>



class Game
{
    private:
        sf::RenderWindow & window;
        sf::Font & font;
        Player player;
        sf::Event event;
        sf::Text playerStats;
        Audio audio;
        std::vector<Shoot> bulletsBank;
        std::vector<Shoot> alienBulletsBank;
        std::vector<Asteroid> asteroids;
        std::vector<Alien> aliens;
        std::vector<ShootingAlien> shootingAliens;
        Unit * lastEnemy;
        Shoot * lastBullet;
        sf::Sprite background;
        sf::Texture playerTexture;
        sf::Texture backgroundTexture;
        sf::Texture bulletTexture;
        sf::Texture alienBulletTexture;
        sf::Texture asteroidTexture1;
        sf::Texture asteroidTexture2;
        sf::Texture alienTexture1;
        sf::Texture shootingAlienTexture;
        sf::Color backColour={100,100,100,128};
        sf::RectangleShape statsBackground;
        float asteroidSpawnNow;
        float asteroidSpawnCooldown;
        float alienSpawnNow;
        float shootingAlienSpawnNow;
        float shootingNow;
        float alienSpawnCooldown;
        int multiplier;
        short & difficulty;
        bool isLeft;
        bool isX;
        bool isUp;
        bool isY;

    public:
        Game(sf::RenderWindow & windowArg, sf::Font & fontArg, short & difficultyArg);

        /*
        * loads all textures from specific files
        */
        void loadTextures();
        void loadPlayerStats();
        /*
        * function set specific values for aliens and asteroids which will be used in
        */
        void setSpawners();
        /*
         * loads all textures
         * clears the old window and creates a new one
         * loads all default stats and sets players position in the center of the window
         * updates the game if the window is open
        */
        void run();



        /*
        * allows the ship to move and accelerate
        * cooperates with specific keys from the keyboard
        */
        bool steer();



        /*
        * All functions checks collision of player with specific object
        * if the collision occurs functions play an audio file and decreases players HP
        */
        template <typename SS>
        void playerCollision(SS & unitBank);
        void playerCollision(std::vector<Shoot> & bulletBank);



        /*
        * adds new object to players bullet vector
        */
        void createPlayerBullet(Player & playerArg);
        /*
        * adds new object to aliens bullet vector
        */
        void createAlienBullet(ShootingAlien & enemyArg);
        /*
        * erases the bullet from specific vector
        */
        void eraseBullet(Shoot & a, unsigned int & ii);


        /*
        * updates bullet trajectory
        */
        void updateBullets();
        /*
        * contains all types of collisions (asteroid, alien, shooting alien and boolet)
        * returnes false value if the player lost all his HP  points
        */
        bool updatePlayer();
        /*
        * spawns the asteroids and updates them
        * destroys asteroids which fell off from the window
        * increases players points if the bullet trajectory met asteroids one
        */
        void updateAsteroids();
        /*
        * both functions spawns specific types of aliens
        * they update aliens and erases them if they fell of from the window
        * they increase players points if the bullet trajectory met aliens one
        */
        void updateAliens();
        void updateShootingAliens();
        /*
        * updates players stats
        */
        void updateOnScreenStats();
        /*
        * displays the interface on the screen
        */
        void updateInterface();
        /*
        * clears the window and loads the background
        * contains all enemies functions
        *displays the window
        */
        bool update();



        /*
        * displays "game over" background if players HP is equal to 0
        * it holds it on the screen for 3 seconds
        */
        void gameOver();
};


#endif //SPACE_SHOOTER_GAME_H
