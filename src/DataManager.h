#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "student.h"
#include "slot.h"
#include "ClassUC.h"
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
    const vector<ClassUC> &getAllUC() const;
    vector<Student> UCstudents(string ucId) const ;

private:
    set<Student>students;
    vector<Slot> classes;
    vector<ClassUC> allUC_ = {};

};








#endif
