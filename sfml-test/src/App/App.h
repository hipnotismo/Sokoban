#pragma once
#include <SFML/Graphics.hpp>

class App {
private:

	sf::RenderWindow window;
	
public:
	App();
	~App();
	void LoopApp();
};