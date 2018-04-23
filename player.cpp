#ifndef _PLAYER_CPP_
#define _PLAYER_CPP_

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#define BURST_COUNT 22

class Player{

  std::string m_name;
  std::vector<Card> m_hand;

protected:

  virtual void setName(std::string str){
    m_name = str;
  }

public:

  Player(){
    init();
  }
  virtual ~Player(){}

  virtual void init(){
    m_hand.clear();
  }

  inline int getCount(){return m_hand.size();}
  inline std::string getName(){return m_name;}
  inline const std::vector<Card>& getHand(){return m_hand;}

  virtual std::string showHand(bool all_flag){
    std::string ret("");
    int n = m_hand.size();
    for (int i = 0; i < n - 1; ++i)
    {
      ret += m_hand[i].toString() + " ";
    }
    ret += m_hand.back().toString();
    return ret;
  }

  void addCard(Card c){
    m_hand.push_back(c);
  }

  int calcBestScore(){
    int a_num = 0, other_sum = 0;

    for(auto&& c : m_hand) {
      if (c.getNumber() == 1) ++a_num;
      else other_sum += std::min(10, c.getNumber());
    }
    /* 11 * x + 1 * (a_num - x) + other_sum <= 21
       =>  x <= (21 - other_sum - a_num) / 10     */
    int x = std::max(0, std::min(a_num, (BURST_COUNT - other_sum - a_num) / 10));
    return other_sum + 10 * x + a_num;
  }

  virtual bool wantNext() = 0;

};

#endif