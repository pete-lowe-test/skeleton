#include "Ship.h"
#include <iostream>



Ship::Ship()
{
}


Ship::~Ship()
{
}


/// <summary>
/// action for ship each frame
/// </summary>
/// <param name="t_deltaTime">time increment</param>
void Ship::update(sf::Time t_deltaTime)
{
	move();
}

/// <summary>
/// draw the ship
/// </summary>
/// <param name="t_window">sfml render window</param>
void Ship::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_shipSprite);
}

/// <summary>
/// run once at the start of game
/// </summary>
void Ship::setup()
{
	if (!m_shipTexture.loadFromFile("ASSETS\\IMAGES\\smallplayerstrip164.png"))
	{
		std::cout << "problem loading ship texture" << std::endl;
	}
	m_shipSprite.setTexture(m_shipTexture);
	m_shipSprite.setTextureRect(sf::IntRect{ 0,0,64,64 });	
	initialise();
}

/// <summary>
/// run at the start of each level
/// </summary>
void Ship::initialise()
{
	m_location = { 100.0,100.0 };
	m_velocity = { 1.0,1.0 };
}

/// <summary>
/// determine if shipo is still in play
/// </summary>
/// <returns>status of ship</returns>
bool Ship::alive()
{
	return m_alive;
}

/// <summary>
/// movement for ship should probally call a screenwrap method from here
/// adjust sprite position to match logic of ships location
/// </summary>
void Ship::move()
{
	m_location += m_velocity;
	m_shipSprite.setPosition(static_cast<sf::Vector2f>(m_location - MyVector2D{ 32.0,32.0 }));
}

/// <summary>
/// find out where ship is used for collisions and such
/// </summary>
/// <returns>current centre of ship</returns>
MyVector2D Ship::getLocation()
{
	return m_location;
}
