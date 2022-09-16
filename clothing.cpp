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
	set<string> keywords = parseStringToWords(name_);
	for (set<string>::iterator it = parseStringToWords(brand_).begin(); it != parseStringToWords(brand_).end(); ++it){
		keywords.insert(*it);
	}
	return keywords;
}

string Clothing::displayString() const{
	string info;
	info += name_ + "\n";
	info += "Size: " + size_ + " Brand: " + brand_ + "\n";
	info += to_string(price_) + " " + to_string(qty_) + " left.\n";
	cout << info;
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