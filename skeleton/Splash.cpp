#include "Splash.h"
#include "game.h"



Splash::Splash()
{
}


Splash::~Splash()
{
}


void Splash::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		Game::m_currentMode = GameMode::MainMenu;
	}
}

void Splash::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Red);
	t_window.draw(m_message);
	t_window.display();
}

void Splash::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Splash screen/ presss m to go to menu");
	m_message.setFont(m_font);
}

