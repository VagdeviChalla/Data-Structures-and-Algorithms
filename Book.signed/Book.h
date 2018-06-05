//Author:VagdeviChalla
//File:Book.h
//Last Changed:08/03/2018

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Book
{
public:
	/**
	 * Book categories.
	 */
	enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

	// Default constructor.
	
	Book();

	//Constructor.

	Book(string isbn, string last, string first, string title, Category category);
   
   //Destructor
	~Book();
	  
	// overloading operators
	friend ostream &operator<<( ostream &output, const Book &book);
	friend istream &operator>>( istream &input, Book &book);
	
	//getter and setter functions
	Category getCategory() const;
	const string& getIsbn() const;
	void setIsbn(const string& isbn);
	const string& getLast() const;

private:
   string isbn,last,first,title;
	Category category;
};

#endif /* EMPLOYEE_H_ */
