#ifndef CourseRecommender_Course_h
#define CourseRecommender_Course_h

#include <iostream>
#include <string>
#include <math.h>

#define W_COURSE 0.2
#define W_LECTURER 0.1
#define W_TUTOR 0.1
#define W_RATING 0.6
#define W_CORE 0 // need to define?

#define COURSE_THRESHOLD 0.7

#ifndef STD_CNT
#define STD_CNT 10
#endif

/* Course, Lecturer, Tutor, Core, Rating */
const float COURSEWEIGHTS[5] = {W_COURSE,W_LECTURER,W_TUTOR,W_RATING};

class Course {
private:
    
    int id;
    int lecturer;
    int tutor;
    bool elective;
    int students[STD_CNT];
    
public:
    
    Course();
    Course(int,int,int,bool, int*);
    Course(int,int,int,bool,int);
    Course(std::string);
    
    int Id();
    int Lecturer();
    int Tutor();
    bool Elective();
    int* Students();
    bool compare(const Course&,int);
    friend std::ostream& operator<<(std::ostream& os, const Course& s);
};

#endif