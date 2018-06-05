//Filename:RomanNumeral.cpp
//Author:Challa Vagdevi
//AssignmentNumber:5
//Description:Arithmetic operations on romanNumerals
//Last changed:28/02/2018

#include <iostream>
#include <fstream>
#include <string>
#include "RomanNumeral.h"

using namespace std;
//Default Constructor
RomanNumeral::RomanNumeral() : decimal(0), roman(""){
//empty
}
//constructor with integer argument
RomanNumeral::RomanNumeral(int d): decimal(d){
   to_roman(d);
}
//constructor with string argument
RomanNumeral::RomanNumeral(string r): roman(r){
   to_decimal(r);
}
//convert decimal to roman
void RomanNumeral::to_roman(int d){
	roman="";
	if(d/1000 >0){
		int n=d/1000;
		for(int i=1;i<=n;i++){
			roman=roman+'M';
		}
		d=d%1000;
	}else d=d%1000;
	if(d/100 >0){
		int n=d/100;
		if(n>=5 && n<9){
		  for(int i=5;i<=n;i++){
			  if(i==5){
				  roman=roman+'D';
			  }else{
				  roman=roman+'C';
			  }
		  }
		}else if(n<4){
			for(int i=1;i<=n;i++){
			  roman = roman+'C';
			}
		}else if(n==4){
			  roman = roman + "CD";
		}else if(n==9){
			  roman = roman + "CM";
		}
		d=d%100;
	}else d=d%100;
	if(d/10 >0){
		int n=d/10;
		if(n>=5 && n<9){
		  for(int i=5;i<=n;i++){
			  if(i==5){
				  roman=roman+'L';
			  }else{
				  roman=roman+'X';
			  }
		  }
		}else if(n<4){
			for(int i=1;i<=n;i++){
			  roman = roman+'X';
			}
		}else if(n==4){
			  roman = roman + "XL";
		}else if(n==9){
			  roman = roman + "XC";
		}
		d=d%10;
  }	else d=d%10;
  if(d >0){
		int n=d;
		if(n>=5 && n<9){
		  for(int i=5;i<=n;i++){
			  if(i==5){
				  roman=roman+'V';
			  }else{
				  roman=roman+'I';
			  }
		  }
		}else if(n<4){
			for(int i=1;i<=n;i++){
			  roman = roman+'I';
			}
		}else if(n==4){
			  roman = roman + "IV";
		}else if(n==9){
			  roman = roman + "IX";
		}
}

}

//converting roman to decimal
void RomanNumeral::to_decimal(string s){
	 decimal=0;
	 for (int i=0; i<s.length(); i++){
			int d1 = value(s[i]);
			int d2=value(s[i+1]);
			if(d1>d2 || d1==d2){
				decimal=decimal+d1;
			}else if(d1<d2){
				decimal=decimal+d2-d1;
				i++;
			}
		}
}

//getter function to get decimal value
int RomanNumeral::get_decimal() const{
   return decimal;
}
//getter function to get roman value
string RomanNumeral::get_roman() const{
   return roman;
}
//fetching decimal from roman
int RomanNumeral::value(char r)
{
	int decimalval;
    if (r == 'I')
    	decimalval = 1;
    if (r == 'V')
    	decimalval = 5;
    if (r == 'X')
    	decimalval = 10;
    if (r == 'L')
    	decimalval = 50;
    if (r == 'C')
    	decimalval = 100;
    if (r == 'D')
    	decimalval = 500;
    if (r == 'M')
    	decimalval = 1000;

    return 	decimalval;
}
//friend functions for stream insertion and stream extraction operators overloading
ostream& operator <<(ostream& out, const RomanNumeral& r1){
   out <<"[" <<r1.decimal<<":"<<r1.roman<<"]";
   return out;
}
istream& operator >>(istream& in, RomanNumeral& r1){
   string str3;
   in>>str3;
   r1.roman=str3;
   r1.to_decimal(r1.roman);
   return in;
}
//friend functions for equality operators overloading
bool operator ==(const RomanNumeral& r1,const RomanNumeral& r2){
   if(r1.decimal == r2.decimal){
         return true;
      }
   else return false;
}

bool operator !=(const RomanNumeral& r1,const RomanNumeral& r2){
   if(r1.decimal != r2.decimal){
         return true;
      }
   else return false;
}
//friend functions for arithmetic operators overloading
RomanNumeral operator +(const RomanNumeral& r1,const RomanNumeral& r2){

	 RomanNumeral addResult(0);
     addResult.decimal=r1.decimal+r2.decimal;
     addResult.to_roman(addResult.decimal);
     return addResult;
}

 RomanNumeral operator -(const RomanNumeral& r1,const RomanNumeral& r2){

     RomanNumeral subResult(0);
     subResult.decimal=r1.decimal-r2.decimal;
     subResult.to_roman(subResult.decimal);
     return subResult;
}

 RomanNumeral operator *(const RomanNumeral& r1,const RomanNumeral& r2){

	 RomanNumeral mulResult(0);
	 mulResult.decimal=r1.decimal*r2.decimal;
	 mulResult.to_roman(mulResult.decimal);
     return mulResult;
}

   RomanNumeral operator /(const RomanNumeral& r1,const RomanNumeral& r2)
{
     RomanNumeral divResult(0);
     divResult.decimal=r1.decimal/r2.decimal;
     divResult.to_roman(divResult.decimal);
     return divResult;
}




