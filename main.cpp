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
    std::cout << "..." << iter.key() << ", value: " << *iter << std::endl;
    Json::Value item = json->get(iter.key().asString(), Json::nullValue);
    Json::ValueConstIterator item_iter;
    for (item_iter = item.begin(); item_iter != item.end(); ++item_iter)
    {
      std::cout << "......" << item_iter.key() << ", value: " << *item_iter << std::endl;
    }
  }

  std::cout << "Deleting json..." << std::endl;
  delete json;

  Json::Value null = Json::nullValue;

  std::cout << "Null attribtes:" << std::endl;
  std::cout << "... size() - " << null.size() << std::endl;
  std::cout << "... asInt() - " << null.asInt() << std::endl;
  std::cout << ".... asString() - '" << null.asString() << "'" << std::endl;

  return 0;
}

