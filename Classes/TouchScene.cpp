#include "TouchScene.h"
USING_NS_CC;

cocos2d::Scene* TouchScene::createScene()
{
  auto scene = Scene::create();
  auto layer = TouchScene::create();
  scene->addChild(layer);
  return scene;
}


bool TouchScene::init()
{
  if (!Layer::init())
  {
    return false;
  }
  //BACKGROUND
  auto sprite = Sprite::create("background/backgroundColorFall.png");
  sprite->setAnchorPoint(Vec2(0, 0));
  sprite->setContentSize(Director::getInstance()->getWinSize());
  auto dir = Director::getInstance();
  sprite->setPosition(0, 0);
  this->addChild(sprite, 0);
  //---------


  labelTouchInfo = Label::createWithTTF("Touch anywhere", "fonts/Diablo Heavy.ttf", 30);
  labelTouchInfo->setPosition(Director::getInstance()->getOpenGLView()->getFrameSize().width / 2,
    Director::getInstance()->getOpenGLView()->getFrameSize().height / 2);
  auto touchListener = EventListenerTouchOneByOne::create();

  touchListener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan, this);
  touchListener->onTouchEnded = CC_CALLBACK_2(TouchScene::onTouchEnded, this);
  touchListener->onTouchMoved = CC_CALLBACK_2(TouchScene::onTouchMoved, this);
  touchListener->onTouchCancelled = CC_CALLBACK_2(TouchScene::onTouchCancelled, this);

  _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

  this->addChild(labelTouchInfo);
  return true;
}


bool TouchScene::onTouchBegan(Touch* touch, Event* event)
{
  labelTouchInfo->setPosition(touch->getLocation());
  labelTouchInfo->setString("You Touched Here");
  return true;
}
void TouchScene::onTouchEnded(Touch* touch, Event* event)
{
  cocos2d::log("touch ended");
}

void TouchScene::onTouchMoved(Touch* touch, Event* event)
{
  cocos2d::log("touch moved");
}

void TouchScene::onTouchCancelled(Touch* touch, Event* event)
{
  cocos2d::log("touch cancelled");
}
