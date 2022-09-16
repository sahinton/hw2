#include <iostream>
#include "book.h"
#include "util.h"
#include <set>
#include <string>
using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn) : 
	Product(category, name, price, qty){
	author_ = author;
	isbn_ = isbn;
}

set<string> Book::keywords() const{
	set<string> keywords = parseStringToWords(name_);
	for (set<string>::iterator it = parseStringToWords(author_).begin(); it != parseStringToWords(author_).end(); ++it){
		keywords.insert(*it);
	}
	keywords.insert(isbn_);
	return keywords;
}

string Book::displayString() const{
	string info;
	info += name_ + "\n";
	info += "Author: " + author_ + " ISBN: " + isbn_ + "\n";
	info += to_string(price_) + " " + to_string(qty_) + " left.\n";
	cout << info;
	return info;
}

void Book::dump(){
	string info;
	info += category_ + "\n";
	info += name_ + "\n";
	info += to_string(price_) + "\n";
	info += to_string(qty_) + "\n";
	info += isbn_ + "\n";
	info += author_ + "\n";
	cout << info;
	return;
}