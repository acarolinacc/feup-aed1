#include "uc.h"

Uc::Uc(string ucId,int ucYear,int ucSemester,vector<Sloth> ucSloth) {
    this->ucId=ucId;
    this->ucSemester=ucSemester;
    this->ucSloth=ucSloth;
    this->ucYear=ucYear;}

int Uc::getUcYear() const{
    return ucYear;
}
int Uc::getUcSemester() const{
    return ucSemester;
}
vector<Sloth> Uc::getUcSloth() const {
    return ucSloth;
}
string Uc::getUcId() const {
    return ucId;
}
void Uc::addUcSloth(const Sloth& sloth){
    ucSloth.push_back(sloth);
}



