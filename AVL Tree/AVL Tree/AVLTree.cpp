//
//  AVLTree.cpp
//  AVL Tree
//
//  Created by Eddie on 5/12/17.
//  Copyright © 2017 Idrees Ashraf. All rights reserved.
//

#include "AVLTree.hpp"

#include <iostream>

using namespace std;

AVLTree::AVLTree() {
    this->root = nullptr;
}

void AVLTree::insert(StudentData *student) {
    this->insert(this->root, student);
}

StudentData* AVLTree::rightRotate(StudentData *node) {
    StudentData *BNode = node->getLeft();
    StudentData *TNode = BNode->getRight();
    
    BNode->setRight(node);
    node->setLeft(TNode);
    
    node->setHeight(max(node->getRight()->getHeight(), node->getLeft()->getHeight()) + 1);
    BNode->setHeight(max(BNode->getLeft()->getHeight(), BNode->getRight()->getHeight())+1);
    
    return BNode;
}

StudentData* AVLTree::leftRotate(StudentData *node) {
    StudentData *BNode = node->getRight();
    StudentData *TNode = BNode->getLeft();
    
    BNode->setLeft(node);
    node->setRight(TNode);
    
    node->setHeight(max(node->getRight()->getHeight(), node->getLeft()->getHeight()) + 1);
    BNode->setHeight(max(BNode->getLeft()->getHeight(), BNode->getRight()->getHeight())+1);
    
    return BNode;
}

//Recursively Insert
void AVLTree::insert(StudentData *rootNode, StudentData *insertNode) {
    if (rootNode == nullptr) {
        rootNode = insertNode;
        return;
    }
    if (insertNode->getStudentID() < rootNode->getStudentID()) {
        insert(rootNode->getLeft(), insertNode);
    }
    else if (insertNode->getStudentID() > rootNode->getStudentID()) {
        insert(rootNode->getRight(), insertNode);
    }
    else {
        return;
    }
    
    int maxHeight = max(rootNode->getLeft()->getHeight(), rootNode->getRight()->getHeight());
    maxHeight++;
    rootNode->setHeight(maxHeight);
    
    int balance = getBalance(rootNode);
    
    //Right
    if (balance > 1 && insertNode->getStudentID() < rootNode->getLeft()->getStudentID()) {
        rightRotate(rootNode);
        return;
    }
    
    //Left
    if (balance < -1 && insertNode->getStudentID() > rootNode->getRight()->getStudentID()) {
        leftRotate(rootNode);
        return;
    }
    
    //Left Right
    if (balance > 1 && insertNode->getStudentID() > rootNode->getLeft()->getStudentID()) {
        rootNode->setLeft(leftRotate(rootNode->getLeft()));
        rightRotate(rootNode);
        return;
    }
    
    //Right Left
    if (balance < -1 && insertNode->getStudentID() < rootNode->getRight()->getStudentID()) {
        rootNode->setRight(rightRotate(rootNode->getRight()));
        leftRotate(rootNode);
        return;
    }
    
}

bool AVLTree::search(StudentData *student) {
    bool isFound = false;
    
    StudentData *traverse = this->root;
    
    while (!isFound && traverse != nullptr) {
        if (traverse->getStudentID() == student->getStudentID()) {
            isFound = true;
            break;
        }
        else {
            if (student->getStudentID() > traverse->getStudentID()) {
                traverse = traverse->getRight();
            }
            else {
                traverse = traverse->getLeft();
            }
        }
    }
    
    return isFound;
}

void AVLTree::traverseInOrder(StudentData *root) {
    if (root != nullptr) {
        traverseInOrder(root->getLeft());
        cout<<"Value: "<<root->getStudentRollNo()<<"\n\n";
        traverseInOrder(root->getRight());
    }
}

void AVLTree::printInOrderTraverse() {
    traverseInOrder(this->root);
}

int AVLTree::max(int a, int b) {
    return (a > b)? a:b;
}

int AVLTree::getBalance(StudentData *student) {
    if (student == nullptr) {
        return 0;
    }
    
    return student->getLeft()->getHeight() - student->getRight()->getHeight();
}


