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
    id=lecturer=tutor=elective=0;
    for (int i=0; i<studentsCount; i++)
        students[i]=0;
}
Course::Course(int id, int lecturer, int tutor, bool elective, int* students)
{
    this->id = id;
    this->lecturer = lecturer;
    this->tutor = tutor;
    this->elective = elective; 
        for (int i=0; i<studentsCount; i++)
            this->students[i] = students[i];
        
}
Course::Course(int id, int lecturer, int tutor, bool elective, int rating)
{
    this->id = id;
    this->lecturer = lecturer;
    this->tutor = tutor;
    this->elective = elective; 
    this->students[0] = rating;
}
Course::Course(std::string record)
{
    
    //try{
    
        //string->char* !magic!
        const char* number = std::strtok (const_cast<char*>(record.c_str()),",");
        id = atoi(number);
        
        number = strtok (NULL, ",");
        lecturer = atoi(number);
        
        number = strtok (NULL, ",");
        tutor = atoi(number);
        
        number = strtok (NULL, ",");
        elective= atoi(number);
        
        for (int i =0; i<studentsCount; i++) {
            if((number = strtok (NULL, ",")))
                students[i] = atoi(number);
            else
                students[i] = 0;
        }
    //}catch(){}
}

int Course::Id()
{
    return id;
}
int Course::Lecturer()
{
    return lecturer;
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

bool Course::compare(const Course& c,int student){
    
    if(!c.students[student])
        return false;
    
    float res = 0.0;
    res+=COURSEWEIGHTS[0]*(id == c.id);
    res+=COURSEWEIGHTS[1]*(lecturer == c.lecturer);
    res+=COURSEWEIGHTS[2]*(tutor == c.tutor);
    res+=COURSEWEIGHTS[3]*(elective == c.elective);
    res+=COURSEWEIGHTS[4]*(5-abs(students[0] - c.students[student]))/5;
    std::cout << "Course " << id << "of S0 VS Course " << c.id << " of S" << student<< " |" << res<<'\n'; 
    return res > CORSETRASHOLD;
}

std::ostream& operator<<(std::ostream& os, const Course& s)
{
    os << s.id<< '\t' << s.lecturer  << '\t' << s.tutor << '\t' << s.elective << '\t';
    
    for(int i=0; i< 10;i++)
        os<< s.students[i] << '\t';
    os    << '\n';
    return os;
}