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
#include "Student.h"
#include "Course.h"
using namespace std;

#define stdcnt 10

//it is possible to write method,
//but we have to make virtual class
//with makeFromFromString(string) method
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
    const char*  tmp = path.c_str();
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

