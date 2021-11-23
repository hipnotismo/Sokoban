#include "Tilemap.h"

Tilemap::Tilemap()
{
	initTile();
	LoadAtlas();
	LoadSprites();
}

void Tilemap::initTile()
{
	for (int i = 0; i < maxTLY; i++) {
		for (int j = 0; j < maxTLX; j++) {
			board[i][j].rec.setSize(sf::Vector2f(40.0f, 40.0f));
			board[i][j].rec.setPosition(40 + 40 * j, 25 + 40 * i);
			board[i][j].sprite.setPosition(Vector2f(board[i][j].rec.getPosition()));
			l.push_front(board[i][j]);
			board[i][j].id = 4;
		}
	}

}
void Tilemap::LoadAtlas()
{
	atlas[0].loadFromFile("res/Left.png");
	atlas[1].loadFromFile("res/Down.png");
	atlas[2].loadFromFile("res/Right.png");
	atlas[3].loadFromFile("res/Up.png");
	atlas[4].loadFromFile("res/Center.png");
	atlas[5].loadFromFile("res/Blank.png");
	atlas[6].loadFromFile("res/WinSlot.png");

}

void Tilemap::LoadSprites()
{
	for (int i = 0; i < maxTLY; i++) {
		for (int j = 0; j < maxTLX; j++) {
			switch (board[i][j].id) {
			case 0:
				board[i][j].sprite.setTexture(atlas[0]);
				break;
			case 1:
				board[i][j].sprite.setTexture(atlas[1]);
				break;
			case 2:
				board[i][j].sprite.setTexture(atlas[2]);
				break;
			case 3:
				board[i][j].sprite.setTexture(atlas[3]);
				break;
			case 4:
				board[i][j].sprite.setTexture(atlas[4]);
				break;
			case 5:
				board[i][j].sprite.setTexture(atlas[5]);
				break;
			case 6:
				board[i][j].sprite.setTexture(atlas[6]);
				break;
			default:
				board[i][j].sprite.setTexture(atlas[4]);
				break;
			}
		}
	}

}

void Tilemap::draw(sf::RenderWindow& win)
{
	for (int i = 0; i < maxTLY; i++) {
		for (int j = 0; j < maxTLX; j++) {
			win.draw(board[i][j].sprite);
		}
	}
}
