//Author:Vagdevi Challa
//File name:Node.cpp
//Assignment No:9
//Description:comparing STL Vector and list
#include <iostream>
#include "Node.h"

using namespace std;

// Static member variables, which are global to the class.
// These variables exist independently from any Node objects.
long Node::constructor_count;
long Node::copy_count;
long Node::assign_count;
long Node::destructor_count;

//Constructor
Node::Node(const long the_value) {
    constructor_count++;
    value=the_value;
}

//Copy Constructor
Node::Node(const Node &other) {
    value=other.value;
    copy_count++;
}

//Destructor
Node::~Node() {
    destructor_count++;
}
void Node::reset(){
   constructor_count=0;
   copy_count=0;
   assign_count=0;
   destructor_count=0;
}
//Getter method for getting the value
long Node::get_value() const {
    return  value;
}

//Getter for constructor count
long Node::get_constructor_count() {
    return constructor_count;
}
//Getter for assign count
long Node::get_assign_count() {
    return assign_count;
}
//Getter to get the copy count
long Node::get_copy_count() {
    return copy_count;
}

//Getter to get the destructor count
long Node::get_destructor_count() {
    return destructor_count;
}

 bool Node::operator ==(const Node& other) const{
    if(this->value==other.value){
       return true;
    }else false;
 }

 bool Node::operator <=(const Node& other) const{
    if(this->value <= other.value){
       return true;
    }else false;
 }

 bool Node::operator >=(const Node& other) const{
    if(this->value >= other.value){
       return true;
    }else false;
 }
 Node& Node::operator =(const Node& rhs){
    this->value=rhs.value;
    assign_count++;
    return *this;
 }
/***** Complete this file. *****/
