//Filename:City.cpp
//Author:Challa Vagdevi
//AssignmentNumber:7
//Description:US Maps
//Last changed:22/03/2018

#include "City.h"

City::City()
{

}

City::City(string name, string state, Coordinate coordinate):name(name), state(state), coordinate(coordinate)
{ 
   
}
City::~City()
{

}

istream& operator >>(istream& ins, City& city)
{  
   string name,state,latitude,longitude;
	getline(ins, name, ',');
	city.name=name;
	getline(ins,state, ',');
	city.state=state;
	getline(ins, latitude, ',');
	double lat=stod(latitude);
	getline(ins, longitude);
	double lon=stod(longitude);
	Coordinate coor(lat, lon);
	city.coordinate =  coor;
	return ins;
}

ostream& operator <<(ostream& outs, const City& city)
{
	outs << "*" << city.name << " " << city.state;
	return outs;
}
string City::get_name() const
{
	return name;
}

string City::get_state() const
{
	return state;
}

Coordinate City::get_coordinate() const
{
	return coordinate;
}