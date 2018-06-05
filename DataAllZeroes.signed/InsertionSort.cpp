//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:InsertionSort.cpp
//Description:Sorting algorithms comparision

#include "InsertionSort.h"
#include "Sorter.h"
#include "VectorSorter.h"
InsertionSort::InsertionSort() : VectorSorter ("Insertion sort") {

}


InsertionSort::~InsertionSort() {

}
//https://www.geeksforgeeks.org/insertion-sort/
void InsertionSort::run_sort_algorithm()
{
	int j;
	for (int i = 0; i < size; i++){
			j = i;

			while (j > 0 ){
				if(data[j] < data[j-1]){
					compare_count++;
					 swap(j, j-1);
				}
				j--;

			}
	}

}