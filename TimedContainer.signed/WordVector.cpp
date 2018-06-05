//Author:Vagdevi Challa
//SJSU ID:012524707
//File name:WordVector.cpp
//Description:STL Vector and Map
//Asssignment Number:11
//Last Changed:04/19/2018

#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;

WordVector::WordVector() {}

WordVector::~WordVector() {}
int WordVector:: size() const{
     
   return  data.size(); 
}

int WordVector::get_count(const string text) const
{
    /***** Complete this function. *****/
    int position = this->find(text,0,data.size());

    if(position < 0) return 0;
    else return data.at(position).get_count();
}

void WordVector::insert(const string text)
{
    /***** Complete this function. *****/
    
    // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

    int pos = find(text,0,data.size()-1);

    if (pos >= 0 ) 
    {
        vector<Word>::iterator it = data.begin();
        advance (it,pos);
        it->increment_count();
    }
    else 
    {
        pos *= -1;
        data.insert ( data.begin()+pos-1, Word(text) ); 
    }

    // end time
    steady_clock::time_point end_time = steady_clock::now();

    //increment count
    this->increment_elapsed_time(start_time,end_time);
    
}

vector<Word>::iterator WordVector::search(const string text)
{
    /***** Complete this function. *****/
     // Starting time.
    steady_clock::time_point start_time = steady_clock::now();

    vector<Word>::iterator it = data.begin();

    int pos = find(text,0,data.size()-1);
    
    if (pos < 0) it = data.end();
    else if (pos > 0) advance (it,pos);
    else if (pos == 0) it = data.begin();
    
    // ending time
    steady_clock::time_point end_time = steady_clock::now();

    //increment time
    this->increment_elapsed_time(start_time,end_time);

    return it;
}

int WordVector::find(const string text, int low, int high) const
{
    /***** Complete this function. *****/
    if (low <= high)
    {
        int mid = (low + high)/2;
        
        if (text < data[mid].get_text() )
          return find(text, low, mid-1);
        else if (text == data[mid].get_text())
            return mid;
         else return find(text, mid+1, high);
    }
    return -(low + 1);
}
vector<Word>* WordVector::get_data()
{
    return &data;
}
Word &WordVector::operator[](int index){
   return data[index];
}