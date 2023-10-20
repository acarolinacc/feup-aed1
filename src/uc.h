#ifndef UC_H
#define UC_H
#include <string>
#include "slot.h"
#include <vector>
#include <ClassUC.h>
using  namespace std;
class Uc{
public:
    Uc(string ucId);
    int getUcYear() const;
    int getUcSemester() const;
    string getUcId() const;
    vector<ClassUC> getUcclassesOfUc() const;
    void addUcclassesOfUc(ClassUC classuc);




private:
    string ucId;
    int ucYear;
    int ucSemester;
    vector<ClassUC>classesOfUc;

};





#endif