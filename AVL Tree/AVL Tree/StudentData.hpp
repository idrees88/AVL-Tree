//
//  StudentData.hpp
//  Queue
//
//  Created by Eddie on 4/10/17.
//  Copyright © 2017 Idrees Ashraf. All rights reserved.
//

#ifndef StudentData_hpp
#define StudentData_hpp

#include <stdio.h>
#include <string>

using namespace std;


class StudentData {
    int studentID;
    int height;
    string studentName;
    string studentRollNo;
    StudentData *left;
    StudentData *right;
    
public:
    StudentData();
    StudentData(string name, string rollNo, int studentID);
    string getStudentName();
    string getStudentRollNo();
    int getHeight();
    void setHeight(int height);
    int getStudentID();
    void setLeft(StudentData *left);
    void setRight(StudentData *right);
    StudentData* getLeft();
    StudentData* getRight();
};

#endif /* StudentData_hpp */
