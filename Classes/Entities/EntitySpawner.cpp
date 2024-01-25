#include "EntitySpawner.h"
#include "Bomb.h"
#include "Bonus.h"

USING_NS_CC;

EntitySpawner::EntitySpawner()
{
  _director = Director::getInstance();
  _visibleSize = _director->getVisibleSize();
}

bool EntitySpawner::init()
{
  Node::init();
  spawn(0);
  schedule(CC_SCHEDULE_SELECTOR(EntitySpawner::spawn), INTERVAL_SPAWN);
  return true;
}

void EntitySpawner::update(float delta)
{
  Node::update(delta);
}

void EntitySpawner::spawn(float dt)
{
  if (CCRANDOM_0_1() > 0.5f) 
  {
    spawnBomb(dt);
  }
  else {
    spawnBonus(dt);
  }
}

void EntitySpawner::spawnBomb(float dt)
{
  Bomb* bomb = new Bomb;
  bomb->_sprite = Sprite::create("bomb.png");
  bomb->setContentSize(ENTITY_SIZE);
  bomb->init();
  this->addChild(bomb, 1);
  bomb->setPosition(CCRANDOM_0_1() * _visibleSize.width, _visibleSize.height + bomb->getContentSize().height / 2);
  bomb->getPhysicsBody()->setVelocity(Vect(0, ((CCRANDOM_0_1() + 0.2f) * -250)));
  _bombs.pushBack(bomb);
}

void EntitySpawner::spawnBonus(float dt)
{
  Bonus* bonus = new Bonus;
  bonus->_sprite = Sprite::create("bonus.png");
  bonus->setContentSize(ENTITY_SIZE);
  bonus->init();
  this->addChild(bonus, 1);
  bonus->setPosition(CCRANDOM_0_1() * _visibleSize.width, _visibleSize.height + bonus->getContentSize().height / 2);
  bonus->getPhysicsBody()->setVelocity(Vect(0, ((CCRANDOM_0_1() + 0.2f) * -250)));
  _bonus.pushBack(bonus);
}
