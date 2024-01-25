#pragma once

#include "cocos2d.h"


class PhysicEntity : public cocos2d::Node
{
public:
  virtual bool init() override;
  cocos2d::Sprite* _sprite;
};