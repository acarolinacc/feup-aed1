#ifndef UC_H
#define UC_H
#include <string>
#include "sloth.h"
#include <vector>
using  namespace std;
class Uc{
public:
    Uc(string ucId,int ucYear,int ucSemester,vector<Sloth> ucSloth);
    int getUcYear() const;
    int getUcSemester() const;
    string getUcId() const;
    vector<Sloth> getUcSloth() const;
    void addUcSloth(const Sloth& sloth);




private:
    string ucId;
    int ucYear;
    int ucSemester;
    vector<Sloth> ucSloth;
};





#endif