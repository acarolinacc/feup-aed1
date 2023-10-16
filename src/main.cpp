#include "uc.h"
#include "turma.h"
#include "student.h"
#include "sloth.h"
#include "DataManager.h"
#include <iostream>


int main() {
    DataManager teste;
    teste.readStudentClasses();
    const set<Student> students = teste.getStudents(); // Make sure it's const

    for (auto it = students.begin(); it != students.end(); ++it) {
        it->print();
    }


    return 0;
}




