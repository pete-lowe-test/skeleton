// author Peter Lowe

#include "Game.h"
#include <iostream>


// neede to initialise the gamemode
GameMode Game::m_currentMode{ GameMode::Licience };

Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupAssets(); // load font 

}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	switch (m_currentMode)
	{
	case GameMode::Licience:
		break;
	case GameMode::Splash:
		break;
	case GameMode::Map:
		break;
	case GameMode::Help:
		break;
	case GameMode::HighScore:
		break;
	case GameMode::GamePlay:
		break;
	case GameMode::Pause:
		break;
	case GameMode::GameOver:
		break;
	case GameMode::Credits:
		break;
	case GameMode::Market:
		break;
	case GameMode::Upgrades:
		break;
	case GameMode::Story:
		break;
	case GameMode::loadLevel:
		break;
	default:
		break;
	}
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	switch (m_currentMode)
	{
	case GameMode::Licience:
		break;
	case GameMode::Splash:
		break;
	case GameMode::Map:
		break;
	case GameMode::Help:
		break;
	case GameMode::HighScore:
		break;
	case GameMode::GamePlay:
		break;
	case GameMode::Pause:
		break;
	case GameMode::GameOver:
		break;
	case GameMode::Credits:
		break;
	case GameMode::Market:
		break;
	case GameMode::Upgrades:
		break;
	case GameMode::Story:
		break;
	case GameMode::loadLevel:
		break;
	default:
		break;
	}
	m_window.clear(sf::Color::White);
	
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupAssets()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	

}

