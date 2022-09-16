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
	set<string> keywords = parseStringToWords(name_);
	for (set<string>::iterator it = parseStringToWords(genre_).begin(); it != parseStringToWords(genre_).end(); ++it){
		keywords.insert(*it);
	}
	return keywords;
}

string Movie::displayString() const{
	string info;
	info += name_ + "\n";
	info += "Genre: " + genre_ + " Rating: " + rating_ + "\n";
	info += to_string(price_) + " " + to_string(qty_) + " left.\n";
	cout << info;
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