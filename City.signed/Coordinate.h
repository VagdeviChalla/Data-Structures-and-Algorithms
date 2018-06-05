//Filename:Coordinate.h
//Author:Challa Vagdevi
//AssignmentNumber:7
//Description:US Maps
//Last changed:22/03/2018

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate
{
public:

	Coordinate();

	Coordinate(double latitude, double longitude);

	double get_latitude() const;

	double get_longitude() const;
    /**
     * Overloaded input stream extraction operator
     * to read a coordinate from an input stream.
     * @param ins the input stream.
     * @param coordinate the coordinate to read.
     * @return the input stream.
     */
    friend istream& operator >>(istream& ins, Coordinate& coordinate);


    // Constants for this app's input data.
    static const double MAX_LATITUDE;

    static const double MIN_LONGITUDE;

private:
    double latitude;
    double longitude;
};

#endif /* COORDINATE_H_ */
