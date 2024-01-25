#pragma once

#include "cocos2d.h"
#include <vector>

const cocos2d::Size ENTITY_SIZE = {200,200};
const float INTERVAL_SPAWN = 3.0f;

class EntitySpawner : public cocos2d::Node
{
public:
  EntitySpawner();
  virtual bool init() override;
  virtual void update(float delta) override;
  void spawn(float dt);
private:
  cocos2d::Director* _director;
  cocos2d::Size _visibleSize;

  virtual void spawnBomb(float dt);
  virtual void spawnBonus(float dt);
  cocos2d::Vector<class PhysicEntity*> _bombs;
  cocos2d::Vector<class PhysicEntity*> _bonus;
};