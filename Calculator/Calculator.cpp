//Author:Vagdevi Challa
//SJSU ID:012524707
//Assignment no:10
//Filename:Calculator.cpp
//Description:Calculator with mutual recursion

#include "Calculator.h"
#include <iostream>
#include <string>
#include <math.h>
#include <exception>
using namespace std;

//constructors
Calculator::Calculator() :
		i(0), errormsg(' '), result(0) {

}

Calculator::Calculator(char e) :
		errormsg(e), result(0) {

}

//method to return error message
char Calculator::get_value() const {
	return this->errormsg;
}

////Reset all values when execution of new expression started
void Calculator::reset() {
	this->i = 0;
	this->result = 0;
}

////To evaluate number
string Calculator::number(string input) {
	if (input.substr(0, 2) == "E+")
		return input.substr(0, 2) + number(input.substr(2));
	else if (input.substr(0, 2) == "E-") {
		return input.substr(0, 2) + number(input.substr(2));
	} else if (input.substr(0, 2) == "e-") {
		return input.substr(0, 2) + number(input.substr(2));
	} else if (input.substr(0, 2) == "e+") {
		return input.substr(0, 2) + number(input.substr(2));
	} else if (input[0] >= '0' && input[0] <= '9')
		return input.substr(0, 1) + number(input.substr(1));
	else if (input[0] == '.') {
		return input.substr(0, 1) + number(input.substr(1));
	} else
		return "";
}

// To evaluate Expression
double Calculator::expression(string& input) {
	double exp = 0;
	if (input.length() == 0) {
		return 0;
	}
	exp = term(input);
	if (input[0] == ' ')
		input = input.substr(1);
	if (input[0] == '+') {
		input = input.substr(1);
		exp += term(input);
	} else if (input[0] == '-') {
		input = input.substr(1);
		exp -= term(input);
	}
	if (input[0] == '%') {
		result = exp;
		throw Unexpectederror(input[0]);
	}
	if (input[0] == ')' && i <= 0) {
		throw Missingbraces(')');
	}
	return exp;
}

//getter method to result
double Calculator::getresult() {
	return result;
}
//setter method to result
void Calculator::setresult(double Result) {
	this->result = Result;
}

//Evaluates Term
double Calculator::term(string& input) {
	if (input.length() == 0)
		return 1;
	double term = 1;
	term = factor(input);
	if (input[0] == ' ')
		input = input.substr(1);
	if (input[0] == '*') {
		input = input.substr(1);
		term = term * factor(input);
	} else if (input[0] == '/') {
		input = input.substr(1);
		double f = factor(input);
		if (f == 0) {
			throw DivisionByZero();
		}
		term = term / f;
	}
	return term;
}

//To Evaluate factor
double Calculator::factor(string& input) {
	double factor = 0;
	if (input[0] == ' ') {
		input = input.substr(1);
	}
	if (input[0] == '(') {
		i++;
		input = input.substr(1);
		factor = expression(input);
		if (input[0] == ')') {
			i--;
			input = input.substr(1);
			return factor;
		} else {
			throw Missingbraces(')');
		}
	} else if (input[0] >= '0' && input[0] <= '9') {
		string str = input.substr(0, 1) + number(input.substr(1));
		input = input.substr(str.length());
		double d = stod(str);
		return d;
	} else {
		result = factor;
		throw Unexpectederror(input[0]);
	}
	return factor;
}

int main() {

	Calculator* cal = new Calculator;
	string input;
	cout << "Expression? ";
	getline(cin, input);
	while (input != ".") {
		try {
			double res = cal->expression(input);
			cal->setresult(res);
			cout << cal->getresult() << endl;
		} catch (Unexpectederror &e) {
			cout << cal->getresult() << endl;
			cout << "***** Unexpected " << e.get_value() << endl;
		} catch (DivisionByZero &e) {
			cout << "***** Division By Zero" << endl;
		} catch (Missingbraces &e) {
			cout << "***** Missing " << e.get_value() << endl;
		}
		cout << "Expression? ";
		cal->reset();
		getline(cin, input);
	}
	cout << "Done!" << endl;
	return 0;
}
