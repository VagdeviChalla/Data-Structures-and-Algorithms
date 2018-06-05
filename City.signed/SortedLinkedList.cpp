//Filename:SortedLinkedList.cpp
//Author:Challa Vagdevi
//AssignmentNumber:7
//Description:US Maps
//Last changed:22/03/2018

#include "SortedLinkedList.h"
const short ZERO=0;
const short ONE =1;
SortedLinkedList::SortedLinkedList():head(nullptr) { 
   
}

SortedLinkedList::SortedLinkedList(Node* head)
{
	
}
SortedLinkedList::~SortedLinkedList() { 
   
}

void SortedLinkedList::insert(Node* node)
{
	Node * p;
	if (head == nullptr)
	{
		head = node;
		
	}else if (*head > *node)
	{
		node->next = head;
		head = node;
	} 
	else
	{
		p = head;

		while (p->next && *node > *p->next)
		{
			p = p->next;
		}
		node->next = p->next;
		p->next = node;
	}
}

ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
	Node * c = list.head;
	Node* nnext;

	while (c->next != NULL)
	{
	   if (c->get_col() == c->next->get_col() && c->get_row() == c->next->get_row())
	   {
		   nnext = c->next->next;
		   free(c->next);
		   c->next = nnext;
	   }
	   else
	   {
		  c = c->next;
	   }
	}
	c = list.head;
	int olength,nlength;
	int slen=c->get_state().length(),colnum=c->get_col(),nlen=c->get_name().length();
	olength = colnum + nlen + slen;
	while(c->next != nullptr)
	{
		nlength = c->next->get_col();

		if(nlength <= olength && c->get_row() == c->next->get_row())
		{
			nnext = c->next->next;
			c->next = nnext;
		}
		else
		{
			c = c->next;
			olength = c->get_col() + c->get_name().length() + c->get_state().length();
			if(c->get_name() != "")
				olength = olength+ONE;
		}
	}

	c = list.head;
	int row =c->get_row();
	int new_column = c->get_col();
	int temp=ZERO,width1,width2;
	while (c->next != nullptr)
	{
	   width1=new_column-temp;
		outs << setw(width1);

		if(c->get_name() == "")
		{
			outs  << *c;
		}
		else
		{
			outs << c->get_city();
		}

		if(row < c->next->get_row())
		{
			for(int i=ZERO;i<c->next->get_row()-row;i++)
				outs << endl;
			new_column = ZERO ;
		}
		row = c->next->get_row();
		temp=new_column;
		new_column = c->next->get_col();
		if(c->get_name() != "")
		{
			temp = temp + c->get_name().length() + c->get_state().length()+ONE;
		}
		c = c->next;
	}
	width2=new_column-temp;
	outs << setw(width2);
	outs  << *c;
	return outs;
}
