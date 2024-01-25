#include "Character.h"
#include "ccMacros.h"
#include <Entities/Bomb.h>
#include <Entities/Bonus.h>
#include "ScoreManager.h"

USING_NS_CC;


Character::Character()
{
  setContentSize({ 200,200 });
  setPosition({ 200,200 });
  _spritePlayer = Sprite::create(CHARACTER_SHEET);
  if (_spritePlayer->initWithFile(CHARACTER_SHEET, Rect(0, 0, CHARACTER_SHEET_SIZEX / 9, CHARACTER_SHEET_SIZEY / 5))) {
    _spritePlayer->scheduleUpdate();
  }

  auto body = PhysicsBody::createCircle(getContentSize().width / 2);
  body->setContactTestBitmask(true);
  setPhysicsBody(body);

  addChild(_spritePlayer, 1);
  _spritePlayer->setAnchorPoint(Vec2(0, 0));
  _spritePlayer->setContentSize({ 200,200 });
  _spritePlayer->setPosition({ 0,0 });
  _director = Director::getInstance();



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

  auto contactListener = EventListenerPhysicsContact::create();
  contactListener->onContactBegin = CC_CALLBACK_1(Character::onCollision, this);
  getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);


  return true;
}

void Character::update(float delta)
{
  float sprHalfWidth = _spritePlayer->getBoundingBox().size.width / 2;
  float posX = getPosition().x - delta * speed * direction;
  float limitRight = _director->getVisibleSize().width - sprHalfWidth * 2;
  posX = clampf(posX, posX >= sprHalfWidth, limitRight);
  setPosition({posX,getPosition().y});
}

bool Character::onCollision(PhysicsContact& contact)
{
    CCLOG("Collision detected");
    auto playerShape = getPhysicsBody()->getFirstShape();
    auto contactShape = contact.getShapeB();
    auto ownerContact = contactShape->getBody()->getOwner();
    if (playerShape != contact.getShapeA() && playerShape != contact.getShapeB())
    {
      return false;
    }
    if (playerShape == contact.getShapeA() && dynamic_cast<Bomb*>(ownerContact)) 
    {
      ScoreManager::AddToScore(-50);
      ownerContact->removeFromParent();
      CCLOG("Collision with bomb");
    }
    else if(playerShape == contact.getShapeA() && dynamic_cast<Bonus*>(ownerContact))
    {
      ScoreManager::AddToScore(50);
      ownerContact->removeFromParent();
      CCLOG("Collision with bonus");
    }
    //UserDefault::getInstance()->setIntegerForKey("score", _score);
    //_director->replaceScene(TransitionFlipX::create(1.0, GameOver::createScene()));
    return false;
}

