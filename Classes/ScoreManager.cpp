#include "ScoreManager.h"

static ScoreManager* _scoreManager;

USING_NS_CC;

ScoreManager::ScoreManager()
{
  if (!_scoreManager) {
    _scoreManager = this;
  }
  else {
    removeFromParent();
  }
}

ScoreManager* ScoreManager::getInstance()
{
  return _scoreManager;
}

bool ScoreManager::init()
{
  CCLOG("Init score manager");
  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  auto label = Label::createWithTTF("Score", "fonts/Diablo Heavy.ttf", 96);
  label->setTextColor(cocos2d::Color4B::BLACK);
  label->setPosition(origin.x + visibleSize.width - 400, origin.y + visibleSize.height - 50);
  this->addChild(label, 1);

  char scoreText[32];
  sprintf(scoreText, "%d", score);
  _labelScore = Label::createWithTTF(scoreText, "fonts/Diablo Heavy.ttf", 96);
  _labelScore->setTextColor(cocos2d::Color4B::GREEN);
  _labelScore->setPosition(origin.x + visibleSize.width - 20, origin.y + visibleSize.height - 50);
  _labelScore->setAnchorPoint({ 1,0.5f });
  this->addChild(_labelScore, 1);

  schedule(CC_SCHEDULE_SELECTOR(ScoreManager::updateScore), INTERVAL_SCORE);

  return true;
}
void ScoreManager::AddToScore(int value)
{
  _scoreManager->score += value;
  char scoreText[32];
  sprintf(scoreText, "%d", _scoreManager->score);
  _scoreManager->_labelScore->setString(scoreText);
}


void ScoreManager::updateScore(float dt)
{
  _scoreManager->AddToScore(PASSIVE_SCORE);
}