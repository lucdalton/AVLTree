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
        binaryTree->Insert(3);
        binaryTree->Insert(5);

        binaryTree->Insert(7);
        binaryTree->Insert(6);
        binaryTree->Insert(8);

    binaryTree->Insert(19);
    binaryTree->Insert(18);
    binaryTree->Insert(100);
    binaryTree->Insert(91);
    binaryTree->Insert(62);
    binaryTree->Insert(85);
    binaryTree->Insert(76);
    binaryTree->Insert(61);
    binaryTree->Insert(888);
    binaryTree->Insert(37);
    binaryTree->Insert(68);
    binaryTree->Insert(78);
        /*
        binaryTree->Insert(1);
        
        binaryTree->Insert(10);
        binaryTree->Insert(4);
        binaryTree->Insert(0);

        binaryTree->Insert(120);
        binaryTree->Insert(40);
         */
        binaryTree->PrintTree();
        std::cout << "";
        
        
    return 0;
}
