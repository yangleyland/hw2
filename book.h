#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <set>
#include "product.h"
#include "util.h"
class Book : public Product {

public:
  Book(std::string author_,std::string ISBN_,const std::string category, const std::string name, double price, int qty);
  ~Book ();
  //bool isMatch(std::vector<std::string>& searchTerms) const;
  std::string displayString() const;
  void dump(std::ostream& os) const;
  std::set<std::string> keywords() const;
private:
  std::string author;
  std::string ISBN;
};



#endif