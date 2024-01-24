#include "GameScene.h"
#include "Character/Character.h"

USING_NS_CC;

cocos2d::Scene* GameScene::createScene()
{
  auto scene = Scene::create();
  auto layer = GameScene::create();

  scene->addChild(layer);
  return scene;
}

bool GameScene::init()
{
  if (!Layer::init())
  {
    return false;
  }

  //--BACKGROUND
  auto sprite = Sprite::create("background/backgroundColorForest.png");
  sprite->setAnchorPoint(Vec2(0, 0));
  sprite->setContentSize(Director::getInstance()->getWinSize());
  auto dir = Director::getInstance();
  sprite->setPosition(0, 0);
  this->addChild(sprite, 0);
  //---------

  //---Init Character
  player = new Character();
  player->init();
  player->setPosition(PLAYERSTARTPOS);
  addChild(player, 1);
  player->scheduleUpdate();
  //-------

  InitKeyboardListener();



  //Update
  this->scheduleUpdate();

  return true;
}

void GameScene::InitKeyboardListener()
{
  auto listener = EventListenerKeyboard::create();
  listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this); 
  listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
  switch (keyCode) {
    case EventKeyboard::KeyCode::KEY_BACK:
      Director::getInstance()->end();
      break;
    case EventKeyboard::KeyCode::KEY_Q :
      player->MoveLeft();
      break;
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
      player->MoveLeft();
      break;
    case EventKeyboard::KeyCode::KEY_D:
      player->MoveRight();
      break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
      player->MoveRight();
      break;
  }
}

void GameScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
  if (keyCode == EventKeyboard::KeyCode::KEY_Q ||
    keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW ||
    keyCode == EventKeyboard::KeyCode::KEY_D ||
    keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
  {
   // player->StopMoving();
  }
}