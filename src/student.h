#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>
#include "Sloth.h"

using namespace std;

class Student {
public:
    Student(int code, const string& name);

    int getCode() const;

    string getName() const;

    void addSloth(const Sloth& sloth);

    void removeSloth(const Sloth& sloth);

    const list<Sloth>& getSloths() const;

private:
    int code;
    string name;
    list<Sloth> sloths;
};

#endif
