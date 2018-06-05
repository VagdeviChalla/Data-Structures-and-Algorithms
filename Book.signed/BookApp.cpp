//Author:VagdeviChalla
//File:BookApp.cpp
//Last Changed:08/03/2018

#include "Book.h"
#include<vector>
#include<iostream>
#include <fstream>

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};
void remove(string isbn, vector<Book>& catalog);
void search(string condition, vector<Book>& catalog);
int find(const string isbn, const vector<Book>& catalog);
void insert(Book book, vector<Book>& catalog);
int isbncompare(string isbn1, string isbn2);

const string INPUT_FILE_NAME = "commands.in";

int main()
{
	// Open the input file.
	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	vector<Book> catalog;  // book catalog
	catalog.reserve(10);

	// read the first command
	char command;
	input >> command;

	/**
	 * Loop to read commands until the end of file.
	 */
	while (!input.fail())
	{
		Book book;
		//when command is +, insert into catalog in sorted order of isbn
		if(command == '+')
		{
			cout << endl << command << "";
			input >> book;
			insert(book, catalog);
		}
		//when command is -, remove a book from the catalog
		else if(command == '-')
		{
			string isbn;
			input >> isbn;
			cout << endl << command << "";
			remove(isbn, catalog);
		}	
		//when command is ?, query the data using the given attributes
		else if(command == '?')
		{
			cout << endl << command << "";
			string condition;
			getline(input, condition);
			search(condition, catalog);
		}
		else
		{
			cout << endl << command << "";
			cout << " *** Invalid command ***" << endl;
			string str;
			input >> str;
		}
		input >> command;
	}
	return 0;
}
//inserting book
void insert(Book book, vector<Book>& catalog)
{
	bool insert = false;
	vector<Book>::iterator it;
	int size = catalog.size();
	int i;
	// insert at first position
	if(catalog.size() == 0)
	{
		catalog.push_back(book);
		cout << " Inserted at index 0: ";
		cout << book << endl;
		insert = true;
	}
	else
	{
		for(i = 0, it = catalog.begin(); i < size ; it++, i++)
		{
			//compare two isbn's
			int k = isbncompare(book.getIsbn(), catalog[i].getIsbn());
			if(k == 0)
			{
				cout << " Inserted at index " << i <<": ";
				cout << book << endl;
				cout << "*** Duplicate ISDN ***" << endl;
				insert = true;
				break;
			}	
			else if(k == -1)
			{
				catalog.insert(catalog.begin()+i, book);
				cout << " Inserted at index " << i <<": ";
				cout << book << endl;
				insert = true;
				break;
			}
		}
		//insert at last
		if(insert == false)
		{
			catalog.push_back(book);
			cout << " Inserted at index " << i << ": ";
			cout << book << endl;
		}

	}

}
//removing a book
void remove(string isbn, vector<Book>& catalog)
{
	Book b;
	b.setIsbn(isbn);
	
	int indexnum = find(isbn, catalog);

	if(indexnum != -1)
	{
		cout << " Removed " << catalog[indexnum] << endl;
		catalog.erase(catalog.begin() + indexnum);
	}
	else
	{
		cout << " Removed " << b << endl;
		cout << "*** Book not found ***" << endl;
	}
}
//searching
void search(string c, vector<Book>& catalog)
{
	if(c == "" || c == " ")
	{
		cout << " All books in the catalog:" << endl;
		int len = catalog.size();
		for(int i = 0; i < len ; i++)
		{
			cout << catalog[i] << endl;
		}
	}
	else
	{
		string resource;
		string data;
		int n = c.length();
		for(int i = 0; i < n ; i++)
		{
			if (c[i] == '=')
			{
				resource = c.substr(1, i-1);
				data = c.substr(i+1, n);
				break;
			}
		}

	   if(resource=="isbn")
		{
			cout << " Book with ISBN " << data << ":" << endl;

			int index = find(data, catalog);
			if(index != -1)
			{
				cout << catalog[index] << endl;
			}

		}
		else if(resource == "category")
		{
			cout << " Books in category " << data << ":" << endl;
			Book::Category cat;
			if(data == "history")
			{
				cat = Book::Category::HISTORY;
			}
			else if(data == "fiction")
			{
				cat = Book::Category::FICTION;
			}
			else if(data == "technical")
			{
				cat = Book::Category::TECHNICAL;
			}
			else
			{
				cat = Book::Category::NONE;
			}
			for(int i = 0; i < 6; i++)
			{
				if(cat == catalog[i].getCategory())
				{
					cout << catalog[i] << endl;
				}
			}
		}	
		else if(resource=="author")
		{
			cout << " Books by author " << data << ":" << endl;
			for(int i = 0; i < 6; i++)
			{
				if(catalog[i].getLast() == data)
				{
					cout << catalog[i] << endl;
				}
			}
		}
	}
}

int isbncompare(string isbn1, string isbn2)
{
   int str1_int,str2_int;
	for(int i = 0; i < isbn1.length(); i++)
	{
		if(isbn1[i] == '-')
		{
			str1_int = stoi(isbn1.substr(i+1, isbn1.length()));
		}
		if(isbn2[i] == '-')
		{
			str2_int = stoi(isbn2.substr(i+1, isbn2.length()));
			break;
		}
	}
	
	if(str1_int < str2_int)
	{
		return -1;
	}
	else if(str1_int > str2_int)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int find(const string isbn, const vector<Book>& catalog)
{
	int min = 0;
	int max = catalog.size();

	while(min <= max)
	{
		int mid = (min + max)/2;
		if (isbncompare(isbn, catalog[mid].getIsbn()) > 0)
		{
			min = mid + 1;
		}
		else if(isbncompare(isbn, catalog[mid].getIsbn()) == 0 )
		{
			return mid;
		}
		else
		{
			max = mid - 1;
		}
	}
	return -1;
}