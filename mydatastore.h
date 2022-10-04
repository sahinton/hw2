#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <map>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"



class MyDataStore : public DataStore {
	public:
		MyDataStore();
		~MyDataStore();
		void addProduct(Product* p);
		void addUser(User* u);
		std::vector<Product*> search(std::vector<std::string>& terms, int type);
		void dump(std::ostream& ofile);
		void addToCart(std::string, Product* P);
		void viewCart(std::string username);
		void buyCart(std::string username);

	private:
		std::vector<Product*> products_;
		std::map<std::string, User*> users_;
		std::map<std::string, std::vector<Product*>> cart_;
		std::map<std::string, std::set<Product*>> keywordProducts_;

};




#endif