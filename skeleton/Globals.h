#ifndef GLOBALS
#define GLOBALS

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
	loadLevel,
	MainMenu
};

const int MAX_ASTEROIDS = 5; // user for pool of asteroids some alive some dead (re-use dead ones)

#endif // !GLOBALS

