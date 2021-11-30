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


	if (!buffer.loadFromFile("res/move.wav"))
	{
		std::cout << "error" << std::endl;
	}
	canMove = true;
	delayCanMove = 0.3f;
	auxDelayCanMove = delayCanMove;
	sound.setBuffer(buffer);
	sound.setVolume(10);
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
	if (!pause)
	{

	}
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
			for (int j = 0; j < 10; j++)
			{
				if (posX - 1 == blocks[i]->getPositionX() &&
					posX - 2 == blocks[j]->getPositionX() &&
					blocks[i]->getActive() &&
					blocks[j]->getActive() &&
					posY == blocks[i]->getPositionY() &&
					posY==blocks[j]->getPositionY())
				{
					canMove = false;
					//WHEN There is a block below the player, and a block below Block1, AND the X axis is aligned AND everything is active THEN move false
				}
			}
			if (board[posY][posX - 2].id != 0 && posX - 1 == blocks[i]->getPositionX() && posY == blocks[i]->getPositionY()) //PLAYER - BLOCK - WALL
			{
				canMove = false;

			}
			
			if (posX - 1 == blocks[i]->getPositionX() && posY == blocks[i]->getPositionY() && board[blocks[i]->getPositionY()][blocks[i]->getPositionX()-1].id == 0 && canMove)
			{
				blocks[i]->setStrideX(-1);
			}
		}

		if (canMove && posX > 0&&board[posY][posX-1].id==0) {
			posX--;
			//If you can move AND you're within the Tilemap AND the tile's ID is walkable (0).
			canMove = false;
			sound.play();
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 10; i++) //FOR checking all 10 moveable blocks
		{
			for (int j = 0; j < 10; j++)
			{
				if (posX + 1 == blocks[i]->getPositionX() && posX + 2 == blocks[j]->getPositionX() && blocks[i]->getActive() && blocks[j]->getActive() && posY == blocks[i]->getPositionY() && posY == blocks[j]->getPositionY())
				{
					canMove = false;
					//WHEN There is a block below the player, and a block below Block1, AND the X axis is aligned AND everything is active THEN move false
				}
			}
			if (board[posY][posX+2].id!=0&& posX + 1 == blocks[i]->getPositionX() && posY == blocks[i]->getPositionY())
			{
				canMove = false;
			}
			if (posX+1==blocks[i]->getPositionX()&&posY==blocks[i]->getPositionY()&&board[blocks[i]->getPositionY()][blocks[i]->getPositionX()+1].id==0&&canMove)
			{
				blocks[i]->setStrideX(1);

			}
		}

		if (canMove && posX < 17 && board[posY][posX + 1].id == 0) {
			posX++;
			canMove = false;
			cout << "BLOCK X:" << blocks[0]->getPositionX() << " X Player:" << posX << endl;
			sound.play();
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < 10; i++) //FOR checking all 10 moveable blocks
		{
			for (int j = 0; j < 10; j++)
			{
				if (posY - 1 == blocks[i]->getPositionY() &&
					posY - 2 == blocks[j]->getPositionY() &&
					blocks[i]->getActive() &&
					blocks[j]->getActive() &&
					posX == blocks[i]->getPositionX() &&
					posX == blocks[j]->getPositionX())
				{
					canMove = false;
					//WHEN There is a block below the player, and a block below Block1, AND the X axis is aligned AND everything is active THEN move false
				}

			}
			if (board[posY-2][posX].id != 0 && posY - 1 == blocks[i]->getPositionY() && posX == blocks[i]->getPositionX())
			{
				canMove = false;
			}

			if (posX == blocks[i]->getPositionX() && posY-1 == blocks[i]->getPositionY() && board[blocks[i]->getPositionY()-1][blocks[i]->getPositionX()].id == 0 && canMove)
			{
				blocks[i]->setStrideY(-1);
				//If there's a block to the player's RIGHT AND b&p are in tha same Y AND the board is still walkable AND can move
			}
		}

		if (canMove && posY > 0 && board[posY-1][posX].id == 0) {
			posY--;	
			canMove = false;
			sound.play();
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

		for (int i = 0; i < 10; i++) //FOR checking all 10 moveable blocks
		{
			for (int j = 0; j < 10; j++)
			{
				if (posY+1== blocks[i]->getPositionY() && posY+2==blocks[j]->getPositionY() && blocks[i]->getActive()&&blocks[j]->getActive()&&posX==blocks[i]->getPositionX() && posX == blocks[j]->getPositionX())
				{
					canMove = false; 
					//WHEN There is a block below the player, and a block below Block1, AND the X axis is aligned AND everything is active THEN move false
				}
			}
			if (board[posY + 2][posX].id != 0 && posY + 1 == blocks[i]->getPositionY() && posX == blocks[i]->getPositionX())
			{
				canMove = false;
			}
			if (posX == blocks[i]->getPositionX() && posY + 1 == blocks[i]->getPositionY()&&board[blocks[i]->getPositionY() + 1][blocks[i]->getPositionX()].id == 0 && canMove)
			{
				blocks[i]->setStrideY(1);
			}
		}

		if (canMove && posY < 8&&board[posY + 1][posX].id == 0) {
			posY++;
			canMove = false;
			sound.play();
		}

	}	
} 



