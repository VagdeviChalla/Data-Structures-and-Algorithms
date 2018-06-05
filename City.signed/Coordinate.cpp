//Filename:Coordinate.cpp
//Author:Challa Vagdevi
//AssignmentNumber:7
//Description:US Maps
//Last changed:22/03/2018

#include "Coordinate.h"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;


Coordinate::Coordinate():latitude(0), longitude(0) { }


Coordinate::Coordinate(double latitude, double longitude):latitude(latitude), longitude(longitude) { }



istream& operator >>(istream& ins, Coordinate& coordinate)
{
   string slatitude;
   string slongitude;
   getline(ins,slatitude,',');
   coordinate.latitude=stod(slatitude);
   getline(ins,slongitude);
   coordinate.longitude=stod(slongitude);
   return ins;
}

double Coordinate::get_latitude() const
{
	return latitude;
}

double Coordinate::get_longitude() const
{
	return longitude;
}