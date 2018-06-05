//Author:Vagdevi Challa
//SJSU Id:012524707
//Assignment no:12
//File name:Node.cpp
//Description:Sorting algorithms comparision

#include "Node.h"
#include "Element.h"


Node::Node()
{
   Element();
   next = NULL;
}

Node::Node(const Element input)
{
   element = input;
   next = NULL;
}
Node::~Node() {}
