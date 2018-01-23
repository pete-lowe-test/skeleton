#pragma once
#include <SFML\Graphics.hpp>
#include "MyVector2D.h"

class Ship
{
public:
	Ship();
	~Ship();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setup();
	void initialise();
	bool alive();
	void move();
	MyVector2D getLocation();
	
private:
	sf::Texture m_shipTexture; // texture for ship only one instance
	sf::Sprite	m_shipSprite; // sprite for ship
	bool m_alive; // used to check if ship is still in play
	MyVector2D m_location;  // location of centr of ship
	MyVector2D m_velocity; // current velocity
	MyVector2D m_acceleration; // force to added to velocity
};

