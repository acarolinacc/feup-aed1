#include <iostream>
#include "Menu.h"
#include "DataManager.h"

int main() {
    DataManager management;

    Menu menu(management);
    menu.start();

    return 0;
}

#include "DataManager.h"


/*
int main() {
 DataManager management;
 management.readClasses();
 management.readClassesPerUC();
 management.readStudentClasses();
 //Menu menu(management);
 //menu.start();
 //vector<Student> stu=management.UCstudents();



 vector<ClassUC> year=management.UcWithLessThanXStudents(100000);



 for ( ClassUC& uc : year) {
     std::cout << "UC Code: " << uc.getUcCode() << std::endl;
     std::cout << "Class Code: " << uc.getClassCode() << std::endl;
     std::cout << "uc with" << management.numberStudentsUc(uc.getUcCode()) << endl;
 }
 if(year.size()==0) {cout<<",";}
/*
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

*/