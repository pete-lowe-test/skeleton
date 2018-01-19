// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Licience.h"

/// <summary>
/// this enum will hold the different modes/screens the game be in
/// </summary>
enum class  GameMode
{
	Licience,
	Splash,
	Map,
	Help,
	HighScore,
	GamePlay,
	Pause,
	GameOver,
	Credits,
	Market,
	Upgrades,
	Story,
	loadLevel
};

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

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game

};

#endif // !GAME

