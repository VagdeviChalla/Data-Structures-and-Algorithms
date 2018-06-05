//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:DataAllZeroes.cpp
//Description:Sorting algorithms comparision

#include "DataAllZeros.h"

DataAllZeros::DataAllZeros() : DataGenerator("All zeroes") {

}
//Destructor
DataAllZeros::~DataAllZeros() {

}
void DataAllZeros::generate_data(vector<Element>& data, int size)
{
    for (int i = 0; i < size; i++) data.push_back(Element(0));
}
