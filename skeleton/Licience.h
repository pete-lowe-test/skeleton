#pragma once
#include "game.h"
#include <SFML\Graphics.hpp>

class Licience
{
public:
	Licience();
	~Licience();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void setup(sf::Font &t_font);
private:
	sf::Font m_font;
	sf::Text m_message;
};

