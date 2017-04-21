#include <iostream>
#include <fstream>

#include "json/json.h"


int main()
{
  Json::Value *json = new Json::Value();
  Json::Reader reader;

  std::cout << "Opening file..." << std::endl;
  std::ifstream is("../init_response.txt");

  std::cout << "Parsing file contents..." << std::endl;
  reader.parse(is, *json);

  std::cout << "Closing file..." << std::endl;
  is.close();

  std::cout << "JSON contents..." << std::endl;
  Json::ValueConstIterator iter;
  for (iter = json->begin(); iter != json->end(); ++iter)
  {
    std::cout << "..." << iter.key() << std::endl;
  }

  std::cout << "Deleting json..." << std::endl;
  delete json;

  return 0;
}

