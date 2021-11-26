#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include "Blocks/Block.h"
using namespace sf;

//-----------
	//IDs:
	// 0- Blank - Walkable
	// 1- Center
	// 2- Left
	// 3- Up
	// 4- Right
	// 5- Down
	// 6- Objective
	//-----------

class Tilemap{
private:
	struct Tile
	{
		sf::RectangleShape rec; 
		int id;
		bool winSlot;
		sf::Sprite sprite;
	};
	const int maxTLX = 18;
	const int maxTLY = 9;
	sf::Texture atlas[7];

	Block* blocks[10];
public:
	Tile board[9][18]; //Tilemap is x = 18, y = 9 TOTAL: 162
	Tilemap();
	~Tilemap();
	void initTile();
	void LoadAtlas();
	void LoadSprites();
	void draw(sf::RenderWindow& win);

	void clearBoard();
	void levelOne(Player* p1);


};
