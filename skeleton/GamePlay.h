#pragma once
#include <SFML\Graphics.hpp>
#include "Ship.h"
#include "Asteroid.h"
#include "Globals.h"

/// <summary>
/// this handles the game logic but should
/// deligate responsibility to the elements (ship,asteroids,bullets etc.)
/// as much as possible
/// 
/// </summary>
class GamePlay
{
public:
	GamePlay();
	~GamePlay();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
	void initialise();
private:
	Ship m_ship;	// players ship
	sf::Font m_font; // font used by HUD maybe??
	Asteroid m_asteroids[MAX_ASTEROIDS]; // all the asteroids used and re-used in the game
	
	void collisions();
	void destroyAsteroid(Asteroid &t_asteroid);
	bool checkHit(MyVector2D t_centreOne, MyVector2D t_centreTwo);
};

