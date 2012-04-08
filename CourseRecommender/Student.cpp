#include "Student.h"

// Constructors
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
}

// Accessors
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

/* Compare two students (depends on student threshold factor) */
bool Student::compare(const Student& a)
{
    float res = 0.0;
    res += STUDENTWEIGHTS[0]*(undergraduate == a.undergraduate);
    res += STUDENTWEIGHTS[1]*(female == a.female);
    res += STUDENTWEIGHTS[2]*(local == a.local);
    res += STUDENTWEIGHTS[3]*((3 - abs(gpa-a.gpa))/3);
    std::cout << "Student " << id << " VS " << a.id << "\t|" << res<< '\n'; 
    return res > STUDENT_THRESHOLD;
}

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << s.id<< '\t' << s.undergraduate << '\t' << s.female << '\t' << s.local << '\t' << s.gpa<< '\t'  << '\n';
    return os;
}