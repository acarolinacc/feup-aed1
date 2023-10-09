#ifndef SLOTH_H
#define SLOTH_H

#include <string>

using namespace std;

class Sloth {
public:

    Sloth(const string &ucCode, float startHour, float endHour, const string &type, const string &weekday);


    string getUcCode() const;
    float getStartHour() const;
    float getEndHour() const;
    string getType() const;
    string getWeekday() const;

private:
    string ucCode;
    float startHour;
    float endHour;
    string type;
    string weekday;
};

#endif
