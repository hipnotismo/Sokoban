#pragma once
#include <SFML/Graphics.hpp>
#include <queue>

class App {
private:
	sf::RenderWindow window;
	enum class Screens
	{
		Menu = 0, Gameplay, GameOver, Credits
	};
	Screens currentScreen;
	sf::CircleShape shape;
	std::queue<sf::CircleShape> q;
	//vector<int> test;
	
	
public:
	App();
	~App();
	void LoopApp();

	void Draw(sf::RenderWindow &win);
};