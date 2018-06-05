//Author:Vagdevi Challa
//File name:SortedList.cpp
//Assignment No:9
//Description:comparing STL Vector and list

#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}
void SortedList::prepend(const long value)
{
   data.push_front(Node(value));
}

void SortedList::append(const long value)
{
    data.push_back(Node(value));
}

void SortedList::remove(const int index)
{
    list<Node>::iterator it = data.begin();

    for(int i=0; i< index ; i++) it++;
    data.erase(it);
}
void SortedList::insert(const long value)
{

    list<Node>::const_iterator it = data.begin();
    if(data.size()==0)
    {
        data.push_back(Node(value));
    }
    else
    {
        list<Node>::const_iterator it = data.begin();
        while ((it!=data.end())&& (it->get_value() < value))
        {
            it++;
        }
        if(it==data.end())
            data.push_back(Node(value));
        else
            data.insert(it,Node(value));
    }
}
void SortedList::reverse(){
   list<Node>::const_iterator it =data.begin();
   while(it != data.end()){
   list<Node>::const_iterator it1 =data.begin();
   it++;
   long value = (*it).get_value();
   data.insert(it1,Node(value));
   it++;
   data.erase(it);
   it--;
   }
}
Node& SortedList::operator [](const int index){
   list<Node>::iterator it = data.begin();
   for(int i=0; i< index ; ++i)
    {
        ++it;
    }
    return *it;
}


bool SortedList::check() const
{
    if (data.size() == 0) return true;

    list<Node>::const_iterator it = data.begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != data.end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
    if (data.size() == 0) return true;

    list<Node>::const_iterator it = data.begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != data.end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}
