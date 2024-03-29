#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "book.hpp"

const unsigned int MAX_L = 30;

char* load(char*, int);
double load_n();
void data(std::vector<Book*>&, std::vector<std::string*>&, std::vector<std::string*>&);
void delete_data(std::vector<Book*>&, std::vector<std::string*>&, std::vector<std::string*>&);
Book* new_book(std::vector<Book*>&);

template<typename T>
void show_vec(std::vector<T*> &vec)
{
  unsigned int i;
  for(i = 0 ; i < vec.size() ; i++)
    std::cout<<*(vec[i]);
}

#endif // functions_hpp
