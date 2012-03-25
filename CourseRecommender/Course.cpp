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


float Course::norm(float* weights){
    float weight = 0.0f;
    
    weight = sqrt(weights[0]*id + weights[1]*lecturer + weights[2]*tutor + weights[3]*elective);
    
    return weight;
}