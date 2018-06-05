//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:QuickSorter.cpp
//Description:Sorting algorithms comparision

#include <iostream>
#include "QuickSorter.h"
using namespace std;

QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

QuickSorter::~QuickSorter() {}

void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}
//https://github.com/careercup/ctci/blob/master/java/Chapter%2011/Introduction/Quicksort.java

void QuickSorter::quicksort(const int left, const int right)
{
    // Continue the recursive calls until the indexes cross.
    if (left <= right)
    {
        // Choose the pivot and partition this subrange.
        Element& pivot = choose_pivot(left, right);
        int p = partition(left, right, pivot);

        quicksort(left, p-1);  // Sort elements <  pivot
        quicksort(p+1, right); // Sort elements >= pivot
    }
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
	   int index=left + 1, prevIndex= left;
	   for ( index; index <= right; index++)
	   {
	      compare_count++;
	      if(pivot > data[index])
	      {
	         prevIndex++;
	         swap(prevIndex, index);
	      }
	   }
	   swap(left, prevIndex);
	   return prevIndex;
}
