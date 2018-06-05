//Author:Vagdevi Challa
//File name:TestSuite.cpp
//Assignment No:9
//Description:comparing STL Vector and list

#include <string>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <iostream>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;
//Insert at the ending of the vector.
void vector_appends(SortedVector& sv, const int size)
{
    for (int i = 0; i < size; i++) sv.append(i);
    
}

//Insert new nodes at the ending of the data list.
void list_appends(SortedList& sl, const int size)
{
    for (int i = 0; i < size; i++) sl.append(i);
}
//Insert new nodes at the beginning of the vector.
void vector_prepends(SortedVector& sv, const int size)
{
   sv.reserve(size);
    for(int i=size-1;i>=0;i--)
        sv.prepend(i);
}

//Insert new nodes at the beginning of the data list.
void list_prepends(SortedList& sl, const int size)
{
    for(int i=size-1;i>=0;i--)
        sl.prepend(i);
}
//get data from random positons of vector
void vector_gets(SortedVector& sv, const int size) throw(string){

    // First fill the vector data.
    for (int i = 0; i < size; i++) sv.push_back(i);
    Node::reset();
    
    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand() % size;
        //cout<<"index is :"<<index<<endl;
        long value = sv[index].get_value();

        // Make sure we got the correct node.
        if (index != value) throw string("Vector data mismatch!");
    }
}
//get data from random positons of list
void list_gets(SortedList& sl, const int size) throw(string){

    // First fill the list data.
    list_appends(sl, size);
    Node::reset();
 
    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand() %size;
        long value = sl[index].get_value();
        // Make sure we got the correct node.
        if (index != value) throw string("List data mismatch!");
    }

}
//insert data to vector at random positions
void vector_inserts(SortedVector& sv, const int size) throw(string){
    
    for(int i=0;i<size;i++) {
        long value=rand();
        sv.insert(value);
    }
    
    if (!sv.check()) throw("Vector sort error!");
}
//insert data to list at random positions
void list_inserts(SortedList& sl, const int size) throw(string){
 
    for(int i=0;i<size;i++) {
        long value=rand();
        sl.insert(value);
    }
    if (!sl.check()) throw("List sort error!");
}
//remove data from vector at random positions
void vector_removes(SortedVector& sv, const int size)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    while (sv.size() > 0)
    {
        int index = rand()%sv.size();
        sv.remove(index);
    }
}
//remove data from list at random positions
void list_removes(SortedList& sl, const int size)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    while (sl.size() > 0)
    {

        int index = rand()%sl.size();
        sl.remove(index);
    }
}
//reverse data of vector
void vector_reverse(SortedVector& sv, const int size) throw(string){
    vector_appends(sv, size);
    Node::reset();
    sv.reverse();
    
    if (!sv.check_reversed()) throw("Vector reverse sort error!");
}
//reverse data of list
void list_reverse(SortedList& sl, const int size) throw(string){
    for (int i = 0; i < size; i++) {
       sl.push_back(i);
    }
    Node::reset();
    sl.reverse();
    
    if (!sl.check_reversed()) throw("List reverse sort error!");
}
