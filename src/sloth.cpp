#include "Sloth.h"

using namespace std;

Sloth::Sloth(const string& ucCode, float startHour, float endHour, const string& type, const string& weekday)
        : ucCode(ucCode), startHour(startHour), endHour(endHour), type(type), weekday(weekday) {}

string Sloth::getUcCode() const {
    return ucCode;
}

float Sloth::getStartHour() const {
    return startHour;
}

float Sloth::getEndHour() const {
    return endHour;
}

string Sloth::getType() const {
    return type;
}

string Sloth::getWeekday() const {
    return weekday;
}
