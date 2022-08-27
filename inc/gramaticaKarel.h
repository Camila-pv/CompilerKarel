#include<iostream>
#include<regex>
#include<string>
/**
* @file gramaticaKarel.h
* @author Camila
* @date Agosto 27 2020
* @brief Header Implementación de gramática Karel
*/

#ifndef GRAMATICAKAREL_H
#define GRAMATICAKAREL_H 

#include <vector>
#include <string>

bool gramatica(std::vector<std::string> &myvec);
bool gram_start(std::vector<std::string> &myvec);
bool gram_program(std::vector<std::string> &myvec);
bool gram_definition(std::vector<std::string> &myvec);
bool instruction(std::string instruc);
bool condition(std::string comando);
bool identifier(std::string identi);
bool number(std::string n);

#endif
