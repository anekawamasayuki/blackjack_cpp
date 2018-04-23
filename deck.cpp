#ifndef _DECK_CPP_
#define _DECK_CPP_

#include "./card.cpp"

#include <random>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#define DECK_SIZE 52

class Deck{

  std::vector<Card> cards;
  int index;

public:

  Deck(): cards(){
    init();
  }
  ~Deck(){}

  void init(){
    cards.resize(DECK_SIZE);

    for(int i = 0; i < DECK_SIZE; ++i){
      Card &c = cards[i];
      c.setNumber(i / SUIT_SIZE + 1);
      switch(i % SUIT_SIZE){
        case 0:
          c.setSuit(Suit::SPADE);
          break;
        case 1:
          c.setSuit(Suit::CLOVER);
          break;
        case 2:
          c.setSuit(Suit::HEART);
          break;
        case 3:
          c.setSuit(Suit::DIAMOND);
          break;
        default:
          std::cerr << "error: unknown Suit\n";
          exit(1);
      }
    }
    index = 0;
    shuffle();
  }

  void shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
  }

  bool hasNext(){
    return index < DECK_SIZE;
  }

  Card dealNext(){
    if(!hasNext()){
      std::cerr << "error: no card remains\n";
      exit(1);
    }
    return cards[index++];
  }
};

#endif
