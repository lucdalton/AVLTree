//
//  BinaryTree.hpp
//  AVLTree
//
//  Created by Luc on 16/08/2018.
//  Copyright © 2018 Luc. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

#endif /* BinaryTree_hpp */

typedef struct node{
    int key;
    node* left;
    node* right;
    
    //int lweight;
    //int rweight;
    int height;
}node;

class BinaryTree{
public:
    BinaryTree(){
        root = nullptr;
    };
    ~BinaryTree();
    
    void Insert(int key);
    node* Search(int key);
    void Remove(int key);
    
    void PrintTree();
    
private:
    //void Insert(int key, node* n);
    node* Insert(int key, node* n);
    node* Remove(int key, node* n);
    node* root;
    
    void PrintTree(node*);
        
};
