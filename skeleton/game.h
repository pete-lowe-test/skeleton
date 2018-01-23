// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Licience.h"
#include "Splash.h"
#include "MainMneu.h"
#include "GamePlay.h"




/// <summary>
/// this class will control the overall game
/// not the gameplay that eill be a smaller part of the game
/// </summary>
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	// used to determin which screen we're on
	static GameMode m_currentMode;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	
	void setupAssets();
	Licience m_licienceScreen; // licience object to do that mode
	Splash m_splashScreen; // splash object for splash screen
	MainMneu m_mainMenuScreen; // menu screen
	GamePlay m_gamePlayScreen; // gameplay object

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used all othet lcasses only loaded once and other classes
							   // use a refrence to this
	bool m_exitGame;			// control exiting game

};

#endif // !GAME

