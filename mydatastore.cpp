#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "user.h"
#include "mydatastore.h"
#include "util.h"


using namespace std;

MyDataStore::MyDataStore(){ //constructor

}

MyDataStore::~MyDataStore(){
	//delete products
	for (vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
		delete *it;
	}
	//delete users
	for(map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it){
		delete it->second;
	}
}

void MyDataStore::addProduct(Product* p){
	products_.push_back(p); //add product to set of products
	set<string> keyWord = p->keywords(); //will be individual keyword
	set<string>::iterator it;
	 //iterate through keywords and insert to list of products
	for (it = keyWord.begin(); it != keyWord.end(); ++it){
		if (keywordProducts_.find(*it) == keywordProducts_.end()) {
			set<Product*> temp;
			keywordProducts_[*it] = temp;
		}
		keywordProducts_[*it].insert(p);
	}

}

void MyDataStore::addUser(User* u){
	users_[u->getName()] = u; //associate user with name
	vector<Product*> newCart;
	cart_.insert(make_pair(u->getName(), newCart)); //give them an empty cart
}

vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
	std::set<Product*> temp;
	bool first = true;
	for(vector<string>::iterator it = terms.begin(); it != terms.end(); ++it){
		if(keywordProducts_.find(*it) != keywordProducts_.end()){
			if(first == true){ //if finding item for first time
				temp = keywordProducts_[*it];
				first = false;
			}
			else{ //finding for second time
				if(type == 0){
					temp = setIntersection(temp, keywordProducts_[*it]); //add all matching terms
				}
				else if (type == 1){
					temp = setUnion(temp, keywordProducts_[*it]); //add all terms
				}
			}
		}
	}
	vector<Product*> returnProducts(temp.begin(), temp.end()); //set temp set to vector
	return returnProducts;
}


void MyDataStore::dump(std::ostream& ofile){
	ofile << "<products>" << endl;
	//iterate through products and dump
	for(vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
		(*it)->dump(ofile);
	}
	ofile << "</products>" << endl << "<users>" << endl;
	//iterate through users and dump
	for(map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it){
		it->second->dump(ofile);
	}
	ofile << "</users>" << endl;
}

void MyDataStore::addToCart(string username, Product* p){
	if (users_.find(username) == users_.end()){ //valid username check
		cout << "Invalid username" << endl;
		return;
	}
	else{
		cart_[username].push_back(p); //add item to cart
	}
}

void MyDataStore::viewCart(string username){
	if (users_.find(username) == users_.end()){ //valid username check
		cout << "Invalid Username" << endl;
		return;
	}
	else{ //display string for all items in cart
		int setSize = cart_[username].size();
		for(vector<Product*>::iterator it = cart_[username].begin(); it != cart_[username].end(); ++it){
			cout << setSize << " ";
			cout << (*it)->displayString();
			setSize--;
		}
	}
}

void MyDataStore::buyCart(string username){
	//make sure to check is username is valid
	if (users_.find(username) == users_.end()){
		cout << "Invalid Username" << endl;
		return;
	}
	vector<Product*> temp;
	for(vector<Product*>::iterator it2 = cart_[username].begin(); it2 != cart_[username].end(); ++it2){
		if((users_[username]->getBalance() >= (*it2)->getPrice()) && (*it2)->getQty() > 0){ //enough money and qty
			double cost = (*it2)->getPrice();
			users_[username]->deductAmount(cost); //remove from balance
			(*it2)->subtractQty(1); //remove 1 qty from database
		}
		else{
			temp.push_back(*it2); //if can't buy, keep item in cart
		}
	}
	if(temp.size() > 0){
		cout << "Not all items could be purchased." << endl;
		cart_[username] = temp; //change cart if unbought items
	}
	else{
		cart_[username].clear(); //delete cart if all was bought
	}
}

