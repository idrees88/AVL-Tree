//
//  StudentData.cpp
//  Queue
//
//  Created by Eddie on 4/10/17.
//  Copyright © 2017 Idrees Ashraf. All rights reserved.
//

#include "StudentData.hpp"

StudentData::StudentData() {
    this->studentName = "";
    this->studentRollNo = "";
    this->studentID = 0;
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}

StudentData::StudentData(string name, string rollNo, int studentID) {
    this->studentName = name;
    this->studentRollNo = rollNo;
    this->studentID = studentID;
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}

int StudentData::getHeight() {
    return this->height;
}

string StudentData::getStudentName() {
    return this->studentName;
}

string StudentData::getStudentRollNo() {
    return this->studentRollNo;
}

int StudentData::getStudentID() {
    return this->studentID;
}

void StudentData::setHeight(int height) {
    this->height = height;
}

void StudentData::setLeft(StudentData *left) {
    this->left = left;
}

void StudentData::setRight(StudentData *right) {
    this->right = right;
}

StudentData* StudentData::getLeft() {
    return this->left;
}

StudentData* StudentData::getRight() {
    return this->right;
}
