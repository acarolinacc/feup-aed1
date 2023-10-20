#include "uc.h"

Uc::Uc(string ucId) {
    this->ucId=ucId;}

int Uc::getUcYear() const{
    char year=classesOfUc[0].getClassCode()[0];
}
int Uc::getUcSemester() const{
    return ucSemester;
}
vector<ClassUC> Uc::getUcclassesOfUc() const {
    return classesOfUc;
}
string Uc::getUcId() const {
    return ucId;
}
void Uc::addUcclassesOfUc(const  ClassUC classUc){
    classesOfUc.push_back(classUc);
}