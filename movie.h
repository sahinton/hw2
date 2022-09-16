#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"

class Movie : public Product{
	public:
		Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump();
	private:
		std::string genre_;
		std::string rating_;
};

#endif