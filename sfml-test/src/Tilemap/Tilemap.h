#pragma once
#include <list>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
//-----------
	//IDs:
	// 0- Blank
	// 1- Center
	// 2- Left
	// 3- Up
	// 4- Right
	// 5- Down
	// 6- Objective
	//-----------

class Tilemap{
private:
	const int maxTLX = 18;
	const int maxTLY = 9;
	sf::Texture atlas[7];

	struct tile
	{
		sf::RectangleShape rec; 
		int id;
		bool winSlot;
		sf::Sprite sprite;
	};
	tile board[9][18]; //Tilemap is x = 18, y = 9

	list<tile> l;
public:
	Tilemap();
	~Tilemap();
	void initTile();
	void LoadAtlas();
	void LoadSprites();
	void draw(sf::RenderWindow& win);

	void clearBoard();
	void levelOne();


};
