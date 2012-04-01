//
//  Course.h
//  CourseRecommender
//
//  Created by Kirill Kliavin on 13/03/12.
//  Copyright (c) 2012 RMIT. All rights reserved.
//

#ifndef CourseRecommender_Course_h
#define CourseRecommender_Course_h



#endif
#include <iostream>
#include <string>
#include <math.h>

const unsigned studentsCount = 10;
const float COURSEWEIGHTS[5] = {0.3,0.2,0.05,0.05,0.4};   //course,lecture,tuter,core,rating
const float CORSETRASHOLD = 0.7;

class Course{
private:
    
    int id;
    int lecturer;
    int tutor;
    bool elective;
    int students[studentsCount];

public:
    
    Course();
    Course(int,int,int,bool, int*);
    Course(int,int,int,bool);
    Course(std::string);
    
    int Id();
    int Lecturer();
    int Tutor();
    bool Elective();
    int* Students();
    bool compare(const Course&,int);
//    float norm() const;
//    bool operator<(const Course&);
    friend std::ostream& operator<<(std::ostream& os, const Course& s);
};
