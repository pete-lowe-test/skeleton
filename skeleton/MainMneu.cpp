#include "MainMneu.h"
#include "Game.h"



MainMneu::MainMneu()
{
}


MainMneu::~MainMneu()
{
}

void MainMneu::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::m_currentMode = GameMode::Splash;
	}
}

void MainMneu::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Yellow);
	t_window.draw(m_message);
	t_window.display();
}

void MainMneu::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Blue);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Main Menu / presss 1 to go to play game");
	m_message.setFont(m_font);
}
