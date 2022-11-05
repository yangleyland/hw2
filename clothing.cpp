#include "clothing.h"

using namespace std;

/**
  * Returns the appropriate keywords that this product should be associated with
  */
std::set<std::string> Clothing::keywords() const{
  std::set<std::string> nameset = parseStringToWords(getName());
  std::set<std::string> brandset = parseStringToWords(brand);
  for (std::set<std::string>::iterator it=brandset.begin();it!=brandset.end();++it)
  {
    nameset.insert(*it);
  }
  return nameset;
}

Clothing::Clothing (std::string size_,std::string brand_,const std::string category, const std::string name, double price, int qty):
  Product(category,name,price,qty)
{
  size=size_;
  brand=brand_;
}
Clothing::~Clothing()
{}

void Clothing::dump(std::ostream& os) const{
  os<<"clothing"<<endl;
  os<<getName()<<endl;
  os << setprecision(2) << fixed << getPrice()<<endl;
  os<<getQty()<<endl;
  os<<size<<endl;
  os<<brand<<endl;
}
std::string Clothing::displayString() const {
  std::string output;
  output+=getName();
  output+="\n";
  output+="Size: ";
  output+=size;
  output+=" Brand: ";
  output+=brand;
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