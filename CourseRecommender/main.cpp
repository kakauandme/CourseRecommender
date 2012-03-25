//
//  main.cpp
//  CourseRecommender
//
//  Created by Kirill Kliavin on 13/03/12.
//  Copyright (c) 2012 RMIT. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "Student.h"
#include "Course.h"
using namespace std;

#define stdcnt 10
#define EXTRA_CHAR 1
#define MAX_LINE_LENGTH 1024

//it is possible to write method,
//but we have to make virtual class
//with makeFromFromString(string) method
vector<Student> readStudents_c(FILE *);
vector<Student> readStudents(string);
vector<Course> readCourses(string);



int main (int argc, const char * argv[])
{
    
    vector<Student> students = readStudents("student.csv");
    vector<Course> courses = readCourses("course.csv");

    // insert code here...
    cout << "Students count:\t"<< students.size() << endl;
    cout << "Courses count:\t" << courses.size() << endl;
    return 0;
}

vector<Student> readStudents(string path)
{
    
    vector<Student> students;    
    string line;
    /*
    char *curpath=NULL;
    size_t size;
    curpath=getcwd(curpath, size);
    string longPath = string(curpath);
     
    longPath+="/";
    longPath+=path;
     
    cout<< longPath <<endl;
    */
    
    ifstream myfile (path.c_str());
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            if(line[0]!= '#'){
                students.push_back(Student(line));
            }
        }
        myfile.close();
    }
    return students;    
}

vector<Course> readCourses(string path)
{
    vector<Course> students;    
    string line;
    
    /*
    char *curpath=NULL;
    size_t size;
    curpath=getcwd(curpath, size);
    string longPath = string(curpath);
    
    longPath+="/";
    longPath+=path;
    
    cout<< longPath <<endl;
    */
    
    ifstream myfile (path.c_str());
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            if(line[0]!= '#'){
                students.push_back(Course(line));
            }
        }
        myfile.close();
    }
    return students;    
}