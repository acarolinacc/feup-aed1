#include "Student.h"

using namespace std;

Student::Student(int code, const string& name) : code(code), name(name) {}

int Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

void Student::addSloth(const Slot& slot) {
    sloths.push_back(slot);
}


const list<Slot>& Student::getSloths() const {
    return sloths;
}

void Student::addUcClass(const UcClass& newUcClass){
    classes.push_back(newUcClass);

}
bool Student::operator<(const Student &other) const {
    return this->code<other.code;
}

void Student::print_student(){
    cout << name << '/' << code << print_UcClass() << '\n';
}

string Student::print_UcClass() {
    string result="[";
    for (const auto& value : classes) {
        result+="[";
        result+=value.tCode;
        result+=",";
        result+=value.ucCode;
        result+="]";
    }
    result +="]";
    return  result;
}