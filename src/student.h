#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>
#include "Sloth.h"
#include <vector>
#include "uc.h"
#include "turma.h"

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

    void addSloth(const Sloth& sloth);

    void removeSloth(const Sloth& sloth);

    const list<Sloth>& getSloths() const;
    void addUcClass(const UcClass& newUcClass);
    bool operator<(const Student &other) const;
private:
    int code;
    string name;
    list<Sloth> sloths;
    vector<UcClass> classes;
};

#endif
