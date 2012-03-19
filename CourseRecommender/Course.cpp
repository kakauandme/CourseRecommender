//
//  Course.cpp
//  CourseRecommender
//
//  Created by Kirill Kliavin on 13/03/12.
//  Copyright (c) 2012 RMIT. All rights reserved.
//

#include "Course.h"


Course::Course()
{
    id=lecture=tutor=elective=0;
    for (int i=0; i<studentsCount; i++)
        students[i]=0;
}
Course::Course(int id, int lecture, int tutor, bool elective, int* students)
{
    this->id = id;
    this->lecture = lecture;
    this->tutor = tutor;
    this->elective = elective;
    for (int i =0; i<studentsCount; i++)
        this->students[i] = students[i];    
}
Course::Course(char* record)
{
    //read from file
}

int Course::Id()
{
    return id;
}
int Course::Lecture()
{
    return lecture;
}
int Course::Tutor()
{
    return tutor;
}
bool Course::Elective()
{
    return elective;
}
int* Course::Students()
{
    return students;
}