#include "PhysicEntity.h"

USING_NS_CC;

bool PhysicEntity::init()
{
  Node::init();
  auto body = PhysicsBody::createCircle(getContentSize().width / 2);
  body->setContactTestBitmask(true);
  body->setDynamic(true);
  setPhysicsBody(body);
  setAnchorPoint(Vec2(0, 0));
  setContentSize({ 200,200 });

  this->addChild(_sprite, 1);
  _sprite->setAnchorPoint(Vec2(0, 0));
  _sprite->setContentSize({ 200,200 });
  _sprite->setPosition({ 0,0 });

  return true;
}
