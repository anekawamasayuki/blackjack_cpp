#include "./deck.cpp"
#include "./human_player.cpp"
#include "./ai_player.cpp"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <typeinfo>

class Blackjack
{

  Deck deck;
  Player *you, *com;

  void deal(Player *player, bool show_flag = true){
    if(!deck.hasNext()){
      std::cout << "There's no card remaining. You cannot draw.\n";
      return;
    }

    Card c = deck.dealNext();
    player->addCard(c);

    if(!show_flag) return;

    printf("%s's hand:\t%s\n",
      player->getName().c_str(),
      player->showHand(false).c_str());
  }

  bool checkBurst(Player *player){
    if(player->calcBestScore() >= BURST_COUNT){
      printf("%s bursted!\n", player->getName().c_str());
      return true;
    }
    else {
      return false;
    }
  }

  void win(Player *player){
    result();
    printf("The winner is %s. Congrats!\n", player->getName().c_str());
  }

  void draw(){
    result();
    printf("This game is Draw. Good game!\n");
  }

  void result(){
    printf("%s's hand:\t%s \t-> %2d\n",
      you->getName().c_str(),
      you->showHand(true).c_str(),
      you->calcBestScore());
    printf("%s's hand:\t%s \t-> %2d\n",
      com->getName().c_str(),
      com->showHand(true).c_str(),
      com->calcBestScore());
  }

  void initGame(){
    deck.init();
    you->init();
    com->init();
  }

  void playGame(){
    initGame();

    std::cout << "Let's begin.\n";
    deal(you, false);
    deal(you);
    deal(com, false);
    deal(com);
    while(you->wantNext()){
      deal(you);
      if(checkBurst(you)){
        win(com);
        return;
      }
    }
    while(com->wantNext()){
      deal(com);
      if(checkBurst(com)){
        win(you);
        return;
      }
    }
    if(you->calcBestScore() > com->calcBestScore()){
      win(you);
    }
    else if(you->calcBestScore() < com->calcBestScore()){
      win(com);
    }
    else{
      draw();
    }
  }

  inline bool askNextGame(){
    return showYesNoPrompt("Wanna play again?", true, false);
  }

public:

  Blackjack(){
    you = new HumanPlayer();
    com = new AIPlayer();
  }
  ~Blackjack(){
    delete you;
    delete com;
  }

  void play(){
    std::cout << "Welcome to our Blackjack!\n";
    do{
      playGame();
    } while(askNextGame());
    std::cout << "See you again!\n";
  }
};

int main(){
  Blackjack bj;
  bj.play();
  return 0;
}