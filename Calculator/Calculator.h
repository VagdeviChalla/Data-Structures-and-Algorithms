//Author:Vagdevi Challa
//SJSU ID:012524707
//Assignment no:10
//Filename:Calculator.h
//Description:Calculator with mutual recursion
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
using namespace std;

class Calculator {
public:
	//constructors
	Calculator();
	Calculator(char e);

	//getter function for result
	double getresult();

	//setter function for result
	void setresult(double Result);

	//Reset all values when execution of new expression started
	void reset();

	// To evaluate Expression
	double expression(string& input);

	//Evaluates Term
	double term(string& input);

	//To Evaluate factor
	double factor(string& input);

	//To evaluate number
	string number(string n);

	char get_value() const;

private:
	int i;
	char errormsg;
	double result;
};

//Error for unexpected strings
class Unexpectederror: public Calculator {
public:
	Unexpectederror(char e) :
			Calculator(e) {
	}
	;
};
//Error if division by zero occurs
class DivisionByZero: public Calculator {
public:
	DivisionByZero() :
			Calculator() {
	}
	;
};
//Error for missing braces
class Missingbraces: public Calculator {
public:
	Missingbraces(char e) :
			Calculator(e) {
	}
	;
};
#endif
