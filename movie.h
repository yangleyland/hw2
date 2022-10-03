#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
#include <set>
#include "product.h"
#include "util.h"
class Movie : public Product {
  std::string genre;
  std::string rating;
public:
  Movie(std::string genre_,std::string rating_,const std::string category, const std::string name, double price, int qty);
  ~Movie ();
  void dump(std::ostream& os) const;
  std::string displayString() const;

  std::set<std::string> keywords() const;
};
#endif