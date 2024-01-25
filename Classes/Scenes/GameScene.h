#pragma once

#include "cocos2d.h"

//CONSTANTES
const cocos2d::Vec2 PLAYERSTARTPOS = {50,50};

class GameScene : public cocos2d::Layer
{
public:
  static cocos2d::Scene* createScene();
  virtual bool init();

  // a selector callback
  void menuCloseCallback(cocos2d::Ref* pSender);

  // implement the "static create()" method manually
  CREATE_FUNC(GameScene);

  void InitKeyboardListener();
  virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;
  virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;


  //Character
  class Character* player;
  //score
  int _score = 0;
};