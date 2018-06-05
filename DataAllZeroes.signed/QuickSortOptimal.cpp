//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:QuickSortOptimal.cpp
//Description:Sorting algorithms comparision

#include "QuickSortOptimal.h"

QuickSortOptimal::QuickSortOptimal() : QuickSorter("Quicksort optimal") {}

QuickSortOptimal::~QuickSortOptimal() {}
Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
	   int mid = (left+right)/2;

	   compare_count++;
	   if ( data[mid] < data[left] ) swap(left,mid);

	   if ( data[right] < data[left] ) swap(left,right);

	   if ( data[mid] > data[right] ) swap(mid,right);

	   swap(left,mid); 

	   return data[left];
}
