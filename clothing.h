#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"

class Clothing : public Product{
	public:
		Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size);
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os) const;
	private:
		std::string brand_;
		std::string size_;
};

#endif