
void identifier(std::string s){
  if (regex_match (s, std::regex("BEGIN-OF-PROGRAM") ))
    std::cout << "string: "<< s <<"  => identifier\n"<<"\n";
   
  if (regex_match (s, std::regex("move") ))
    std::cout << "string: "<< s<< " => keyword\n"<<"\n";
  else
    std::cout << s<<"\n";
}
  
  /**
   if (regex_match ("BEGIN-OF-PROGRAM", regex("BEGIN-OF-PROGRAM") ))
      cout << "string:literal => identifier\n";
   else
     cout<< "No identifier";
   
   if (regex_match ("DEFINE-NEW", regex("DEFINE NEW") ))
      cout << "string:literal => keyword\n";
   else
     cout<< "No Keyword";
  **/
  /**
   if (regex_match ("BEGIN-OF-PROGRAM", regex("([0-9]+|a)(.*)(M)") ))
      cout << "string:literal => matched\n";
   else
     cout<< "No matched";
  **/
   // const char mystr[] = "SoftwareTestingHelp";
   // string str ("software");
   // regex str_expr ("(soft)(.*)");
 
   // if (regex_match (str,str_expr))
   //    cout << "string:object => matched\n";
 
   // if ( regex_match ( str.begin(), str.end(), str_expr ) )
   //    cout << "string:range(begin-end)=> matched\n";
 
   // cmatch cm;
   // regex_match (mystr,cm,str_expr);
    
   // smatch sm;
   // regex_match (str,sm,str_expr);
    
   // regex_match ( str.cbegin(), str.cend(), sm, str_expr);
   // cout << "String:range, size:" << sm.size() << " matches\n";
 
   
   // regex_match ( mystr, cm, str_expr, regex_constants::match_default );
 
   // cout << "the matches are: ";
   // for (unsigned i=0; i<sm.size(); ++i) {
   //    cout << "[" << sm[i] << "] ";
   // }
 
   // cout << endl;
 
 
