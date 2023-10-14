#include "uc.h"
#include "turma.h"
#include "student.h"
#include "sloth.h"
#include "DataManager.h"
#include <iostream>


int main() {
    DataManager teste;
    teste.readStudentClasses();
    std::set<Student> students = teste.getStudents();
    for (Student student : students) {

        student.print_student();
    }

    return 0;
}