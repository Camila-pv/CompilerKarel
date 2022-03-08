#include<iostream>
#include<regex>

bool gramatica(std::string g);
bool gram_start(std::string g);

/**
 GRAMATICA KAREL
 
 start → BEGINNING−OF−PROGRAM program END−OF−PROGRAM
 program → definition∗ BEGINNING−OF−EXECUTION statement∗ END−OF−EXECUTION
 definition → DEFINE−NEW−INSTRUCTION identifier AS statement 
 statement → block | iteration | loop | conditional | instruction
 block → BEGIN statement∗ END 
 iteration → ITERATE number TIMES statement
 loop → WHILE condition DO statement
 conditional → IF condition THEN statement (ELSE statement)?
 instruction → TURNON | MOVE | TURNLEFT | PICKBEEPER | PUTBEEPER | TURNOFF | identifier 
 condition → FRONT−IS−CLEAR | FRONT−IS−BLOCKED | LEFT−IS−CLEAR | LEFT−IS−BLOCKED
            | RIGHT−IS−CLEAR | RIGHT−IS−BLOCKED | BACK−IS−CLEAR | BACK−IS−BLOCKED
            | NEXT−TO−A−BEEPER | NOT−NEXT−TO−A−BEEPER | ANY−BEEPERS−IN−BEEPER−BAG
            | NO−BEEPERS−IN−BEEPER−BAG | FACING−NORTH | NOT−FACING−NORTH
            | FACING−SOUTH | NOT−FACING−SOUTH | FACING−EAST | NOT−FACING−EAST
            | FACING−WEST | NOT−FACING−WEST
 identifier → [ a−z ] ( [ a−z ] | [0−9]+ )∗
 number → [0−9]+

**/

int main(){
    std::string g = "BEGINNING-OF-PROGRAM turnleft; ITERATE 9 TIMES ED-OF-PROGRAM";
    if(gramatica(g))
    std::cout << "Verdadero " << gramatica(g) << std::endl;
  else
    std::cout << "Falso " << gramatica(g) << std::endl;
    
    return 0;
}

bool gramatica(std::string g){
    return gram_start(g);
}


bool gram_start(std::string g){
    if(std::regex_match(g, std::regex("(BEGINNING-OF-PROGRAM)(([\\s])*([A-Za-z])*([0-9])*(;)*)*(END-OF-PROGRAM)")))
        return true;
    else
        return false;
}