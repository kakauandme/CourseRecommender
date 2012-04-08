#ifndef CourseRecommender_Student_h
#define CourseRecommender_Student_h

#include <iostream>
#include <string>
#include <math.h>

#define W_UNDERGRAD 0.2
#define W_GENDER 0.2
#define W_LOCAL 0.1
#define W_GPA 0.5

#define STUDENT_THRESHOLD 0.5

#ifndef STD_CNT
#define STD_CNT 10
#endif

/* Undergrad, Gender, Local, GPA */
const float STUDENTWEIGHTS[4] = {W_UNDERGRAD, W_GENDER, W_LOCAL, W_GPA};    

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
    bool compare(const Student&);
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

#endif