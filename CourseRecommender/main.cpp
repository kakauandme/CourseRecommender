#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Required Headers
#include "Student.h"
#include "Course.h"

// Custom Defines
#define STD_CNT 10
#define NUMBER_OF_COURSES 4

using namespace std;

/*****************
 * Special Types *
 *****************/

typedef struct NewStudentType {
    Student studentInfo;
    Course  courseInfo[NUMBER_OF_COURSES];
    int coursesFinished;
} NewStudent;


/**********************
 * Function Prototypes *
 **********************/

// Print student/course
void print(vector<Student>&);
void print(vector<Course>&);

// File operations
vector<Student> readStudents(string);
vector<Course> readCourses(string);

// Create new student
NewStudent createNewStudent();

// Estimate similarities 
vector<Student>* getSimilarByStudent(vector<Student>&, Student&);
vector<Student>* getSimilarByCourses(vector<Student>&, vector<Course>&, NewStudent);
vector<Course>* getRecomendedCourses(vector<Student>&, vector<Course>&, NewStudent&);
int getMaxCourse(NewStudent&);

// Additional 
bool generateWekaFile(vector<Student>&, vector<Course>&);


// ENTRY POINT
int main (int argc, const char * argv[])
{
    if (argc != 3) {
        cout << "Please pass student test data file path as argument 1, and course test data file as argument 2" << endl;
        return 0;
    }
    
    //Read from file test data 
    string sFile = argv[1];
    string cFile = argv[2];
    vector<Student> students = readStudents(sFile);
    vector<Course> courses = readCourses(cFile);   
    
    if (!students.size()|| !courses.size()) {
        cout << "Please pass student test data file path as argument 1, and course test data file as argument 2" << endl;
        return 0;
    }
    
    cout << "Students count:\t"<< students.size() << endl;
    cout << "Courses count:\t" << courses.size() << endl;
    
    cout << "\n All Students" << endl;
    print(students);
    cout << "\n All Courses" << endl;
    print(courses);
    
    //Sample student 
    NewStudent newStudent = createNewStudent();
    
    
    //Step 1: Student profile information similarity
    vector<Student>* sStudents =  getSimilarByStudent(students, newStudent.studentInfo);    
    cout << "\n Students by characteristics" << endl;
    print(*sStudents);
    
    //Step 2: Corses similarity according to student's ratings
    vector<Student>* cStudents = getSimilarByCourses(*sStudents, courses, newStudent);
    cout << "\n Students by courses" << endl;
    print(*cStudents);
    
    //Step 3: Get courses from most similar students which are new to "sample student" 
    vector<Course>* resCourses =  getRecomendedCourses(*cStudents, courses, newStudent);
    cout << "\n Recomended Courses" << endl;
    print(*resCourses);
    
    cout <<"\nRecomended Courses:\t" << resCourses->at(0).Id() <<"\t"<<resCourses->at(1).Id()<<"\t"<<resCourses->at(2).Id()<<endl;
    cout<<endl;
    return 0;
}


/******************
 * File Operations *
 ******************/

// Read students data from file
vector<Student> readStudents(string path)
{
    
    vector<Student> students;    
    string line;    
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
    else{
        cout << "Cannot read student test data file" << endl;
    }
    return students;    
}

// Read courses data from file
vector<Course> readCourses(string path)
{
    vector<Course> courses;    
    string line;
    
    ifstream myfile (path.c_str());
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            if(line[0]!= '#'){
                courses.push_back(Course(line));
            }
        }
        myfile.close();
    }
    else{
        cout << "Cannot read course test data file" << endl;
    }
    return courses;    
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
    
    cout << "Courses finished:\t";
    cin >> newStudent.coursesFinished;
    
    newStudent.studentInfo=Student(0,u,f,l,gpa);
    
    int c,le,t,r;
    bool e;
    
    try{
        for (int i=0; i<newStudent.coursesFinished; i++) {
            
            cout << "Enter corses " << i+1 <<" details\n";
            
            cout << "Course:\t";
            cin >> c;
            
            cout << "Lecturer:\t";
            cin >> le;
            
            cout << "Tutor:\t";
            cin >> t;
            
            cout << "Elective (1/0):\t";
            cin >> e; 
            cout << "Rating (1-5):\t";
            cin >> r;             
            newStudent.courseInfo[i] = Course(c,le,t,e,r);
            cout << endl << endl;
            
            //temporary
            //newStudent.courseInfo[i] = Course(0,0,0,0,0);
            
        }
    }catch(exception c)
    {
        cout << "Input Error" << endl;
        
    }
    return newStudent;
    
}

/***********
 * Printers *
 ***********/ 

void print(vector<Student>& students)
{
    cout << "\nID\tU\tF\tL\tGPA\n";
    cout << "-------------------\n";
    for(int i=0;i < students.size(); i++)
    {
        std::cout << students[i];
        
    }
}
void print(vector<Course>& courses)
{    
    cout << "\nID\tL\tT\tE\tS1\tS2\tS3\tS4\tS5\tS6\tS7\tS8\tS9\tS10\n";
    cout << "-------------------------------------------------------\n";
    
    for (int i =0; i<courses.size(); i++) {
        std::cout << courses[i];
    }
}


/************************
 * Estimate similarities *
 ************************/ 

// By student data
vector<Student>* getSimilarByStudent(vector<Student>& list, Student& s)
{
    vector<Student>* res = new vector<Student>();
    for (int i=0; i<list.size(); i++) {
        if(s.compare(list[i]))
            res->push_back(list[i]);
    }
    //Add if for 0 sudents !!!!!!!!!!!!!!!!!!!!!!!
    return res;
}

// By course data
vector<Student>* getSimilarByCourses(vector<Student>& students, vector<Course>& courses, NewStudent newStudent)
{
    vector<Student> *res = new vector<Student>();
    for(int i=0; i<courses.size(); i++) {
        for (int j=0; j<newStudent.coursesFinished; j++){
            if(newStudent.courseInfo[j].Id() !=  courses[i].Id())
                continue;
            
            for (int k=0; k<students.size(); k++){
                if (!courses[i].Students()[students[k].Id()-1])
                    continue;
                
                if (newStudent.courseInfo[j].compare(courses[i], students[k].Id()-1)){
                    bool flag = true;
                    for (int f=0; f<res->size(); f++) {
                        if (res->at(f).Id() == students[k].Id()){
                            flag = false;
                            break;
                        }
                    }
                    if (flag) res->push_back(students[k]);
                }
            }
        }
    }
   // cout << "\nAlike students: " << res->size();
    //Add if for 0 sudents !!!!!!!!!!!!!!!!!!!!!!!
    return res;
}

// Finds latest course of Sample Student for "prerequisite feature"
int getMaxCourse(NewStudent& s){
    int res = 0;
    
    for (int i=0; i<s.coursesFinished; i++)
        if (s.courseInfo[i].Id() > res)
            res= s.courseInfo[i].Id();
    
    return res;
}

// Get recommended
vector<Course>* getRecomendedCourses(vector<Student>& students, vector<Course>& courses, NewStudent& s)
{
    vector<Course>* res = new vector<Course>();
    float   coursesToRecommend[STD_CNT];
    
    int maxCourse = getMaxCourse(s);
    float ratingSum;
    int coursesCount;
    int recommendedCnt = 0;
    bool unique = false;
    for(int j=0; j<courses.size();j++){
        unique = true;
        for(int k = 0; k< s.coursesFinished; k++){
            if(courses[j].Id() == s.courseInfo[k].Id() ){
                unique = false;
                break;
            }
            
        }
        if (courses[j].Id() <= maxCourse || !unique) {
            continue;                
        }  
        ratingSum = 0;
        coursesCount=0;
        for(int i =0; i< students.size(); i ++){
            if(courses[j].Students()[students[i].Id()-1]){
                ratingSum+=courses[j].Students()[students[i].Id()-1];
                coursesCount++;                
            }
        }
        cout << "Course " << courses[j].Id() << " AVG rating = " << ratingSum/coursesCount << endl;
        if(ratingSum/coursesCount >= 2.0){
            res->push_back(courses[j]);
            coursesToRecommend[recommendedCnt++] = ratingSum/coursesCount;
            //cout << "Course " << courses[j].Id() << " AVG= " << ratingSum/coursesCount << endl;
        }
    }
    //sorts recomended courses
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i =0; i< recommendedCnt-1; i++) {
            
            if (coursesToRecommend[i] < coursesToRecommend[i+1]) {
                float tmp = coursesToRecommend[i];
                coursesToRecommend[i] = coursesToRecommend[i+1];
                coursesToRecommend[i+1] = tmp;
                
                Course ctmp = res->at(i);
                res->at(i) = res->at(i+1);
                res->at(i+1) = ctmp;
                sorted = false;              
                
            }
        }
    }    
    
    //Add if for 0 courses !!!!!!!!!!!!!!!!!!!!!!!
    return res;
}


/*************
 * Additional *
 *************/ 

// This method generates Weka file which may be used for analyzing data
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
    
    // Course section (course,lecturer,tutor,core)
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


