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

#include <string>
#include <math.h>

const unsigned studentsCount = 10;

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
    Course(std::string);
    
    int Id();
    int Lecturer();
    int Tutor();
    bool Elective();
    int* Students();
    float norm(float*);

};
