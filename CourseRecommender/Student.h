//
//  Student.h
//  CourseRecommender
//
//  Created by Kirill Kliavin on 13/03/12.
//  Copyright (c) 2012 RMIT. All rights reserved.
//

#ifndef CourseRecommender_Student_h
#define CourseRecommender_Student_h



#endif


class Student{
private:
    
    int id;
    bool undergraduate;
    bool female;
    bool local;
    int gpa;
    
    
public:
    
    Student();
    Student(int, bool, bool, bool, int);
    Student(char*);
    
    int Id();
    bool Undergraduate();
    bool Female();
    bool Local();
    int GPA();
        
};
