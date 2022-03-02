#include<iostream>
#include<map>
#include<vector>
#include <regex>

bool gram_S(std::string s);
bool gram_A(std::string s);
bool gramatica(std::string palabra);

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
  if(std::regex_match(s, std::regex("(a)([A-Za-z])*(b)")))
    return gram_A(s.substr(1, s.length()-2));

  return false;
}

bool gram_A(std::string s){
  if(std::regex_match(s, std::regex("(c)|(a)")))
    return true;

  return false;
}

bool gramatica(std::string palabra){
  return gram_S(palabra);
  /*
  std::map<char,std::string> mymap;
  std::map<std::string,std::string>::iterator it;
  mymap['S'] = "(aAb)"; // "(a)([a-Z])(b)"
  mymap['A'] =  "(c)|(a)";
  
  int count = 1;
  if(count == 1){
    std::string w = mymap['S'];
    for(int i = 0 ; i < w.size(); i++){
      for(int j = 0; j < palabra.size(); i++){
	if(minusculas(j) && minusculas(i)){
	  if(w[i] == palabra[j]){
	    std::cout<<"entre "<< w[i]<<palabra[j]<<"\n";
	    break;
	  }
	}
      }
    }
  }
  return true;
  */
}
