#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "student.h"
#include "slot.h"
#include "ClassUC.h"
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>

class DataManager{


public:
    //DataManager();
    set<Student> getStudents() const;
    const vector<ClassUC>& getAllUC() const;
    void addStudent(const Student& student);
    void addClassUC(const ClassUC& classUC);
    void readClasses();
    void readStudentClasses();
    void readClassesPerUC();
    vector<Student> UCstudents(string ucId) const ;
    vector<ClassUC> sortAllU();
    bool sorter(const ClassUC& a, const ClassUC& b);




private:
    set<Student>students;
    vector<Slot> classes;
    vector<ClassUC> allUC_ ;

};








#endif
