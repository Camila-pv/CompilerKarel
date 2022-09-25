#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <vector>


bool gramatica(std::vector<std::string> &myvec);
bool gram_start(std::vector<std::string> myvec);
bool gram_program(std::vector<std::string> myvec);
bool identif_ins(std::vector<std::string> myvec);
bool instruction(std::string instruc);

/**
 GRAMATICA KAREL
| start → BEGINNING−OF−PROGRAM program END−OF−PROGRAM
| program → BEGINNING−OF−EXECUTION instruction  END−OF−EXECUTION
| instruction → TURNON | MOVE | TURNLEFT | PICKBEEPER | PUTBEEPER | TURNOFF 
**/

int main(){
  std::vector<std::string> myvec;
  int n = 0; 
  
  std::fstream newfile;
  //Leer el programa fuente
  newfile.open("ejemplo.txt",std::ios::in); //Abrir el archivo
  if (newfile.is_open()){ //Verificar que el archivo este abierto
    std::string tp;
    while(getline(newfile, tp)){  //Leer el archivo y ponerlo en string
      if(std::regex_match(tp, std::regex("([\\s]*)")))
	n++;
      else
	myvec.push_back(tp);//Guardar cada linea de codigo
    }
      newfile.close();   //Cerrar el archivo
   }

   for(int i = 0; i < myvec.size(); i++)
     std::cout<< myvec[i]<<"\n";

   if(gramatica(myvec))
     std::cout << "Bien/n";
   else
     std::cout << "Mal/n";

    return 0;
}



// LLama a la función gram_start y le pasa el vector
bool gramatica(std::vector<std::string> &myvec){
  return gram_start(myvec2);
}



// Identifica BEGINNING-OF-PROGRAM y END-OF-PROGRAM
// Luego llama a la función gram_program si sigue la ejecucion del programa
bool gram_start(std::vector<std::string> myvec){
  std::vector<std::string> myvec2;
  if(std::regex_match(myvec[0], std::regex("(BEGINNING-OF-PROGRAM)([\\s]*)")) && std::regex_match(myvec[myvec.size()-1],std::regex("(END-OF-PROGRAM)([\\s]*)"))){
    /////////////CREAR FUNCION GENERADOR DE SUBVECTORES
    for(int i = 1; i < myvec.size()-1; i++)
      myvec2.push_back(myvec[i]);
    myvec = myvec2;
    if(std::regex_match(myvec[0], std::regex("([\\s]*)(BEGINNING−OF−EXECUTION)([\\s]*)")))
      return gram_program(myvec);
    else
      return gram_definition(myvec);
  }else{
    return false;
  }
}


// Identifica BEGINNING-OF-EXECUTION y END-OF-EXECUTION
bool gram_program(std::vector<std::string> &myvec){
  std::vector<std::string> myvec2;
  if(std::regex_match(myvec[0], std::regex("([\\s]*)(BEGINNING−OF−EXECUTION)([\\s]*)")) && std::regex_match(myvec[myvec.size()-1],std::regex("([\\s]*)(END-OF-EXECUTION)([\\s]*)"))){
    for(int i = 1; i < myvec.size()-1; i++)
      myvec2.push_back(myvec[i]);
    myvec = myvec2;
    return identif_ins(myvec2);
  }
  return false;
}

bool identif_ins(std::vector<std::string> &myvec){
  std::vector<std::string> myvec2;
  int size = myvec2.size();
  int count = 0;
  if(instruction(myvec2[count]) && count != size-1)
    count++;
  else
    return false;
  return true;
}

//Identifica las instrucciones y su terminacion en ;
bool instruction(std::string instruc){
  if(std::regex_match(instruc,std::regex("([\\s]*)(move)([\\s]*)(;)([\\s]*)|([\\s]*)(turnleft)([\\s]*)(;)([\\s]*)|([\\s]*)(pickbeeper)([\\s]*)(;)([\\s]*)|([\\s]*)(putbeeper)([\\s]*)(;)([\\s]*)|([\\s]*)(turnoff)([\\s]*)"))){
    return true;
  }
  return false;
}


////////////   PREGUNTAS ////////////////////
// Existe turnon en las instrucciones?
