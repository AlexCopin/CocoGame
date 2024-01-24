#pragma once


#include "cocos2d.h"
#include <string>

const std::string CHARACTER_SHEET = "tilesheets/character_zombie_sheet.png";
const int CHARACTER_SHEET_SIZEX = 864;
const int CHARACTER_SHEET_SIZEY = 640;

class Character : public cocos2d::Node
{
public:
  Character();
  float speed = 500.0f;
  cocos2d::Sprite* _spritePlayer;

  float direction = 0;

  void MoveLeft();
  void MoveRight();
  void StopMoving();


  virtual bool init() override;
  virtual void update(float delta) override;
};