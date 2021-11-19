#include "Block.h"

Block::Block(int x, int y)
{
	rec.setSize({40,40});
	rec.setPosition(x,y);
	active = false;
}

Block::~Block()
{

}
