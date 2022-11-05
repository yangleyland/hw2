#include "mydatastore.h"

using namespace std;

myDataStore::~myDataStore() {
    for (std::set <Product*>::iterator it=productlist.begin();it!=productlist.end();++it)
    {
        delete *it;
    }
    for (std::set <User*>::iterator it=userlist.begin();it!=userlist.end();++it)
    {
        delete *it;
    }
}

void myDataStore::addProduct(Product* p) {
    productlist.insert(p);
    std::set<std::string> keywordString=p->keywords();
    for (std::set<std::string>::iterator it=keywordString.begin(); it!=keywordString.end();++it)
    {
        if (keywordPairs.find(*it)!=keywordPairs.end())
        {
            keywordPairs[*it].insert(p);
        }
        else{
            set <Product*> temp;
            temp.insert(p);
            keywordPairs.insert({*it,temp});
        }
    }
}
void myDataStore::addUser(User* u) {
    userlist.insert(u);
    std::vector<Product*> emptyset;
    userPairs.insert({u,emptyset});
}
std::vector<Product*> myDataStore::search(std::vector<std::string>& terms, int type) {
    //for each term, get a set
    //intersect each set accordingly
    //iterate through each Product, see if terms is in the Product keywords
    std::set <Product*> finalset;
    for (std::vector<std::string>::iterator it=terms.begin(); it!=terms.end(); ++it)
    {
        std::set <Product*> tempset;
        // for (std::set<Product*>::iterator it1=productlist.begin(); it1!=productlist.end(); ++it1)
        // {
        //     std::set<std::string> temp=(*it1)->keywords();
        //     if (temp.find(*it)!=temp.end())
        //     { 
        //         tempset.insert(*it1);
        //     }
        // }
        tempset=keywordPairs[*it];
        if (type==1)
        {
            //union of two sets
            finalset=setUnion<Product*>(finalset,tempset);
        }
        else if (type==0)
        {
            if (it==terms.begin())
            {
                finalset=tempset;
            }
            else
            {
                finalset=setIntersection<Product*> (finalset, tempset);
            }
            //intersection of sets
        }
    }
    std::vector <Product*> finalvector;
    std::copy(finalset.begin(), finalset.end(), std::back_inserter(finalvector));
    //convert final set to vector then return vector
    return finalvector;
}

void myDataStore::dump(std::ostream& ofile) {
    ofile<<"<products>"<<endl;
    for (std::set <Product*>::iterator it=productlist.begin();it!=productlist.end();++it)
    {
        (*it)->dump(ofile);
    }
    ofile<<"</products>"<<endl;
    ofile<<"<users>"<<endl;
    for (std::set <User*>::iterator it=userlist.begin();it!=userlist.end();++it)
    {
        (*it)->dump(ofile);
    }
    ofile<<"</users>";
}
void myDataStore::addToCart(User* u,Product* p) {
    userPairs.find(u)->second.push_back(p);
}

void myDataStore::viewCart(User* u) {
    std::vector<Product*> usercart= userPairs.find(u)->second;
    int count=1;
    for (std::vector<Product*>::iterator it=usercart.begin(); it!=usercart.end();++it)
    {
        cout<<"Item "<<count<<endl;
        cout<<(*it)->displayString()<<endl;
        count++;
    }
}

void myDataStore::buyCart(User* u) {
    //std::vector<Product*> usercart= userPairs[u];
    std::vector<Product*>::iterator it=userPairs[u].begin();
    while (it!=userPairs[u].end())
    {
        if ((*it)->getQty()==0) {
            ++it;
        }
        else if ((*it)->getPrice()>u->getBalance()) {
            ++it;
        }
        else{
            u->deductAmount((*it)->getPrice());
            (*it)->subtractQty(1);
            it = userPairs[u].erase(it);
        }
    }
}

    User* myDataStore::findUser(std::string username) {
        for (std::set <User*>::iterator it=userlist.begin(); it!=userlist.end(); ++it)
        {
            if (username==(*it)->getName()) {
                return *it;
            }
        }
        return NULL;
    }