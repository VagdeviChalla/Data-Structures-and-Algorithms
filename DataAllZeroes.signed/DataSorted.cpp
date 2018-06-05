//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:DataSorted.cpp
//Description:Sorting algorithms comparision

#include "DataSorted.h"

DataSorted::DataSorted() : DataGenerator("Already sorted") {

}
DataSorted:: ~DataSorted() {

}
//sorted data generation(low to high order)
void DataSorted::generate_data(vector<Element>& data, int size)
{
    for (long i = 0; i < size; i++)
    {
    	   data.push_back(Element(i));
    }
}
