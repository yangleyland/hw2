#include "book.h"

using namespace std;

/**
  * Returns the appropriate keywords that this product should be associated with
  */
std::set<std::string> Book::keywords() const{
  std::set<std::string> nameset = parseStringToWords(getName());
  std::set<std::string> authorset = parseStringToWords(author);
  for (std::set<std::string>::iterator it=authorset.begin();it!=authorset.end();++it)
  {
    nameset.insert(*it);
  }
  nameset.insert(ISBN);

  return nameset; //redo this

}

Book::Book (std::string author_,std::string ISBN_,const std::string category, const std::string name, double price, int qty):
  Product(category,name,price,qty)
{
  author=author_;
  ISBN=ISBN_;
}

Book::~Book()
{}

void Book::dump(std::ostream& os) const{
  os<<"book"<<endl;
  os<<getName()<<endl;
  os<<getPrice()<<endl;
  os<<getQty()<<endl;
  os<<ISBN<<endl;
  os<<author<<endl;
}

std::string Book::displayString() const {
  std::string output;
  output+=getName();
  output+="\n";
  output+="Author: ";
  output+=author;
  output+=" ISBN: ";
  output+=ISBN;
  output+="\n";
  std::string str = std::to_string (getPrice());
  str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
  str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
  output+=str;
  output+=" ";
  output+=to_string(getQty());
  output+=" left.";
  output+="\n";
  return output;
}