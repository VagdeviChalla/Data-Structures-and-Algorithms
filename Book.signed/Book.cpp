//Author:VagdeviChalla
//File:Book.cpp
//Last Changed:08/03/2018

#include "Book.h"
#include <iostream>
#include <vector>

using namespace std;

/***** Complete this file. *****/

Book::Book(): isbn(""),last(""), first(""), title("")
{
	category = Category::NONE;
}

//Constructor.
 
Book :: Book(string isbn, string last, string first, string title, Category category) : isbn(isbn),last(last), first(first), title(title),category(category)
{

}

// Destructor.
 
Book :: ~Book()
{

}

// Getter and setter functions
Book :: Category Book :: getCategory() const
{
	return category;
}

const string& Book :: getIsbn() const
{
	return isbn;
}

void Book :: setIsbn(const string& isbn)
{
	this->isbn = isbn;
}

const string& Book :: getLast() const
{
	return last;
}
//overloading << operator
ostream &operator<<( ostream &output, const Book &book)
{
	string str = ""; //variable to store category
	if(book.category == Book::Category::FICTION){
		str = "fiction";
	}
	else if(book.category == Book::Category::HISTORY){
		str = "history";
	}
	else if(book.category == Book::Category::TECHNICAL){
		str = "technical";
	}
	else{
		str = "none";
	}
	output << "Book{ISBN=" << book.isbn << ", last=" << book.last <<", first=" << book.first
			<< ", title=" << book.title << ", category=" << str << "}" ;
	return output;
}
//overloading  >> operator
istream &operator>>(istream &input, Book &book)
{
	string s1;
	getline(input, s1, ',');
	string s2;
	getline(input, s2, ',');
	string s3;
	getline(input, s3, ',');
	string s4;
	getline(input, s4, ',');
	string s5;
	getline(input, s5);

	book.isbn = s1.substr(1,s1.length());
	book.last = s2;
	book.first = s3;
	book.title = s4;

	if(s5 == "technical"){
		book.category = Book::Category::TECHNICAL;
	}
	else if(s5 == "history"){
		book.category = Book::Category::HISTORY;
	}
	else if(s5 == "fiction"){
		book.category = Book::Category::FICTION;
	}
	else{
		book.category = Book::Category::NONE;
	}

	return input;
}