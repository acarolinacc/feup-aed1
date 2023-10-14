#include <string>
#include <vector>
#include "ClassUC.h"


const string &ClassUC::getClassCode() const {
    return classCode_;
}

const string &ClassUC::getUcCode() const {
    return ucCode_;
}

void ClassUC::addSlot(Slot b){
    schedule_.push_back(b);
}

ClassUC::ClassUC(const string &ucCode, const string &classCode, const vector<Slot> &schedule) : ucCode_(ucCode),classCode_(classCode),schedule_(schedule) {}

const vector<Slot> &ClassUC::getSchedule() const {
    return schedule_;
}
