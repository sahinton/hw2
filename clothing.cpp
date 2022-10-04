#include <iostream>
#include "clothing.h"
#include "util.h"
#include <set>
#include <string>
using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size):
	Product(category, name, price, qty){
	brand_ = brand;
	size_ = size;
}

set<string> Clothing::keywords() const{
	set<string> keywords = parseStringToWords(convToLower(name_));
	set<string> brandWords = parseStringToWords(convToLower(brand_));
	keywords = setUnion(keywords, brandWords);
	return keywords;
}

string Clothing::displayString() const{
	string info;
	info += name_ + "\n";
	info += "Size: " + size_ + " Brand: " + brand_ + "\n";
	string price = to_string(price_);
	info += price.substr(0, price.length() - 4) + " " + to_string(qty_) + " left.\n";
	return info;
}

void Clothing::dump(){
	string info;
	info += category_ + "\n";
	info += name_ + "\n";
	info += to_string(price_) + "\n";
	info += to_string(qty_) + "\n";
	info += size_ + "\n";
	info += brand_ + "\n";
	cout << info;
	return;
}