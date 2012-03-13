//
//  Student.cpp
//  CourseRecommender
//
//  Created by Kirill Kliavin on 13/03/12.
//  Copyright (c) 2012 RMIT. All rights reserved.
//
#include "Student.h"

Student::Student()
{
    id=undergraduate=female=local=gpa=0;
}
Student::Student(int id, bool undergraduate, bool female, bool local, int gpa)
{
    this->id = id;
    this->undergraduate = undergraduate;
    this->female = female;
    this->local = local;
    this->gpa = gpa;
}
Student::Student(char* path)
{
    //read from file
}
int Student::Id()
{
    return id;
}
bool Student::Undergraduate()
{
    return undergraduate;
}
bool Student::Female()
{
    return female;
}
bool Student::Local()
{
    return local;
}
int Student::GPA()
{
    return gpa;
}
