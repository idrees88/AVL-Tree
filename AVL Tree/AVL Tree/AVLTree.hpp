//
//  AVLTree.hpp
//  AVL Tree
//
//  Created by Eddie on 5/12/17.
//  Copyright © 2017 Idrees Ashraf. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <stdio.h>

#include "StudentData.hpp"

class AVLTree {
    
    StudentData *root;
    
public:
    AVLTree();
    void insert(StudentData *student);
    bool search(StudentData *student);
    void printInOrderTraverse();
    
private:
    StudentData* rightRotate(StudentData *node);
    StudentData* leftRotate(StudentData *node);
    void traverseInOrder(StudentData *root);
    void traverseRightTreeInOrder();
    void insert(StudentData *rootNode, StudentData *insertNode);
    
    int max(int a, int b);
    int getBalance(StudentData *student);
};

#endif /* AVLTree_hpp */
