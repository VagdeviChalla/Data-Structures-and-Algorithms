//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:QuickSortSuboptimal.cpp
//Description:Sorting algorithms comparision

#include "QuickSortSuboptimal.h"

QuickSortSuboptimal::QuickSortSuboptimal() : QuickSorter("Quicksort suboptimal") {}

QuickSortSuboptimal::~QuickSortSuboptimal() {}
Element& QuickSortSuboptimal::choose_pivot_strategy(const int left, const int right)
{
   return data[left];
}
