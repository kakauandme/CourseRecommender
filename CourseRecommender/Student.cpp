//
//  Student.cpp
//  CourseRecommender
//
//  Created by Kirill Kliavin on 13/03/12.
//  Copyright (c) 2012 RMIT. All rights reserved.
//
#include "Student.h"

Student::Student()
{
    id=undergraduate=female=local=gpa=0;
}
Student::Student(int id, bool undergraduate, bool female, bool local, int gpa)
{
    this->id = id;
    this->undergraduate = undergraduate;
    this->female = female;
    this->local = local;
    this->gpa = gpa;
}
Student::Student(std::string record)
{
     //try{
    
        //string->char* !magic!
        const char* number = std::strtok (const_cast<char*>(record.c_str()),",");
        id = atoi(number);
        
        number = strtok (NULL, ",");
        undergraduate = atoi(number);
        
        number = strtok (NULL, ",");
        female = atoi(number);
        
        number = strtok (NULL, ",");
        local = atoi(number);
        
        number = strtok (NULL, ",");
        gpa = atof(number);  
    
    //}catch(){}
}
int Student::Id()
{
    return id;
}
bool Student::Undergraduate()
{
    return undergraduate;
}
bool Student::Female()
{
    return female;
}
bool Student::Local()
{
    return local;
}
int Student::GPA()
{
    return gpa;
}

float Student::norm(float* weights){
    float weight = 0.0f;
    
    weight = sqrt(weights[0]*undergraduate + weights[1]*female + weights[2]*local + weights[3]*gpa);
    
    return weight;
}
