#include<iostream>
#include<map>
#include<vector>
#include <regex>

#include <gramatica.h>

/**
GRAMATICA
S -> aAb|b
A -> bdE|E
E -> c|a
Comprobar:
b      
abdcb  
abdab  
acb    
aab    
**/

int main(){
  
  std::string palabra;

  std::cout << "Inserte string: ";
  std::cin >> palabra;
  std::cout << std::endl;
  
  if(gramatica(palabra))
    std::cout << "Verdadero " << gramatica(palabra) << std::endl;
  else
    std::cout << "Falso " << gramatica(palabra) << std::endl;
  
  return 0;
}

bool gram_S(std::string s){
  if(std::regex_match(s, std::regex("(a)([A-Za-z])*(b)"))){
    return gram_A(s.substr(1, s.length()-2));
  }else if(std::regex_match(s, std::regex("(b)"))){
    return true;
  }else{
    return false;
  }
}

bool gram_A(std::string s){
  if(std::regex_match(s, std::regex("(b)(d)([A-Za-z])*"))){
    return gram_E(s.substr(2, s.length()-1));
  }else if(std::regex_match(s, std::regex("([A-Za-z])*"))){
    return gram_E(s);
  }else{
    return false;
  }
}

bool gram_E(std::string s){
  if(std::regex_match(s, std::regex("(c)|(a)")))
    return true;

  return false;
}

bool gramatica(std::string palabra){
  return gram_S(palabra);
  
}
