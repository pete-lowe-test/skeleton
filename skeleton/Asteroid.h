#pragma once
#include <SFML\Graphics.hpp>
#include "MyVector2D.h"
#include <iostream>


class Asteroid
{
public:
	Asteroid();
	~Asteroid();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	static void loadTexture();
	void setup();
	void initialise(MyVector2D t_loaction, MyVector2D t_velocity, int t_size);
	bool alive();	
	void kill();
	MyVector2D getLocation();

	static int s_sizes[4]; // radus for asteroids
private:
	bool m_alive;
	int m_size;

	static sf::Texture s_asteroidTexture; // texture for class
	static sf::IntRect s_textureMapping[4]; // source rectangles for different size astweroids in texture atlas
	sf::Sprite m_sprite; // sprite for asteroid
	MyVector2D m_location; // where it's at
	MyVector2D m_velocity; // per asteroid
	MyVector2D m_acceleration; //basedon ships direction
	void move();
	
	
};

