#include <iostream>
#include "movie.h"
#include "util.h"
#include <set>
#include <string>
using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating):
	Product(category, name, price, qty){
	genre_ = genre;
	rating_ = rating;
}
set<string> Movie::keywords() const{
	set<string> keywords = parseStringToWords(convToLower(name_));
	set<string> genreWords = parseStringToWords(convToLower(genre_));
	keywords = setUnion(keywords, genreWords);
	return keywords;
}

string Movie::displayString() const{
	string info;
	info += name_ + "\n";
	info += "Genre: " + genre_ + " Rating: " + rating_ + "\n";
	string price = to_string(price_);
	info += price.substr(0, price.length() - 4) + " " + to_string(qty_) + " left.\n";
	return info;
}

void Movie::dump(){
	string info;
	info += category_ + "\n";
	info += name_ + "\n";
	info += to_string(price_) + "\n";
	info += to_string(qty_) + "\n";
	info += genre_ + "\n";
	info += rating_ + "\n";
	cout << info;
	return;
}