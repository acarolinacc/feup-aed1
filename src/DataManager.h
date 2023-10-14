#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "student.h"
#include "sloth.h"
#include <string>
#include <fstream>
#include <sstream>
#include <set>

class DataManager{


public:
    //DataManager();
    void readClasses();
    void readStudentClasses();
    set<Student> getStudents() const ;
    void readClassesPerUC();


private:
    set<Student>students;
    vector<Sloth> classes;

};








#endif
