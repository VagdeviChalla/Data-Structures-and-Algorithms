//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:DataRandom.cpp
//Description:Sorting algorithms comparision

#include <stdlib.h>
#include <time.h>
#include "DataRandom.h"
#include "Element.h"

DataRandom::DataRandom() : DataGenerator("Unsorted random") {

}
//destructor
DataRandom::~DataRandom() {

}

//random data generation
void DataRandom::generate_data(vector<Element>& data, int size)
{
	data.clear();
	if (random_data.size() != size){
		random_data.clear();
		srand(time(NULL));

		for (int i = 0; i <= size-1; i++)
		{
			long r = rand()%size;
			Element element(r);
			data.push_back(element);
			random_data.push_back(element);

		}
	}
	else
	{
		data = random_data;
	}
}
