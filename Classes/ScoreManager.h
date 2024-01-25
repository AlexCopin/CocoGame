#pragma once

#include "cocos2d.h"

const int PASSIVE_SCORE = 10;
const float INTERVAL_SCORE = 2.f;

class ScoreManager : public cocos2d::Node
{
public:
  ScoreManager();
  static ScoreManager* getInstance();
  static void AddToScore(int value);
  virtual bool init() override;
private:
  int score = 0;
  cocos2d::Label* _labelScore;
  void updateScore(float dt);
};