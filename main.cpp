#include <iostream>
#include <string>
#include <regex>
#include<fstream>
#include<map>
#include"karel1.cpp"

 
int main () {

  std::fstream newfile;
  //Leer el programa fuente
  newfile.open("prueba.txt",std::ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
     std::string tp;
      while(getline(newfile, tp)){  //read data from file object and put it into string.
	//Llamar la función
        identifier(tp);  
      }
      newfile.close();   //close the file object.
   }

   return 0;
}
