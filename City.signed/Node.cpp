//Filename:Node.cpp
//Author:Challa Vagdevi
//AssignmentNumber:7
//Description:US Maps
//Last changed:22/03/2018

#include <math.h>
#include "Node.h"

Node::Node(){

}

Node::Node(City city)
{
	name = city.get_name();
	state = city.get_state();
	convert_coordinate(city.get_coordinate());
	(*this).city = city;
}

Node::Node(Coordinate coordinate)
{
	convert_coordinate(coordinate);
	City acity(name, state, coordinate);
	(*this).city = acity;
}
Node::~Node(){
    delete this;
}
void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

bool Node::operator >(const Node& other)
{
	return row > other.row || (!(other.row > row) && col > other.col);
}

int Node::get_row() const
{
	return row;
}

int Node::get_col() const
{
	return col;
}

string Node::get_name() const
{
	return name;
}

string Node::get_state() const
{
	return state;
}

City Node::get_city() const
{
	return city;
}
ostream& operator <<(ostream& outs, const Node& node)
{
	outs << "#";
	return outs;
}
