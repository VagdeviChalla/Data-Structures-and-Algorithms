//Author:Vagdevi Challa
//File name:SortedVector.cpp
//Assignment No:9
//Description:comparing STL Vector and list

#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

void SortedVector::prepend(const long value)
{
    vector<Node>::const_iterator it = data.begin();
    data.insert(it,Node(value));
}

void SortedVector::append(const long value)
{
    data.push_back(Node(value));
}


void SortedVector::remove(const int index)
{
    vector<Node>::iterator it = data.begin();

    for(int i=0; i< index ; i++)
    {
        it++;
    }
    data.erase(it);
}

void SortedVector::insert(const long value)
{
    vector<Node>::const_iterator it =data.begin();
    if(data.size()==0)
    {
        data.push_back(Node(value));
    }
    else
    {
        while ((it!=data.end())&& (it->get_value()<value))
        {
            it++;
        }
        if(it==data.end())
            data.push_back(Node(value));
        else
            data.insert(it,Node(value));
         
         
    }
}
void SortedVector::reverse(){
   vector<Node>::const_iterator it =data.begin();
   while(it != data.end()){
   vector<Node>::const_iterator it1 =data.begin();
   it++;
   long value = (*it).get_value();
   data.insert(it1,Node(value));
   it++;
   data.erase(it);
   it--;
   }
}

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal to the previous node.
    while ((it != data.end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

bool SortedVector::check_reversed() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != data.end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

