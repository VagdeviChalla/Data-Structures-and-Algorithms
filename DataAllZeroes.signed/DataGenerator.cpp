//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:DataGenerator.cpp
//Description:Sorting algorithms comparision

#include <string>
#include <vector>
#include "DataGenerator.h"

//name the name of this generator
DataGenerator::DataGenerator(string name) : name(name) {

}
//destructor
DataGenerator:: ~DataGenerator() {

}
//return name of generator
string DataGenerator::get_name() {
	return name;
}
