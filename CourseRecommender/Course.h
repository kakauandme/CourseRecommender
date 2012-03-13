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

const int studentsCount = 10;

class Course{
private:
    
    int id;
    int lecture;
    int tutor;
    bool elective;
    int students[studentsCount];
    
    
public:
    
    Course();
    Course(int,int,int,bool, int*);
    Course(char*);
    
    int Id();
    int Lecture();
    int Tutor();
    bool Elective();
    int* Students();
};
