//Author:Vagdevi Challa
//SJSU ID:012524707
//AssignmentNo:13
//filename:BinarySearchTree.cpp
//description:comparision between AVL tree and BST

#include <string>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() { clear(); }

BinaryNode *BinarySearchTree::get_root() const { return root; }

int BinarySearchTree::height() const { return height(root); }

int BinarySearchTree::height(const BinaryNode *ptr) const
{
   return ptr == nullptr ? -1: 1 + max(height(ptr->left),height(ptr->right));
    /***** Complete this function. *****/
}

int BinarySearchTree::find_min() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_min(root)->data;
}

BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
    if (ptr != nullptr)
    {
        while(ptr->left != nullptr) {ptr = ptr->left;}
    }

    return ptr;
    /***** Complete this function. *****/
}

int BinarySearchTree::find_max() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_max(root)->data;
}

BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{   
    if (ptr != nullptr)
    {
        while(ptr->right != nullptr) {ptr = ptr->right;}
    }

    return ptr;
    /***** Complete this function. *****/
}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{
    /***** Complete this function. *****/
    if (ptr != nullptr)
    {
        clear(ptr->left);
        clear(ptr->right);
        delete ptr;
        ptr = nullptr;
    }
}

bool BinarySearchTree::is_empty() const
{
    /***** Complete this function. *****/
        return root == nullptr;
}

bool BinarySearchTree::contains(const int data) const
{
    return contains(data, root);
}
//https://gist.github.com/mycodeschool/44e1a9183ab0e931f729
bool BinarySearchTree::contains(const int data, BinaryNode *ptr) const
{
    /***** Complete this function. *****/
   if(ptr == NULL) return false;
   else if(ptr->data == data) return true;
   else if (data < ptr->data) return contains(data,ptr->left);
   else return contains(data,ptr->right);
}

void BinarySearchTree::insert(const int data)
{
    insert(data, root);
}
//https://gist.github.com/mycodeschool/44e1a9183ab0e931f729
void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
    /***** Complete this function. *****/
    if (ptr == nullptr)
    {
        ptr = new BinaryNode(data);
    }
    else if (data < ptr->data)
    {
        insert(data, ptr->left);
    }
    else if (data > ptr->data)
    {
        insert(data, ptr->right);
    }
    
}

void BinarySearchTree::remove(const int data)
{
    remove(data, root);
}
//https://gist.github.com/mycodeschool/9465a188248b624afdbf
void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
	if(ptr == NULL) return; 
	else if(data < ptr->data) remove(data,ptr->left);
	else if (data > ptr->data) remove(data,ptr->right);
	else {
		// Case 1:  No child
		if(ptr->left == NULL && ptr->right == NULL) { 
			delete ptr;
			ptr = NULL;
		}
		//Case 2: One child 
		else if(ptr->left == NULL) {
			struct BinaryNode *temp = ptr;
			ptr = ptr->right;
			delete temp;
		}
		else if(ptr->right == NULL) {
			struct BinaryNode *temp = ptr;
			ptr = ptr->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct BinaryNode *temp = find_min(root->right);
			root->data = temp->data;
			remove(temp->data,ptr->right);
		}
	}
    /***** Complete this function. *****/
}