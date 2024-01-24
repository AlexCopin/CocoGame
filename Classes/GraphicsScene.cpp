#include "GraphicsScene.h"
USING_NS_CC;

cocos2d::Scene* GraphicsScene::createScene()
{
  auto scene = Scene::create();
  auto layer = GraphicsScene::create();

  scene->addChild(layer);
  return scene;
}

bool GraphicsScene::init()
{
  if (!Layer::init())
  {
    return false;
  }

  auto sprite = Sprite::create("background/backgroundColorFall.png");
  auto sprite2 = Sprite::create("background/backgroundColorForest.png");
  sprite->setAnchorPoint(Vec2(0, 0));
  sprite2->setAnchorPoint(Vec2(0, 0));
  auto dir = Director::getInstance();
  auto visibleSize = Director::getInstance()->getOpenGLView()->getVisibleSize();
  sprite->setContentSize(visibleSize);
  sprite->addChild(sprite2);
  sprite->setPosition(100, 100);
  sprite->setPosition(0, 0);

  this->addChild(sprite, 0);

  return true;
}

void GraphicsScene::menuCloseCallback(cocos2d::Ref* pSender)
{
}
