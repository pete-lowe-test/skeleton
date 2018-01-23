#include "MainMneu.h"
#include "Game.h"



MainMneu::MainMneu()
{
}


MainMneu::~MainMneu()
{
}

/// <summary>
/// simple 1 to start game at the moment
/// </summary>
/// <param name="t_deltaTime">time slice</param>
void MainMneu::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		Game::m_currentMode = GameMode::GamePlay;
	}
}

/// <summary>
/// draw menu screen
/// </summary>
/// <param name="t_window"></param>
void MainMneu::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Yellow);
	t_window.draw(m_message);
	t_window.display();
}


/// <summary>
/// setup menu page
/// use existing font
/// set up text object
/// </summary>
/// <param name="t_font"></param>
void MainMneu::setup(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Blue);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Main Menu /n presss 1 to go to play game");
	m_message.setFont(m_font);
}
