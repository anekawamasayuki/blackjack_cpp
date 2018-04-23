#ifndef _CARD_CPP_
#define _CARD_CPP_

#include <iostream>
#include <string>

#define SUIT_SIZE 4

enum class Suit: unsigned char{
  SPADE,
  CLOVER,
  HEART,
  DIAMOND,
  UNKNOWN = 100,
};

class Card{

  Suit m_suit;
  int m_number;

public:

  Card(Suit _suit, int _number)
    : m_suit(_suit), m_number(_number) {}

  Card(): m_suit(Suit::UNKNOWN), m_number(-1) {}

  ~Card(){}

  inline Suit getSuit(){return m_suit;}
  inline void setSuit(Suit _suit){m_suit = _suit;}

  inline int getNumber(){return m_number;}
  inline void setNumber(int _number){m_number = _number;}

  std::string SuitToString(Suit s) const {
    switch(s){
      case Suit::SPADE:   return "♠";
      case Suit::CLOVER:  return "♣";
      case Suit::HEART:   return "♥";
      case Suit::DIAMOND: return "♦";
      default:
        std::cerr << "error: unknown suit\n";
        exit(1);
    }
  }

  std::string toString() const {
    std::string ret = std::to_string(m_number);
    if(m_number == 1) ret = std::string("A");
    if(m_number == 11) ret = std::string("J");
    if(m_number == 12) ret = std::string("Q");
    if(m_number == 13) ret = std::string("K");
    return SuitToString(m_suit) + " " + ret;
  }
};

#endif