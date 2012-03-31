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

#include <iostream>
#include <string>
#include <math.h>

const float STUDENTWEIGHTS[4] = {0.2,0.2,0.1,0.5};    // undergrad,gender,local,GPA
const float STUDTRASHHOLD = 0.5;

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
    Student(std::string);
    
    int Id();
    bool Undergraduate();
    bool Female();
    bool Local();
    int GPA();
//    float norm() const;
    bool compare(const Student&);
//    bool operator<(const Student&) ;
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    
    
        
};
