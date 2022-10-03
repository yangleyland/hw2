#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "util.h"
#include "product.h"
#include "user.h"
#include <map>
#include <set>


class myDataStore : public DataStore {
public:
    ~myDataStore();
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
    void addToCart(User* u,Product* p);
    void viewCart(User* u);
    void buyCart(User* u);

    //accessors
    User* findUser(std::string username);

protected:
    std::set <Product*> productlist;
    std::set <User*> userlist;
    std::map <User*,std::vector<Product*> > userPairs;
    std::map <std::string, std::set<Product*> > keywordPairs;
};

#endif
