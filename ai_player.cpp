#ifndef _AI_PLAYER_CPP_
#define _AI_PLAYER_CPP_

#include "player.cpp"

#include <string>

class AIPlayer : public Player{

  const int WANT_NEXT_CRITERION = 17;

public:

  virtual std::string showHand(bool all_flag) override {
    const std::vector<Card> hand = getHand();
    std::string ret("");
    int n = hand.size();
    for (int i = 0; i < n; ++i)
    {
      if(!all_flag && i == 1) ret += "??? ";
      else ret += hand[i].toString() + " ";
    }
    return ret.substr(0, ret.length() - 1);
  }

  virtual void init() override {
    Player::init();
    if(getName().empty()) setName("COM");
  }

  virtual bool wantNext() override {
    return calcBestScore() < WANT_NEXT_CRITERION;
  }

};

#endif