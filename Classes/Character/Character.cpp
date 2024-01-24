#include "Character.h"


USING_NS_CC;


Character::Character()
{
  setPosition({ 200,200 });
  _spritePlayer = Sprite::create(CHARACTER_SHEET);
  if (_spritePlayer->initWithFile(CHARACTER_SHEET, Rect(0, 0, CHARACTER_SHEET_SIZEX / 9, CHARACTER_SHEET_SIZEY / 5))) {
    _spritePlayer->scheduleUpdate();
  }
  addChild(_spritePlayer, 1);
  _spritePlayer->setAnchorPoint(Vec2(0, 0));
  _spritePlayer->setContentSize({ 200,200 });
  _spritePlayer->setPosition({ 0,0 });
}

void Character::MoveLeft()
{
  direction = 1;
  _spritePlayer->setFlippedX(true);
}

void Character::MoveRight()
{
  direction = -1;
  _spritePlayer->setFlippedX(false);
}

void Character::StopMoving()
{
  direction = 0;
}

bool Character::init()
{
  Node::init();
  return true;
}

void Character::update(float delta)
{
  setPosition({ 
    getPosition().x - delta * speed * direction,
    getPosition().y 
    });
}

