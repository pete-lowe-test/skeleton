#include "Asteroid.h"

 // static variables need to be initialised outside the class code

int Asteroid::s_sizes[4]={ 32,64,96,128 };  // differwent sizes in pixels for sprites
sf::Texture Asteroid::s_asteroidTexture;  // texture used by all asteroid instances
// source areas inside sprite for different  size asteroids
sf::IntRect Asteroid::s_textureMapping[4] = {
	{0,192,32,32},
	{0,128,64,64},
	{128,0,96,96},
	{0,0,128,128} }; 

Asteroid::Asteroid()
{
}


Asteroid::~Asteroid()
{
}

/// <summary>
// move and readjust sprite location
/// </summary>
/// <param name="t_deltaTime">tim eincrement</param>
void Asteroid::update(sf::Time t_deltaTime)
{
	move();
	double offset = static_cast<double>(s_sizes[m_size]) / 2.0;
	m_sprite.setPosition(static_cast<sf::Vector2f>(m_location - MyVector2D{ offset,offset }));
}
 

/// <summary>
/// draw the steroid
/// </summary>
/// <param name="t_window">render window</param>
void Asteroid::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_sprite);
}

/// <summary>
/// load the texture once per class
/// </summary>
void Asteroid::loadTexture()
{
	if (!s_asteroidTexture.loadFromFile("ASSETS\\IMAGES\\asteroids.png"))
	{
		std::cout << "problem loading ship texture" << std::endl;
	}
}


/// <summary>
/// setup each asteroid for the first time
/// </summary>
void Asteroid::setup()
{
	m_size = std::rand() % 4;;
	m_sprite.setTexture(s_asteroidTexture);	
	// initialise();
}


/// <summary>
///  make the asteroid active and give it it's initial values
/// </summary>
/// <param name="t_loaction">position</param>
/// <param name="t_velocity">velocity</param>
/// <param name="t_size">intial size</param>
void Asteroid::initialise(MyVector2D t_loaction, MyVector2D t_velocity, int t_size)
{
	m_size = t_size;
	m_sprite.setTextureRect(s_textureMapping[m_size]);
	m_location = t_loaction;
	m_velocity = t_velocity;
	m_alive = true;
}

/// <summary>
/// check if the asteroid is alive
/// </summary>
/// <returns>if alive true</returns>
bool Asteroid::alive()
{
	return m_alive;
}

/// <summary>
/// destroy the asteroid
/// </summary>
void Asteroid::kill()
{
	m_alive = false;
}

/// <summary>
/// find the location used for collisions etc.
/// </summary>
/// <returns>current location</returns>
MyVector2D Asteroid::getLocation()
{
	return m_location;
}

/// <summary>
/// update the location
/// </summary>
void Asteroid::move()
{
	m_location += m_velocity;
}
