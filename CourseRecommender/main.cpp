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

#define STD_CNT 10

#define NUMBER_OF_COURSES 4





typedef struct NewStudentType 
{
    Student studentInfo;
    Course  courseInfo[NUMBER_OF_COURSES];
} NewStudent;

//it is possible to write method,
//but we have to make virtual class
//with makeFromFromString(string) method
vector<Student> readStudents(string);
vector<Course> readCourses(string);

NewStudent createNewStudent();

bool generateWekaFile(vector<Student>&, vector<Course>&);
void print(vector<Student>&,vector<Course>&);

vector<Student>* getSimilarByStudent(vector<Student>&, Student&);
vector<Course>* getSimilarByCourse(vector<Course>&, Course&);

vector<Student>* getSimilarByCourses(vector<Student>&, vector<Course>&, NewStudent);
int* getRecommendedCourses(vector<Student>&, vector<Course>&, NewStudent);


int main (int argc, const char * argv[])
{
    
    vector<Student> students = readStudents("student.csv");
    vector<Course> courses = readCourses("course.csv");
    NewStudent newStudent;
    
    cout << "Students count:\t"<< students.size() << endl;
    cout << "Courses count:\t" << courses.size() << endl;
    
    
    //generateWekaFile(students, courses);
    
    print(students,courses);
    newStudent = createNewStudent();
    getSimilarByStudent(students, newStudent.studentInfo);
//  getSimilarByCourse(courses, newStudent.);
    
    cout<<endl;
    
    return 0;
}

bool generateWekaFile(vector<Student>& students, vector<Course>& courses)
{    

    ofstream wekaFile;
    wekaFile.open("data.arff");
    
    const string classes[] = {"unknown","very_bad", "bad", "satisfactory", "good", "excellent"};
    
    wekaFile << "@RELATION " << "STUDENT_RATE_FOR_COURSE\n\n";
    // Student section
    wekaFile << "@ATTRIBUTE " << "undergrad " << "{0,1}\n";
    wekaFile << "@ATTRIBUTE " << "female " << "{0,1}\n";
    wekaFile << "@ATTRIBUTE " << "local " << "{0,1}\n";
    wekaFile << "@ATTRIBUTE " << "gpa " << "NUMERIC\n";

    // Course section    course,lecturer,tutor,core
    wekaFile << "@ATTRIBUTE " << "course " << "NUMERIC\n";
    wekaFile << "@ATTRIBUTE " << "lecturer " << "NUMERIC\n";
    wekaFile << "@ATTRIBUTE " << "tutor " << "NUMERIC\n";
    wekaFile << "@ATTRIBUTE " << "core " << "{0,1}\n";
    wekaFile << "@ATTRIBUTE " << "class " << "{unknown,very_bad,bad,satisfactory,good,excellent}" << "\n\n";
    
    wekaFile << "@DATA\n";
    
    for(int i=0; i<students.size(); i++)
    {   
        for (int j=0; j<courses.size(); j++)
        {
            wekaFile << students[i].Undergraduate() << "," << students[i].Female() << "," << students[i].Local() << "," << students[i].GPA() << ",";
            wekaFile << courses[j].Id() << "," << courses[j].Lecturer() << "," << courses[j].Tutor() << "," << courses[j].Elective() << ",";
            wekaFile << classes[courses[j].Students()[i]] << "\n";
        }
    }
    
    wekaFile.close();
    return true;
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


NewStudent createNewStudent()
{
    NewStudent newStudent;
    bool u,f,l;
    int gpa;
    try {
        cout << "\nEnter new student details \n";
        cout << "Undergraduate:\t";
        cin >> u;
        cout << "Female:\t";
        cin >> f;
        cout << "Local:\t";
        cin >> l;
        cout << "GPA:\t";
        cin >>  gpa;
    } catch (exception c) {
        cout << "Input Error" << endl;
    }
 
    cout << endl << endl;
    
    newStudent.studentInfo=Student(0,u,f,l,gpa);
    
    int c,le,t,r;
    bool e;
    
    try{
        for (int i=0; i<NUMBER_OF_COURSES; i++) {
                
//            
//            cout << "Enter corses " << i+1 <<" details\n";
//            
//            cout << "Course:\t";
//            cin >> c;
//
//            cout << "Lecturer:\t";
//            cin >> le;
//
//            cout << "Tutor:\t";
//            cin >> t;
//
//            cout << "Elective (1/0):\t";
//            cin >> e; 
//            cout << "Rating (1-5):\t";
//            cin >> r;             
//            newStudent.courseInfo[i] = Course(c,le,t,e,r);
//            cout << endl << endl;
            
            //temporary
            newStudent.courseInfo[i] = Course(0,0,0,0,0);
           
        }
    }catch(exception c)
    {
        cout << "Input Error" << endl;

    }
    return newStudent;
    
}


void print(vector<Student>& students,vector<Course>& courses)
{
    cout << "\nID\tU\tF\tL\tGPA\n";
    cout << "-------------------\n";
    for(int i=0;i < students.size(); i++)
    {
        std::cout << students[i];
        
    }
    
    cout << "\nID\tL\tT\tE\n";
    cout << "-------------------\n";
    
    for (int i =0; i<courses.size(); i++) {
        std::cout << courses[i];
    }
}

vector<Student>* getSimilarByStudent(vector<Student>& list, Student& s)
{
    vector<Student>* res = new vector<Student>();
    for (int i=0; i<list.size(); i++) {
        if(s.compare(list[i]))
            res->push_back(list[i]);
    }
    
    return res;
    
}

vector<Course>* getSimilarByCourse(vector<Course>& list, Course& s)
{
    vector<Course>* res = new vector<Course>();
    for (int i=0; i<list.size(); i++) {
        if(s.compare(list[i]))
            res->push_back(list[i]);
    }    
    return res;
    
}

vector<Student>* getSimilarByCourses(vector<Student>& students, vector<Course>& courses, NewStudent newStudent)
{
    vector<Student> *res = new vector<Student>();
    for(int i=0; i<courses.size(); i++) {
        for (k=0; k<students.size(); k++)
            for (int j=0; j<NUMBER_OF_COURSES; j++) {    
                if (newStudent.courseInfo[j].compare(courses[i], students[k].Id())
                    res->push_back(students[k]);
            }
    }
    return res;
}
