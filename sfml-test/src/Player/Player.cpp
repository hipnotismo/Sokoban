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
	sprite.setPosition(x, y);
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
	win.draw(sprite);
}

void Player::move(Tile board[9][18], Block* blocks[])
{
	bool canMove = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

		for (int i = 0; i < 10; i++) {
			if (blocks[i]->getPositionY() == posY + 1 && blocks[i]->getPositionX() == posX && board[posX][posY + 2].id == 0 && blocks[i]->getActive()) {
						blocks[i]->setPosition(static_cast<int>(board[posX][posY + 2].rec.getPosition().x), static_cast<int>(board[posX][posY + 2].rec.getPosition().y));
						
				}
			for (int j = 0; j < 10; j++) {
				if (blocks[i]->getPositionX() == blocks[j]->getPositionX() && blocks[i]->getPositionY() == blocks[j]->getPositionY() && i != j) {
					blocks[i]->setVPosition(board[posX][posY + 1].rec.getPosition());
					blocks[i]->setStrideY(-1);
					canMove = false;
				}
			}


			if ((posY + 1 == blocks[i]->getPositionY() && posX == blocks[i]->getPositionX() && board[posX][posY + 2].id != 0) && canMove && blocks[i]->getActive() || canMove && board[posX][posY + 1].id != 0) {
				canMove = false;
			}
		}
		if (canMove) {
			pos = { board[posX][posY + 1].rec.getPosition() };
			posX++;
			setPosition(posX, posY);
			canMove = false;
			cout << "this working?" << endl;
			cout<<sprite.getPosition().x << endl;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		cout << "Moving up" << endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		cout << "Moving down" << endl;
	}
}
