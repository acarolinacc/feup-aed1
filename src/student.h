#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>
#include "slot.h"
#include <vector>
#include "uc.h"
#include "turma.h"
#include <iostream>

using namespace std;

struct UcClass{ //lets see if its not needed to make a class of it
    string ucCode;
    string tCode;
};


class Student {
public:
    Student(int code, const string& name);

    int getCode() const;

    string getName() const;

    void addSloth(const Slot& slot);


    const list<Sloth>& getSloths() const;
    void removeSloth(const Slot& slot);
    const list<Slot>& getSloths() const;
    void addUcClass(const UcClass& newUcClass);
    bool operator<(const Student &other) const;
    bool operator==(const Student &other) const;
    void print_student()const;

    void print_UcClass()const;
    void print()const;
private:
    int code;
    string name;
    list<Slot> sloths;
    vector<UcClass> classes;


};

#endif
