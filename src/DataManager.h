#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "student.h"
#include <string>
#include <fstream>
#include <sstream>
#include <set>

class DataManager{


public:

    void readStudentClasses();
    set<Student> getStudents() const ;
private:
    set<Student>students;
};








#endif
