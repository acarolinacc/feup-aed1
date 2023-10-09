#include "Student.h"

using namespace std;

Student::Student(int code, const string& name) : code(code), name(name) {}

int Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

void Student::addSloth(const Sloth& sloth) {
    sloths.push_back(sloth);
}


const list<Sloth>& Student::getSloths() const {
    return sloths;
}
