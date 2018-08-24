//  BinaryTree.cpp
//  AVLTree
//
//  Created by Luc on 16/08/2018.
//  Copyright © 2018 Luc. All rights reserved.

#include "BinaryTree.hpp"
#include <iostream>

#define REBALANCE_HEIGHT 2

node* NewNode(){
    node* n = new node();
    n->left = nullptr;
    n->right = nullptr;
    n->height = 0;
    return n;
}

void BinaryTree::Insert(int key){
    
    if(root == nullptr){
        root = NewNode();
        root->key = key;
        return;
    }
    
    root = Insert(key, root);

}

int height(node* n){
    return (n==nullptr ? -1 : n->height);
}

int max(int a, int b){
    return (a > b ? a : b);
}

int maxHeight(node* n, node* p){
    return max(height(n), height(p));
}

node* shiftLeft(node* n){
/*
         n                 2
        / \               / \
       2   T1     ->     1   n
      /\                    / \
     1  T2                 T2   T1
*/
    node* p = n->left;
    n->left = n->left->right;
    p->right = n;
    n->height = max(height(n->left), height(n->right)) + 1;
    return p;
}

node* shiftRight(node* n){
/*
      n                        2
     / \                      / \
    T1  2         ->         n   3
       / \                  / \
      T2  3                T1 T2
     
*/
    node* p = n->right;
    n->right = n->right->left;
    p->left = n;
    n->height = max(height(n->left), height(n->right)) + 1;
    return p;
}


node* shiftLeft_v(node* n){
/*
         n                 n              2
        /                 /              / \
       0        ->       2      ->      0   n
        \               /
         2             0
 */
    n->left = shiftRight(n->left);
    return shiftLeft(n);
}

node* shiftRight_v(node* n){
/*
       n                 n                  0
        \                 \                / \
         2        ->       2      ->      n   2
        /                   \
       0                     0
     
*/
    n->right = shiftLeft(n->right);
    return shiftRight(n);
}

node* minNode(node* n){
    // find the smallest node from a tree root n
    if(n == nullptr)
        return nullptr;
    else if(n->left == nullptr)
        return n;
    else
        return minNode(n->left);
}

void BinaryTree::Remove(int key){
    root = Remove(key, root);
}

node* BinaryTree::Remove(int key, node* n){
    
    node* temp;
    
    if(n==nullptr)
        return nullptr;
    
    if(key < n->key){
        n->left = Remove(key, n->left);
    }
    else if(key > n->key){
        n->right = Remove(key, n->right);
    }
    // when control reaches here we have arrived at the node to remove
    else if(n->right && n->left){
        
        // node has 2 children
        temp = minNode(n->right);
        n->key = temp->key;
        n->right = Remove(n->key, n->right);
        
    }else{
       
        // node has 1 or 0 children
        temp = n;
        if(n->left==nullptr){
            n = n->right;
        }else if(n->right==nullptr){
            n = n->left;
        }else{
            return nullptr;
        }
        delete temp;
    }
    
    if(n==nullptr)
        return n;
    
    //n->height = max(height(n->left), height(n->right))+1;
    n->height = maxHeight(n->left, n->right)+1;

    // check node balancing
    if(height(n->left) - height(n->right) == REBALANCE_HEIGHT)
    {
        // left left case
        if(height(n->left->left) - height(n->left->right) == REBALANCE_HEIGHT-1)
            return shiftLeft(n);
        // left right case
        else
            return shiftLeft_v(n);
    }
    // If right node is deleted, left case
    else if(height(n->right) - height(n->left) == REBALANCE_HEIGHT)
    {
        // right right case
        if(height(n->right->right) - height(n->right->left) == REBALANCE_HEIGHT-1)
            return shiftRight(n);
        // right left case
        else
            return shiftRight_v(n);
    }
    return n;
}


node* BinaryTree::Insert(int key, node* n){

    if(n==nullptr){
        n = NewNode();
        n->key = key;
        n->height = 0;
    }else if (key < n->key){
        
        n->left = Insert(key, n->left);
        if(height(n->left) - height(n->right) == REBALANCE_HEIGHT){
            if(key < n->left->key){
                n = shiftLeft(n);
            }else{
                n = shiftLeft_v(n);
            }
        }
        
    }else if(key > n->key){

        n->right = Insert(key, n->right);
        if(height(n->right) - height(n->left) == REBALANCE_HEIGHT){
            if(key > n->right->key){
                n = shiftRight(n);
            }else{
                n = shiftRight_v(n);
            }
        }
        
    }
    n->height = maxHeight(n->left, n->right) + 1;
    return n;
    
}

void BinaryTree::DeleteNode(node* n){
    if(n->left)
        DeleteNode(n->left);
    if(n->right)
        DeleteNode(n->right);
    delete n;
}


void PrintNode(node* n){
    std::cout << "key: " << n->key << " height: " << n->height;
    if(n->left){
        std::cout << " :left " << n->left->key;
    }
    else{
        std::cout << " :left null";
    }
    
    if(n->right){
        std::cout << " right: " << n->right->key;
    }
    else{
        std::cout << " right: null";
    }
    std::cout << "\n";
}

void BinaryTree::PrintTree(node* n){

    PrintNode(n);

    if(n->left!=nullptr)
        PrintTree(n->left);
    if(n->right!=nullptr)
        PrintTree(n->right);
    
}

void BinaryTree::PrintTree(){
    PrintTree(root);
}
