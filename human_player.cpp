#ifndef _HUMAN_PLAYER_CPP_
#define _HUMAN_PLAYER_CPP_

#include "player.cpp"
#include "./utility.cpp"

#include <string>

class HumanPlayer : public Player {

public:

  HumanPlayer(){}
  ~HumanPlayer(){}

  virtual void init() override {
    Player::init();
    if(getName().empty()){
      setName(showStringPrompt("Enter your name: "));
    }
  }

  virtual bool wantNext() override {
    return showYesNoPrompt("Do you want a next card?");
  }

};

#endif