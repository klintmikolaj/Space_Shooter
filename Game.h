#ifndef SPACE_SHOOTER_GAME_H
#define SPACE_SHOOTER_GAME_H

#include "Player.h"
#include "Audio.h"
#include "Shoot.h"
#include "Asteroid.h"
#include "Alien.h"
#include "ShootingAlien.h"
#include <vector>



class Game {
private:
    sf::RenderWindow& window;
    sf::Font& font;
    Player player;
    sf::Event event;
    sf::Text playerStats;
    Audio audio;
    std::vector<Shoot*> bulletsBank;
    std::vector<Shoot*> alienBulletsBank;
    std::vector<Asteroid*> asteroids;
    std::vector<Alien*> aliens;
    std::vector<ShootingAlien*> shootingAliens;
    Unit* lastEnemy;
    Shoot* lastBullet;
    sf::Sprite background;
    sf::Texture playerTexture;
    sf::Texture backgroundTexture;
    sf::Texture bulletTexture;
    sf::Texture alienBulletTexture;
    sf::Texture asteroidTexture1;
    sf::Texture asteroidTexture2;
    sf::Texture alienTexture1;
    sf::Texture shootingAlienTexture;
    sf::Color backColour;
    sf::RectangleShape statsBackground;
    float asteroidSpawnNow;
    float asteroidSpawnCooldown;
    float alienSpawnNow;
    float shootingAlienSpawnNow;
    float shootingNow;
    float alienSpawnCooldown;
    int multiplier;
    int frameCount;
    short & difficulty;
    bool isLeft;
    bool isX;
    bool isUp;
    bool isY;

public:
    Game(std::string& nameArg, sf::RenderWindow& windowArg, sf::Font& fontArg, short& difficultyArg);
    
    /*
     * loads all textures
     * clears the old window and creates a new one
     * loads all default stats and sets players position in the center of the window
     * updates the game if the window is open
    */
    void run();
    
    /*
    * clears the window and loads the background
    * contains all enemies functions
    *displays the window
    */
    bool update();
    
    
//     void display();
    
    /*
    * allows the ship to move and accelerate
    * cooperates with specific keys from the keyboard
    */
    bool steer();
    
    /*
    * displays the interface on the screen
    */
    void drawInterface();
    
    /*
    * displays players sprite
    */
    void drawPlayerStuff();
    
    /*
    * loads all textures from specific files
    */
    void loadTextures();
    
    /*
    * displays players name in the interface
    */
    void loadPlayerStats();
    
    /*
    * All four functions checks collision of player with specific object
    * if the collision occurs functions play an audio file and decreases players HP 
    */
    void playerCollision(std::vector<Asteroid*> & unitBank);
    void playerCollision(std::vector<Alien*> & unitBank);
    void playerCollision(std::vector<ShootingAlien*> & unitBank);
    void playerCollision(std::vector<Shoot*> & bulletBank);
    
    /*
    * contains all types of collisions (asteroid, alien, shooting alien and boolet)
    * returnes false value if the player lost all his HP  points
    */
    bool playerManager();
    
    /*
    * adds new object to players bullet vector
    */
    void bulletMaker(Player& playerArg);
    
    /*
    * adds new object to aliens bullet vector
    */
    void alienBulletMaker(ShootingAlien*& enemyArg);
    
    /*
    * erases the bullet from specific vector
    */
    void bulletDestroyer(Shoot*& a, unsigned int& ii);
    
    /*
    * updates bullet trajectory
    */
    void masterOfBullets();
    
    /*
    * spawns the asteroids and updates them
    * destroys asteroids which fell off from the window
    * increases players points if the bullet trajectory met asteroids one
    */
    void asteroidAhead();
    
    /*
    * both functions spawns specific types of aliens
    * they update aliens and erases them if they fell of from the window
    * they increase players points if the bullet trajectory met aliens one
    */
    void alienAttack();
    void shootingAlienAttack();
    
    /*
    * both functions set specific values for aliens and asteroids which will be used in 
    */
    void asteroidsSetSpawners();
    void aliensSetSpawners();
    
    /*
    * updates players stats
    */
    void statsUpdate();
    
    /*
    * displays "game over" background if players HP is equal to 0
    * it holds it on the screen for 3 seconds
    */
    void gameOver();
};


#endif //SPACE_SHOOTER_GAME_H
