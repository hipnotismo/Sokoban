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
	delayCanMove = 0.5f;
	auxDelayCanMove = delayCanMove;
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

void Player::move(Tile board[9][18], Block* blocks[], RenderWindow& win, Theomer clock)
{
	if (delayCanMove>0)
	{
		delayCanMove = delayCanMove - clock.deltaTime();
		
	}
	else {
		delayCanMove = auxDelayCanMove;
		canMove = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int i = 0; i < 10; i++) //FOR checking all 10 moveable blocks
		{
			if (posX - 1 == blocks[i]->getPositionX() && posY == blocks[i]->getPositionY() && board[blocks[i]->getPositionY()][blocks[i]->getPositionX()-1].id == 0 && canMove)
			{
				blocks[i]->setStrideX(-1);
			}
		}

		if (canMove && posX > 0&&board[posY][posX-1].id==0) {
			posX--;
			//If you can move AND you're within the Tilemap AND the tile's ID is walkable (0).
			canMove = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 10; i++) //FOR checking all 10 moveable blocks
		{
			if (posX+1==blocks[i]->getPositionX()&&posY==blocks[i]->getPositionY()&&board[blocks[i]->getPositionY()][blocks[i]->getPositionX()+1].id==0&&canMove)
			{
				blocks[i]->setStrideX(1);
			}
		}

		if (canMove && posX < 17 && board[posY][posX + 1].id == 0) {
			posX++;
			canMove = false;
			cout << "BLOCK X:" << blocks[0]->getPositionX() << " X Player:" << posX << endl;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < 10; i++) //FOR checking all 10 moveable blocks
		{
			if (posX == blocks[i]->getPositionX() && posY-1 == blocks[i]->getPositionY() && board[blocks[i]->getPositionY()-1][blocks[i]->getPositionX()].id == 0 && canMove)
			{
				blocks[i]->setStrideY(-1);
				//If there's a block to the player's RIGHT AND b&p are in tha same Y AND the board is still walkable AND can move
			}
		}

		if (canMove && posY > 0 && board[posY-1][posX].id == 0) {
			posY--;	
			canMove = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

		for (int i = 0; i < 10; i++) //FOR checking all 10 moveable blocks
		{
			if (posX == blocks[i]->getPositionX() && posY + 1 == blocks[i]->getPositionY()&&board[blocks[i]->getPositionY() + 1][blocks[i]->getPositionX()].id == 0 && canMove)
			{
				blocks[i]->setStrideY(1);
			}
		}

		if (canMove && posY < 8&&board[posY + 1][posX].id == 0) {
			posY++;
			canMove = false;
		}
	}	


} 



