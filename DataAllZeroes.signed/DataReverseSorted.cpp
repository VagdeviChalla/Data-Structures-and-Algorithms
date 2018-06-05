//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:DataReverseSorted.cpp
//Description:Sorting algorithms comparision

#include "DataReverseSorted.h"

DataReverseSorted::DataReverseSorted() : DataGenerator("Reverse sorted") {

}
//destructor
DataReverseSorted:: ~DataReverseSorted() {

}
//data generation in reverse sort order
void DataReverseSorted::generate_data(vector<Element>& data, int size)
{
    for (long i = size; i > 0; i--)
    {
      	data.push_back(Element(i));
    	}
}
