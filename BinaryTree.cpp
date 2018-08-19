//
//  BinaryTree.cpp
//  AVLTree
//
//  Created by Luc on 16/08/2018.
//  Copyright © 2018 Luc. All rights reserved.
//

#include "BinaryTree.hpp"

#include <iostream>
//#include <cmath>

#define REBALANCE_HEIGHT 2

node* NewNode(){
    node* n = new node();
    n->left = nullptr;
    n->right = nullptr;
    n->height = 0;
    return n;
}

/*
 void BinaryTree::Insert(int key, node* n){
 if(key < n->key){
 if(n->left != nullptr)
 {
 n->lweight++;
 Insert(key, n->left);
 }
 else{
 // reached the end of the tree branch
 n->left = NewNode();
 n->left->key = key;
 }
 }else if(key > n->key){
 if(n->right != nullptr){
 n->rweight++;
 Insert(key, n->right);
 }else{
 // reached end of tree branch
 n->right = NewNode();
 n->right->key = key;
 }
 }
 
 }
 */

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

int maxHeight(node* n, node* p){
    
    return (height(n) > height(p) ? height(n) : height(p));
}

int max(int a, int b){
    return (a > b ? a : b);
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

node* BinaryTree::Insert(int key, node* n){

    if(n==nullptr){
        n = NewNode();
        n->key = key;
        n->height = 0;
    }else if (key < n->key){
        
        n->left = Insert(key, n->left);
        if(height(n->left) - height(n->right) == REBALANCE_HEIGHT){
            // rebalance
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

    /*
     node** p;
     if(key < n->key)
        p = &(n->left);
     else
        p = &(n->right);
     
     (*p) = Insert(key, *p);
     if(abs(height(n->right) - height(n->left)) == REBALANCE_HEIGHT){
     
     }
     */
    
    
/*
    /// without repeating code
     node** k;
     if(key < n->key)
         k = &(n->left);
     else
         k = &(n->right);
     if(*k==nullptr){
         *k = NewNode();
         (*k)->key = key;
         (*k)->height = ++height;
     }else{
         Insert(key, *k, ++height);
     }
 */
}

/*
void Shift_0(node* n, node* parent){
    // case 0
    if(parent->left!=nullptr){
        if(parent->left->key == n->key){
            // node is on the left
            parent->left = n->left;
            n->left->right = n;
            n->left = nullptr;
        }
    }
    else{
        // node is on the right
        parent->right = n->left;
        n->left->right = n;
        n->left = nullptr;
        
    }
}

void Shift_1(node* n, node* parent){
    // case 1
    if(parent->left!=nullptr){
        if(parent->left->key == n->key){
            // node is on the left
            parent->left = n->left->right;
            n->left->right->right = n;
            n->left->right->left = n->left;
            
            n->left->right = nullptr;
            n->left = nullptr;
            n->right = nullptr;
            
        }
    }
    else{
        // node is on the right
        parent->right = n->left->right;
        n->left->right->right = n;
        n->left->right->left = n->left;
        
        n->left->right = nullptr;
        n->left = nullptr;
        n->right = nullptr;
    }
}
 */
/*
void BinaryTree::Shift(node* n, node* parent){
      n            1
     / \            \
    2   5             5        5        3
       /            /         \         \
      4               3          7          4
     /                \         /           \
    3                 4        6            5
     case 0         case 1      case2     case3
 
    int first = 0;
    int second = 0;
    
    int p = 0;
    
    if(parent->left->key == n->key){
        // node is on the left
        p=0;
    }else{
        // node is on the right
        p=1;
    }
    
    
    if(n->left != nullptr){
        if(n->left->left != nullptr){
            // case 0
 
             if(p==0){
             parent->left = n->left;
             n->left->right = n;
             n->left = nullptr;
             }else{
             parent->right = n->left;
             n->left->right = n;
             n->left = nullptr;
             }
 
            Shift_0(n, parent);
        }else{
            // case 1
            if(p==0){
                parent->left = n->left->right;
                
            }
        }
    }else{
        if(n->right->left != nullptr){
            // case 2
        }else{
            // case 3
        }
    }
}
 */

void PrintNode(node* n){
    std::cout << "key: " << n->key << " height: " << n->height;
    if(n->left!=nullptr){
        std::cout << " :left " << n->left->key;
    }
    else{
        std::cout << " :left null";
    }
    
    if(n->right!=nullptr){
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


/*
int main(){
    
    BinaryTree* binaryTree = new BinaryTree();
    binaryTree->Insert(2);
    binaryTree->Insert(3);
    binaryTree->Insert(1);
    binaryTree->Insert(5);
    binaryTree->Insert(10);
    
    binaryTree->PrintTree();
    

     node* n1 = NewNode();
     node* n2 = NewNode();
     node* n3 = NewNode();
     node* n4 = NewNode();
     
     n1->key = 1;
     n2->key = 5;
     n3->key = 4;
     n4->key = 3;
     
     n1->right = n2;
     n2->left = n3;
     n3->left = n4;
     
     //std::cout << n1->key << " :left " << n1->left->key << " right: " << n1->right->key; //<< "\n";
     
     PrintNode(n1);
     PrintNode(n2);
     PrintNode(n3);
     PrintNode(n4);
     
     Shift_0(n2, n1);
     
     std::cout << "\n";
     
     
     
     PrintNode(n1);
     PrintNode(n2);
     PrintNode(n3);
     PrintNode(n4);
     
 
    
    
    return 0;
}
*/
