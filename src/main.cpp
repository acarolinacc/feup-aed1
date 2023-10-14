#include "uc.h"
#include "slot.h"
#include "DataManager.h"
#include <iostream>


int main() {
    DataManager dataManager;
    dataManager.readClasses();

    const vector<ClassUC>& allUC = dataManager.getAllUC();

    for (const ClassUC& uc : allUC) {
        std::cout << "UC Code: " << uc.getUcCode() << std::endl;
        std::cout << "Class Code: " << uc.getClassCode() << std::endl;

        const std::vector<Slot>& slots = uc.getSchedule();
        for (const Slot& slot : slots) {
            std::cout << "Day: " << slot.getDay() << std::endl;
            std::cout << "Start: " << slot.getStart() << std::endl;
            std::cout << "Duration: " << slot.getDuration() << std::endl;
            std::cout << "Type: " << slot.getType() << std::endl;
            std::cout << "-------------------------" << std::endl;
        }

        std::cout << "-------------------------" << std::endl;
    }

    return 0;
}

