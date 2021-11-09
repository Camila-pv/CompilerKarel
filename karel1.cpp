
void identifier(std::string s){
  std::map<std::string,std::string> mymap;
  std::map<std::string,std::string>::iterator it;

  mymap["Keyword"] = "([\\s]*)(DEFINE-NEW-INSTRUCTION)([\\s]*)|([\\s]*)(AS)([\\s]*)|([\\s]*)(IF)([\\s]*)|([\\s]*)(THEN)([\\s]*)|([\\s]*)(ELSE)([\\s]*)|([\\s]*)(ITERATE)([\\s]*)|([\\s]*)(WHILE)([\\s]*)|([\\s]*)(TIMES)([\\s]*)";
  
  mymap["Instructions"] = "([\\s]*)(move)|([\\s]*)(turnleft)|([\\s]*)(turnoff)|([\\s]*)(putbeeper)|([\\s]*)(pickbeeper)";
  
  mymap["Delimiter"] = "([\\s]*)(BEGIN-OF-PROGRAM)([\\s]*)|([\\s]*)(BEGIN-OF-EXECUTION)|([\\s]*)(END)|([\\s]*)(BEGIN)|([\\s]*)(END-OF-PROGRAM)|([\\s]*)(END-OF-EXECUTION)";

  mymap["Proposition"] = "([\\s]*)(next-to-a-beeper)|([\\s]*)(not-next-to-a-beeper)|([\\s]*)(facing-east)|([\\s]*)(not-facing-east)|([\\s]*)(facing-south)|([\\s]*)(not-facing-south)|([\\s]*)(facing-north)|([\\s]*)(not-facing-north)|([\\s]*)(facing-west)|([\\s]*)(not-facing-west)";

  mymap["Number"] = "([\\s]*)([0-9]+)([\\s]*)";
 

  if (regex_match (s, std::regex("([\\s]*)([a-z]*)(;)([\\s]*)") )){
    std::cout << "string: ;"<<"  => Separator\n";
    while(s[s.size()-1] != ';')
      s.pop_back();
    s.pop_back();
    identifier(s);
  }else{
    std::string space = " ";
    std::vector<std::string>words{};
    int pos = 0;
    while((pos = s.find(space)) != std::string::npos){
      words.push_back(s.substr(0,pos));
      s.erase(0,pos+space.length());
    }
    words.push_back(s.substr(0,pos-1));
    
    
    int p = 0;
    while(p != words.size()){
      for(int i = 0; i < words.size() ; i++){
	p++;
	for(it = mymap.begin(); it != mymap.end(); it++){
	  if(regex_match (words[i], std::regex(it->second)))
	    std::cout << "string:" << words[i]<< " => "<< it->first << "\n";
	}
      }
    }
  }
}
