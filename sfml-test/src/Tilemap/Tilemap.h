#pragma once
#include <SFML/Graphics.hpp>
#include "Blocks/Block.h"
using namespace sf;
//-----------
	//IDs:
	// 1- Left
	// 2- Down
	// 3- Right 
	// 4- Up
	// 5- Center
	// 6- Walkable
	//-----------

class Tilemap{
private:
	Block tiles[9][18];
	Texture texture;
	Sprite sprite[6];
	RectangleShape rec;
	int id;
	bool winSlot;
public:
	Tilemap();
	~Tilemap();
};
