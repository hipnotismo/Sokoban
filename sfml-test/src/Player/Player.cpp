#include "player.h"
#include "Blocks/Block.h"


Player::Player()
{
	pos.x = 0;
	pos.y = 0;
	posX = 0;
	posY = 0;
	texture.loadFromFile("res/CloakGuy.png");
	sprite.setTexture(texture);
	canMove = true;
}

Player::~Player()
{
}

void Player::setVPosition(float x1, float y1)
{
	pos.x = x1;
	pos.y = y1;
	sprite.setPosition(x1,y1);
	
}
void Player::setVPosition(Vector2f f)
{
	pos = f;
	sprite.setPosition(f);
}
Vector2f Player::getVPosition()
{
	return pos;
}
void Player::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

int Player::getPositionX()
{
	return posX;
}

int Player::getPositionY()
{
	return posY;
}

void Player::draw(RenderWindow& win)
{
	sprite.setPosition((posX*40)+40,(posY*40)+25);
	win.draw(sprite);
}

void Player::move(Tile board[9][18], Block* blocks[], RenderWindow& win)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (canMove && posX > 0&&board[posY][posX-1].id==0) {
			posX--;
			//If you can move AND you're withing the Tilemap AND the tile's ID is walkable (0).
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 10; i++) //FOR checking all 10 moveable blocks
		{
			if (blocks[i]->getPositionX() == posX+1 && board[posY][posX+2].id!=0)
			{
				canMove = false;
			}
			else {
				blocks[i]->setStrideX(1);
			}
		}

		if (canMove && posX < 17 && board[posY][posX + 1].id == 0) {
			posX++;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (canMove && posY > 0 && board[posY-1][posX].id == 0) {
			posY--;	
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (canMove && posY < 8&&board[posY + 1][posX].id == 0) {
			posY++;				
		}
	}	


} 



