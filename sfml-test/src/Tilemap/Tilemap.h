#pragma once
#include <list>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
//-----------
	//IDs:
	// 1- Left
	// 2- Down
	// 3- Right 
	// 4- Up
	// 5- Center
	// 6- Walkable
	// 7- Objective
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


};
