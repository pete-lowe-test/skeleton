#include "Licience.h"
#include "Game.h"


Licience::Licience()
{
}


Licience::~Licience()
{
}

void Licience::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::m_currentMode = GameMode::Splash;
	}
}

void Licience::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Yellow);
	t_window.draw(m_message);
	t_window.display();
}

void Licience::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Blue);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Licience screen/ presss pace to go to splash");
	m_message.setFont(m_font);
}
