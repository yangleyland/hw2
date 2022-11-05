#ifndef CLOTHING_H
#define CLOTHING_H
#include <string>
#include <iostream>
#include <set>
#include <iomanip>
#include <sstream>
#include "product.h"
#include "util.h"
class Clothing : public Product {
  std::string size;
  std::string brand;
public:
  Clothing(std::string size_,std::string brand_,const std::string category, const std::string name, double price, int qty);
  ~Clothing ();
  void dump(std::ostream& os) const;
  std::string displayString() const;

  std::set<std::string> keywords() const;
};



#endif