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

class WrapperWithCopy
{
public:
	WrapperWithCopy(const char* filename)
	{
		value = new Json::Value();

		std::ifstream is(filename);

		Json::Reader reader;
		reader.parse(is, *value);

		is.close();
	}
	WrapperWithCopy(const WrapperWithCopy& copy)
	{
		value = new Json::Value(*copy.value);
	}

	~WrapperWithCopy() { delete value; }

private:
	Json::Value* value;

};

WrapperWithCopy createWithCopy()
{
	WrapperWithCopy wrapper("../init_response.txt");
	return wrapper;
}

void func0()
{
	WrapperWithCopy wrapper = createWithCopy();
	std::cout << "Exiting func0()." << std::endl;
}

void func1()
{
  Wrapper wrapper = create();
  std::cout << "Exiting func1()." << std::endl;
}

int main()
{
  std::cout << "Start." << std::endl;
  func0();
  func1();
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

