#include<iostream>
#include<map>

bool gramatica(std::string g);

int main(){
  if(gramatica("000111")){
    std::cout<<"SI\n";
  }else{
    std::cout<<"NO\n";
  }
    
  return 0;
}

bool gramatica(std::string g){
  std::map<std::string, std::string> gram;
  std::map<std::string,std::string>::iterator it;
  /**
  gram["E"] = ["(TE')"];
  gram["E'"] = ["(+TE')|(e)"];
  gram["T"] = ["(FT')"];
  gram["T'"] = ["(*FT')|(e)"];
  gram["F"] = ["((E))|(id)"];
  **/
  //gram["S"] = ["(0S1)|(01)"];

  int longitud = g.size();
  if (g.size() == 0){
    return true;
  }else if(g == "01"){
    return true;
  }else if(g.front()== '0' && g.back()== '1'){
    g = g.substr(1,g.size()-2);
    return gramatica(g);
  }else{
    return false;
  }
  return false;
}
      
