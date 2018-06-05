//Filename:City.h
//Author:Challa Vagdevi
//AssignmentNumber:7
//Description:US Maps
//Last changed:22/03/2018

#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>
#include <vector>

#include "Coordinate.h"

using namespace std;

/**
 * City data.
 */
class City
{
public:

    /***** Complete this class. *****/
    //constructors
	 City();

	 City(string name, string state, Coordinate coordinate);

    //destructors
    ~City();

	/**
     * Overloaded input stream operator to read a city
     * from an input stream.
     * @param ins the input stream.
     * @param city the city to read.
     * @return the input stream.
     */
    friend istream& operator >>(istream& ins, City& city);

    /**
     * Overloaded output stream operator to output a city
     * to an output stream.
     * @param outs the output stream.
     * @param city the city to output.
     * @return the output stream.
     */
    friend ostream& operator <<(ostream& outs, const City& city);

	 string get_name() const;

	 string get_state() const;

	 Coordinate get_coordinate() const;
private:
    string name;
    string state;
    Coordinate coordinate;
};

#endif /* CITY_H_ */
