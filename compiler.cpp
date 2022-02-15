#include<iostream>
#include<map>
#include<vector>

bool gramatica(std::string g);

int main(){
  if(gramatica("TETT'")){
    std::cout<<"SI\n";
  }else{
    std::cout<<"NO\n";
  }
    
  return 0;
}

bool gramatica(std::string g){
  std::map<std::string, std::string> gram;
  std::map<std::string,std::string>::iterator it;
  std::vector<std::string> myvec;

  //GRAMATICA 2
  gram["E"] = "(TE')";
  gram["E'"] = ["(+TE')|(e)"];
  gram["T"] = ["(FT')"];
  gram["T'"] = ["(*FT')|(e)"];
  gram["F"] = ["((E))|(id)"];
  gram["S"] = ["(0S1)|(01)"];

  for(it = mymap.begin(); it != mymap.end(); it++){
    for(int i = 0; i < g.size(); i++){
      if(std::regex(it->first) == g[i]){
	myvec.push_back(g[i]);
      }else{
	std::string gs = g.substr(i,2);
	if(std::regex(it->first) == gs)
	  myvec.push_back(g[i]);
	else
	  return false;
      }
    }
  }

  for(int i = 0;i < g.size(); i++){
    std::cout<< g[i]<<"\n";
  }
  
  /**
  // GRAMATICA 1
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
  **/
}
