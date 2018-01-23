#include "GamePlay.h"



GamePlay::GamePlay()
{
}


GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime)
{
	m_ship.update(t_deltaTime);
	for (size_t i = 0; i < 5; i++) // use MAX ASTEROIDS
	{
		if (m_asteroids[i].alive())
		{
			m_asteroids[i].update(t_deltaTime);
		}
	}
	collisions();
}

void GamePlay::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	m_ship.render(t_window);
	for (size_t i = 0; i < 5; i++) // use MAX ASTEROIDS
	{
		if (m_asteroids[i].alive())
		{
			m_asteroids[i].render(t_window);
		}
	}
	t_window.display();
}

void GamePlay::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_ship.setup();
	Asteroid::loadTexture();
	for (size_t i = 0; i < 5; i++) // use MAX ASTEROIDS
	{
		m_asteroids[i].setup();
	}	
	initialise();
}

void GamePlay::initialise()
{
	MyVector2D startLocation{ 0.0, 380.0 };
	MyVector2D velocity{ 1.5,0 };
	m_ship.initialise();
	for (size_t i = 0; i < 5; i++) // use MAX ASTEROIDS
	{
		m_asteroids[i].initialise(startLocation, velocity,3);
		startLocation += {25.0, 50.0};
	}

}


/// <summary>
/// collision system cehcking for collisions bettween all
/// entities in our world. actions that happen after a collsion
/// should be dealt wioht in another method
/// </summary>
void GamePlay::collisions()
{
	for (size_t i = 0; i < 5; i++) // use MAX ASTEROIDS
	{
		if (checkHit(m_ship.getLocation(), m_asteroids[i].getLocation()))
		{
			destroyAsteroid(m_asteroids[i]);
		}
	}
}

/// <summary>
/// do whatever your game logic dictates happens
/// when a ship bumps into an asteroid
/// </summary>
/// <param name="t_asteroid"></param>
void GamePlay::destroyAsteroid(Asteroid &t_asteroid)
{
	t_asteroid.kill();
}


/// <summary>
/// wou might need a adiffernt set of parameters perhaps a radius or two
/// </summary>
/// <param name="t_centreOne">first vector</param>
/// <param name="t_centreTwo">second vector</param>
/// <returns></returns>
bool GamePlay::checkHit(MyVector2D t_centreOne, MyVector2D t_centreTwo)
{
	// the logic of this is sooo wrong
	// as this will be called lots of times 50 bullets * 25 asteroids = 1,250 per frame
	// usually when nothing happens it's good if it can return false as quickly as possible;
	if (t_centreOne.x - t_centreTwo.x < -100)
	{
		//way left
		return false;
	}
	if (t_centreOne.x - t_centreTwo.x > 100)
	{
		//way right
		return false;
	}
	if (t_centreOne.x == t_centreTwo.x )
	{
		return true;
	}
	return false;
}
