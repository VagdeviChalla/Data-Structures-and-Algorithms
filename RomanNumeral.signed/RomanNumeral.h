//Filename:RomanNumeral.h
//Author:Challa Vagdevi
//AssignmentNumber:5
//Description:Arithmetic operations on romanNumerals
//Last changed:28/02/2018

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include<string>
using namespace std;

class RomanNumeral
{
public:
	//default empty constructor
    RomanNumeral();
    //constructor with integer argument
    RomanNumeral(int d);
    //constructor with string argument
	RomanNumeral(string r);
	//fetching decimal from roman
	int value(char r);
	//getter function to get decimal value
	int get_decimal() const;
	//getter function to get roman value
	string get_roman() const;
	//friend functions for arithmetic operators overloading
	friend RomanNumeral operator +(const RomanNumeral& r1,const RomanNumeral& r2);
	friend RomanNumeral operator *(const RomanNumeral& r1,const RomanNumeral& r2);
	friend RomanNumeral operator /(const RomanNumeral& r1,const RomanNumeral& r2);
	friend RomanNumeral operator -(const RomanNumeral& r1,const RomanNumeral& r2);
	//friend functions for equality operators overloading
	friend bool operator ==(const RomanNumeral& r1,const RomanNumeral& r2);
	friend bool operator !=(const RomanNumeral& r1,const RomanNumeral& r2);
	//friend functions for stream insertion and stream extraction operators overloading
	friend ostream& operator <<(ostream& out, const RomanNumeral& r1);
    friend istream& operator >>(istream& in, RomanNumeral& r1);
private:
   string roman;
   int decimal;
   //converting decimal to roman
   void to_roman(int d);
   //converting roman to decimal
   void to_decimal(string r);
};

#endif /* ROMANNUMERAL_H_ */
