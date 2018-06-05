//Filename:BigPi.cpp
//Author:Challa Vagdevi
//AssignmentNumber:4
//Description:printing pi value upto 1000 decimal places
//Last changed:22/02/2018

#include <iostream>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
using namespace std::chrono;


int main (void){

	const int PLACES         = 1000;        // desired decimal places
	const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal
	const int BASE       = 10;  // base 10 numbers
	const int BLOCK_SIZE = 10;                // print digits in blocks
	const int LINE_SIZE  = 100;               // digits to print per line
	const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
	const int GROUP_SIZE = 5;
	steady_clock::time_point begin;

	steady_clock::time_point end;
	begin=steady_clock::now();

    //calculating a0 and y0
	mpf_set_default_prec(1000*8);
	mpf_t sqrt,mul,sub,variable1,variable2,variable3,variable4,y;
	mpf_init(variable1);
	mpf_init(variable2);
	mpf_init(variable3);
	mpf_init(variable4);
	mpf_init(sqrt);
	mpf_init(mul);
	mpf_init(sub);
	mpf_init(y);
	//calculating a0,y0
	mpf_set_str(variable1,"2",10);
	mpf_set_str(variable2,"4",10);
	mpf_set_str(variable3,"6",10);
	mpf_set_str(variable4,"1",10);
	mpf_sqrt(sqrt,variable1);
	mpf_mul(mul,sqrt,variable2);
	mpf_sub(sub,variable3,mul);
	mpf_sub(y,sqrt,variable4);

	//variables used for calculating yi value and initializing them
	mpf_t fourthpow,fourthroot,subm,sqrt1,up,down,div;
	mpf_init(fourthpow);
	mpf_init(subm);
	mpf_init(sqrt1);
	mpf_init(fourthroot);
	mpf_init(up);
	mpf_init(down);
	mpf_init(div);

    //variables used for calculating ai value and initializing them
	mpf_t at1,fourthpowat1,ftmul,at2,sqy,stmul,sadd,ipow,ipi,pi;
	mpf_init(at1);
	mpf_init(fourthpowat1);
	mpf_init(ftmul);
	mpf_init(at2);
	mpf_init(sqy);
	mpf_init(stmul);
	mpf_init(sadd);
	mpf_init(ipow);
	mpf_init(ipi);
	mpf_init(pi);
	mpf_init(ipow);

	//looping for 1000 iterations
	for(int  k=0;k<1000;k++){

		mpf_pow_ui(fourthpow,y,4);
		mpf_sub(subm,variable4,fourthpow);
		mpf_sqrt(sqrt1,subm);
		mpf_sqrt(fourthroot,sqrt1);
		mpf_sub(up,variable4,fourthroot);
		mpf_add(down,variable4,fourthroot);
		mpf_div(y,up,down);
		mpf_add(at1,variable4,y);
		mpf_pow_ui(fourthpowat1,at1,4);
		mpf_mul(ftmul,sub,fourthpowat1);
		mpf_pow_ui(sqy,y,2);
		mpf_add(sadd,y,sqy);
		mpf_add(sadd,sadd,variable4);

		int i;
		i=2*k+3;
		mpf_pow_ui(ipow,variable1,i);
		mpf_mul(stmul,sadd,y);
		mpf_mul(stmul,stmul,ipow);
		mpf_sub(sub,ftmul,stmul);
  }
	mpf_div(pi,variable4,sub);
	//calculating elapsed time
	end=steady_clock::now();
	//duration<double>time_span =duration_cast<duration<double> >(end-begin);
	//duration<double> time = duration_cast<duration<double>> ( end - begin );
	std::chrono::duration<double> elapsed=end-begin;
	//Printing pi value
	//converting to pi to string
	gmp_printf("pi to 1000 decimal places :\n");
	cout << endl;
	mp_exp_t no_use;
	    // Convert the multiple-precision number x to a C string.
	    char *string = NULL;
	    char *s = mpf_get_str(string, &no_use, BASE, PRECISION, pi);
	    char *var = s+1;
	    cout << endl;
	    cout << *s << ".";
	    char b[BLOCK_SIZE + 1];
	    for (int i = 1; i <= LINE_COUNT; i++)
	    {
	        //print digits in block
	        for (int j = 0; j < LINE_SIZE; j += BLOCK_SIZE)
	        {
	            strncpy(b, var+j, BLOCK_SIZE);
	            //b[BLOCK_SIZE] = '\0';
	            cout << b << " ";
	        }
	        cout << endl << "  ";
	        // grouping
	        if (i%GROUP_SIZE == 0) cout << endl << "  ";
	        var += LINE_SIZE;
	    }
   cout << "Elapsed time is:" << elapsed.count() <<" seconds" << endl;
   return 0;
}
