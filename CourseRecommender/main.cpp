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
#include <map>
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
vector<Student>* getSimailar(vector<Student>&, Student&);
vector<Course>* getSimailar(vector<Course>&, Course&);






int getMaxCourse(NewStudent&);
int* getRecomendedCourses(vector<Student>&, vector<Course>&,  NewStudent&);
bool compareCoursesToRecommend(const float&, const float&);


int main (int argc, const char * argv[])
{
    
    vector<Student> students = readStudents("student.csv");
    vector<Course> courses = readCourses("course.csv");
    NewStudent newStudent;
    
    // insert code here...
    cout << "Students count:\t"<< students.size() << endl;
    cout << "Courses count:\t" << courses.size() << endl;
    //generateWekaFile(students, courses);
    print(students,courses);
    newStudent = createNewStudent();
    getSimailar(students, newStudent.studentInfo);
//  getSimailar(courses, newStudent.);
    
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
    
    int c,le,t;
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
//            cout << "Elective:\t";
//            cin >> e; 
//            newStudent.courseInfo[i] = Course(c,le,t,e);
//            cout << endl << endl;
            
            //temporary
            newStudent.courseInfo[i] = Course(0,0,0,0);
           
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

vector<Student>* getSimailar(vector<Student>& list, Student& s)
{
    vector<Student>* res = new vector<Student>();
    for (int i=0; i<list.size(); i++) {
        if(s.compare(list[i]))
            res->push_back(list[i]);
    }
    
    return res;
    
}

vector<Course>* getSimailar(vector<Course>& list, Course& s)
{
    vector<Course>* res = new vector<Course>();
    for (int i=0; i<list.size(); i++) {
        if(s.compare(list[i]))
            res->push_back(list[i]);
    }    
    return res;
    
}












int getMaxCourse(NewStudent& s){
    int res = 0;
    
    for (int i=0; i<NUMBER_OF_COURSES; i++)
        if (s.courseInfo[i].Students()[0] > res)
            res= s.courseInfo[i].Students()[0];
        
    return res;
}


bool compareCoursesToRecommend(const float& s1, const float& s2)
{
    return    s1<s2;
}


int* getRecomendedCourses(vector<Student>& students, vector<Course>& courses, NewStudent& s)
{
    int maxCourse = getMaxCourse(s);
    map <int,float>  coursesToRecommend;
    int ratingSum;
    int coursesCount;
    bool unique = false;
    for(int j=0; j<courses.size();j++){
        unique = true;
        for(int k = 0; k< NUMBER_OF_COURSES; k++){
            if(courses[j].Id() == s.courseInfo[k].Id() ){
                unique = false;
                break;
            }
                
        }
        if (courses[j].Id() <= maxCourse) {
            continue;                
        }  
        ratingSum = 0;
        coursesCount=0;
        for(int i =0; i< students.size(); i ++){
            if(courses[j].Students()[i]){
                ratingSum+=courses[j].Students()[i];
                coursesCount++;
            }
        }
        if(ratingSum/coursesCount >= 3.0)
            coursesToRecommend.insert(pair<int,float>(j,ratingSum/coursesCount));
    }
    std::sort(coursesToRecommend.begin(),coursesToRecommend.end(),compareCoursesToRecommend); 
    int* res = new int[3];
    int cnt = 0;
    for(map<int,float>::iterator it = coursesToRecommend.begin(); it != coursesToRecommend.end(); ++it) {
        
        res[cnt] = it->first;
        if(++cnt >= 3)
            break;
    
    }
    
    return res;
    
}

            
