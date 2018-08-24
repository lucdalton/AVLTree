//  main.cpp
//  AVLTree
//
//  Created by Luc Dalton on 16/08/2018.
//  Copyright © 2018 Luc Dalton. All rights reserved.
//

#include <iostream>
#include "BinaryTree.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    

        BinaryTree* binaryTree = new BinaryTree();
        binaryTree->Insert(1);
        binaryTree->Insert(2);
        binaryTree->Insert(3);
        binaryTree->Insert(4);
        binaryTree->Insert(5);
        binaryTree->Insert(6);
        binaryTree->Insert(7);
        binaryTree->PrintTree();
        std::cout << "\n";
        binaryTree->Remove(6);
        binaryTree->Remove(7);
        binaryTree->Remove(4);
    
        binaryTree->PrintTree();
        std::cout << "\n";
    
        binaryTree->Insert(6);
        binaryTree->Insert(7);
        binaryTree->Insert(4);

        binaryTree->PrintTree();
        std::cout << "\n";
        /*
        binaryTree->Insert(1);
        
        binaryTree->Insert(10);
        binaryTree->Insert(4);
        binaryTree->Insert(0);

        binaryTree->Insert(120);
        binaryTree->Insert(40);
         */
        //binaryTree->PrintTree();
        std::cout << "";
        
        
    return 0;
}
