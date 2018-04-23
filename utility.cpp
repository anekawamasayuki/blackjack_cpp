#ifndef _UTILITY_CPP_
#define _UTILITY_CPP_

#include <string>
#include <iostream>

bool showYesNoPrompt(const char * question,
  bool hasDefaultAnswer = false,
  bool defaultAnswer = false){
  std::string str;
  while(true){
    std::cout << question;
    if (hasDefaultAnswer)
    {
      if(defaultAnswer) {
        std::cout << "[Y/n]: ";
      }
      else {
        std::cout << "[y/N]: ";
      }
    }
    else{
      std::cout << "[y/n]: ";
    }

    std::cin >> str;

    if(hasDefaultAnswer && str.empty()){
      return defaultAnswer;
    }
    if(str == std::string("y") || str == std::string("Y")){
      return true;
    }
    else if(str == std::string("n") || str == std::string("N")){
      return false;
    }
    else{
      std::cout << "sorry, try again.\n";
    }
  }
}

std::string showStringPrompt(const char * question){
  std::string str;
  std::cout << question;
  std::cin >> str;
  return str;
}

#endif