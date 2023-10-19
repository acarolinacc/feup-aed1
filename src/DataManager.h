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
    set<Student> getStudents() const;
    const vector<ClassUC>& getAllUC() const;
    void addStudent(const Student& student);
    void addClassUC(const ClassUC& classUC);
    void readClasses();
    void readStudentClasses();
    void readClassesPerUC();


private:
    set<Student>students;
    vector<Slot> classes;
    vector<ClassUC> allUC_ ;

};








#endif
