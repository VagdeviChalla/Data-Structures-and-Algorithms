//Author:Vagdevi Challa
//SJSU ID:012524707
//AssignmentNo:13
//filename:AvlTree.cpp
//description:comparision between AVL tree and BST

#include <iostream>
#include "AvlTree.h"

using namespace std;

AvlTree::AvlTree() : BinarySearchTree() {}

AvlTree::~AvlTree() {}

int AvlTree::height(const BinaryNode *ptr) const
{
   return ptr == nullptr ? -1 : ptr->height;
    /***** Complete this function. *****/
}

void AvlTree::insert(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
    /***** Complete this function. *****/
    if (ptr == nullptr) return ptr;

    if (height(ptr->left) - height(ptr->right) > 1)
    {
        if (height(ptr->left->left) >= height(ptr->left->right))
        {
            ptr = single_right_rotation(ptr);
            cout << "    --- Single right rotation at node "<< ptr->data << endl;
        }
        else
        {
            ptr = double_left_right_rotation(ptr);
            cout << "    --- Double left-right rotation at node "<< ptr->data << endl;
            
        }
    }

    else if (height(ptr->right) - height(ptr->left) > 1)
    {
        if (height(ptr->right->right) >= height(ptr->right->left))
        {
            ptr = single_left_rotation(ptr);
            cout << "    --- Single left rotation at node "<< ptr->data << endl;
            
        }
        else
        {
            ptr = double_right_left_rotation(ptr);
            cout << "    --- Double right-left rotation at node "<< ptr->data << endl;
        }
    }
    // Recompute the node's height.
    ptr->height = (max(height(ptr->left),height(ptr->right)) + 1);

    if (check_balance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{
    BinaryNode *temp;
    temp = k2->left;
    k2->left = temp->right;
    temp->right = k2;
    k2->height = (max(height(k2->left),height(k2->right)) + 1);
    return temp;
    /***** Complete this function. *****/
}

BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
{
    BinaryNode *temp;
    temp = k3->left;
    k3->left = single_left_rotation (temp);
    k3->height = (max(height(k3->left),height(k3->right)) + 1);
    return single_right_rotation (k3);
    /***** Complete this function. *****/
}

BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{
    BinaryNode *temp;
    temp = k1->right;
    k1->right = single_right_rotation (temp);
    k1->height = (max(height(k1->left),height(k1->right)) + 1);
    return single_left_rotation (k1);
    /***** Complete this function. *****/
}

BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{
    /***** Complete this function. *****/
    BinaryNode *temp;
    temp = k1->right;
    k1->right = temp->left;
    temp->left = k1;
    k1->height = (max(height(k1->left),height(k1->right)) + 1);
    return temp;
}

int AvlTree::check_balance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = check_balance(ptr->left);
    int rightHeight = check_balance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}