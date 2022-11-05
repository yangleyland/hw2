#include "movie.h"

using namespace std;

/**
  * Returns the appropriate keywords that this product should be associated with
  */
std::set<std::string> Movie::keywords() const{
  std::set<std::string> nameset = parseStringToWords(getName());
  std::set<std::string> genreset = parseStringToWords(genre);
  for (std::set<std::string>::iterator it=genreset.begin();it!=genreset.end();++it)
  {
    nameset.insert(*it);
  }
  return nameset;
}

Movie::Movie (std::string genre_,std::string rating_,const std::string category, const std::string name, double price, int qty):
  Product(category,name,price,qty)
{
  genre=genre_;
  rating=rating_;
}
Movie::~Movie()
{}

void Movie::dump(std::ostream& os) const{
  os<<"movie"<<endl;
  os<<getName()<<endl;
  os << setprecision(2) << fixed << getPrice()<<endl;
  os<<getQty()<<endl;
  os<<genre<<endl;
  os<<rating<<endl;
}
std::string Movie::displayString() const {
  std::string output;
  output+=getName();
  output+="\n";
  output+="Genre: ";
  output+=genre;
  output+=" Rating: ";
  output+=rating;
  output+="\n";
  std::ostringstream oss;
  oss << setprecision(2) << fixed << getPrice();
  string str = oss.str();
  output+=str;
  output+=" ";
  output+=to_string(getQty());
  output+=" left.";
  output+="\n";
  return output;
}