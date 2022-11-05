#include <iostream>
#include "book.h"
#include "util.h"
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn) : 
	Product(category, name, price, qty){
	author_ = author;
	isbn_ = isbn;
}

set<string> Book::keywords() const{
	set<string> keywords = parseStringToWords(convToLower(name_));
	set<string> authorWords = parseStringToWords(convToLower(author_));
	keywords = setUnion(keywords, authorWords);
	keywords.insert(isbn_);
	return keywords;
}

string Book::displayString() const{
	string info;
	info += name_ + "\n";
	info += "Author: " + author_ + " ISBN: " + isbn_ + "\n";
	string price = to_string(price_);
	info += price.substr(0, price.length() - 4) + " " + to_string(qty_) + " left.\n";
	return info;
}

void Book::dump(std::ostream& os) const{
	//string info;
	os << category_ + "\n";
	os << name_ + "\n";
	os << to_string(price_) + "\n";
	os << to_string(qty_) + "\n";
	os << isbn_ + "\n";
	os << author_ + "\n";
	//cout << info;
	return;
}