#include <iostream>
#include <fstream>

#include "json/json.h"

class Wrapper
{
  public:
    Wrapper(const char* filename)
    {
      value = new Json::Value();

      std::ifstream is(filename);

      Json::Reader reader;
      reader.parse(is, *value);

      is.close();
    }

    ~Wrapper() { delete value; }

  private:
    Json::Value* value;

};

Wrapper create()
{
  Wrapper wrapper("../init_response.txt");
  return wrapper;
}

void func()
{
  Wrapper wrapper = create();
  std::cout << "Exiting func()." << std::endl;
}

int main()
{
  std::cout << "Start." << std::endl;
  func();
  std::cout << "End." << std::endl;

//  std::cout << "JSON contents..." << std::endl;
//  Json::ValueConstIterator iter;
//  for (iter = json->begin(); iter != json->end(); ++iter)
//  {
//    std::cout << "..." << iter.key() << ", value: " << *iter << std::endl;
//    Json::Value item = json->get(iter.key().asString(), Json::nullValue);
//    Json::ValueConstIterator item_iter;
//    for (item_iter = item.begin(); item_iter != item.end(); ++item_iter)
//    {
//      std::cout << "......" << item_iter.key() << ", value: " << *item_iter << std::endl;
//    }
//  }

  return 0;
}

