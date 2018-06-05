//Author:Vagdevi Challa
//SJSU ID:012524707
//File name:WordMap.cpp
//Description:STL Vector and Map
//Asssignment Number:11
//Last Changed:04/19/2018

#include <map>
#include <string>
#include "WordMap.h"

using namespace std;

WordMap::WordMap() {}

WordMap::~WordMap() {}


int WordMap:: size() const {
   int size=data.size(); 
   return size;
}
int WordMap::get_count(const string text) const
{
    /***** Complete this function. *****/
    int count=data.at(text).get_count();
    return count;
}

void WordMap::insert(const string text)
{
    /***** Complete this function. *****/
     pair<map<string,Word>::iterator,bool> it;
    // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

    it = data.insert (pair<string,Word>(text,Word(text)));

    if (it.second!=true)
        data.at(text).increment_count();

    // end time
    steady_clock::time_point end_time = steady_clock::now();

    //time increment
    this->increment_elapsed_time(start_time,end_time);
}

map<string, Word>::iterator WordMap::search(const string text)
{
    /***** Complete this function. *****/
        // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

    map<string, Word>::iterator it = data.find(text);

    // end time
    steady_clock::time_point end_time = steady_clock::now();

    //increment time
    this->increment_elapsed_time(start_time,end_time);

    return it;
}