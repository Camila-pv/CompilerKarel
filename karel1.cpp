// Función que clasifica cada lexema con un simbolo o un error
void identifier(std::string s){
  //Se crea un mapa y apuntador del mismo, donde la llave es el simbolo y el valor es la expresión regular
  std::map<std::string,std::string> mymap;
  std::map<std::string,std::string>::iterator it;

  mymap["Keyword"] = "([\\s]*)(DEFINE-NEW-INSTRUCTION)([\\s]*)|([\\s]*)(AS)([\\s]*)|([\\s]*)(IF)([\\s]*)|([\\s]*)(THEN)([\\s]*)|([\\s]*)(ELSE)([\\s]*)|([\\s]*)(ITERATE)([\\s]*)|([\\s]*)(WHILE)([\\s]*)|([\\s]*)(TIMES)([\\s]*)";
  
  mymap["Instructions"] = "([\\s]*)(move)|([\\s]*)(turnleft)|([\\s]*)(turnoff)|([\\s]*)(putbeeper)|([\\s]*)(pickbeeper)";
  
  mymap["Delimiter"] = "([\\s]*)(BEGIN-OF-PROGRAM)([\\s]*)|([\\s]*)(BEGIN-OF-EXECUTION)|([\\s]*)(END)|([\\s]*)(BEGIN)|([\\s]*)(END-OF-PROGRAM)|([\\s]*)(END-OF-EXECUTION)";

  mymap["Proposition"] = "([\\s]*)(next-to-a-beeper)|([\\s]*)(not-next-to-a-beeper)|([\\s]*)(facing-east)|([\\s]*)(not-facing-east)|([\\s]*)(facing-south)|([\\s]*)(not-facing-south)|([\\s]*)(facing-north)|([\\s]*)(not-facing-north)|([\\s]*)(facing-west)|([\\s]*)(not-facing-west)";

  mymap["Number"] = "([\\s]*)([0-9]+)([\\s]*)";
 
  //Este if entra la linea de caracteres que terminan en ;
  if (regex_match (s, std::regex("([\\s]*)([a-z]*)(;)([\\s]*)") )){
    // Imprime el simbolo del ;
    std::cout << "string: ;"<<"  => Separator\n";
    //Borra el; 
    while(s[s.size()-1] != ';')
      s.pop_back();
    s.pop_back();

    //Se crea la variable count donde se inicializa como true paraa saber si el lexema tiene un simbolo o no.
    bool count = true;
    for(it = mymap.begin(); it != mymap.end(); it++){
	  if(regex_match (s, std::regex(it->second))){
	    std::cout << "string:" << s << " => "<< it->first << "\n";
	    count = false;
	    break;
	  }
	}
    // Si el lexema no tiene ningun simbolo, es porque hay un error de léxico
    if(count == true)
      std::cout << "Error de Lexicooooo :"<< s<<"\n";

    //En el esle entran los lexemas que no terminan en ;, es decir que pueden tener mas de un lexema en la linea leida del programa fuente.
  }else{
    //Se crea un vector para separar cada lexema, se separa por medio de un espacio en blanco
    std::string space = " ";
    std::vector<std::string>words{};
    int pos = 0;
    while((pos = s.find(space)) != std::string::npos){
      words.push_back(s.substr(0,pos));
      s.erase(0,pos+space.length());
    }
    words.push_back(s.substr(0,pos-1));
    
    //Se recorre el vector para identificar el simbolo de cada elemento del vector
    int p = 0;
    while(p != words.size()){
      for(int i = 0; i < words.size() ; i++){
	p++;
	bool prueba = true;
	//Se recorre el mapa para encontar la expresion regular
	for(it = mymap.begin(); it != mymap.end(); it++){
	  if(regex_match (words[i], std::regex(it->second))){
	    std::cout << "string:" << words[i]<< " => "<< it->first << "\n";
	    prueba = false;
	    break;
	  }
	}
	//Si no se encontro el simbolo del lexema es un Identifier y no un error porque no termina en ; y puede ser una"variable"
	if(prueba == true){
	  if(regex_match (words[i],std::regex("([\\s]*)([a-z]*)(([0-9]|[a-z]|(-)|(_))+)([\\s]*)")))
	    std::cout << "string: " << words[i] << " =>  Identifier\n";
	}
      }
    }
  }
}
