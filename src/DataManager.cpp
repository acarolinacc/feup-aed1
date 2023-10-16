#include <iostream>
#include "DataManager.h"



set<Student> DataManager::getStudents() const{
    return students;
}

void DataManager::readStudentClasses(){
    ifstream file("students_classes.csv");
    if (!file.is_open()) {
        cout << "erro a abrir fichiro"<< endl;
        return;
    }
    string line;
    string value;
    vector<string> values;
    string studentName; string studentCode;
    getline(file,line);//the first line is not important
    while (getline(file,line)){
        values.clear();
        istringstream iss(line);
        while (getline(iss,value,',')){    //values[0]-studentiD,value[1]-StudentName,value[2]-ucCode,value[3]-classCode
            values.push_back(value);
        }
        if (values.size() >= 4) {
            //adicionar os valores a um student e depois adicionar os students ao set de the estudantes
            UcClass ucClassread;
            int sCode = stoi(values[0]);
            Student student = Student(sCode, values[1]);
            ucClassread.ucCode = values[2];
            ucClassread.tCode = values[3];
            auto it = students.find(student);
            if (it != students.end()) {
                Student alterStudent = *it;
                students.erase(it);
                alterStudent.addUcClass(ucClassread);
                students.insert(alterStudent);}
            else {
                student.addUcClass(ucClassread);
                students.insert(student);

            }

        }
    }
    file.close();
}

void DataManager::readClasses() {
    ifstream file("classes.csv");
    string line;
    string value;

    vector<Sloth> classes;

    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> values;
        while (getline(iss, value, ',')) {
            values.push_back(value);
        }

        if (values.size() >= 6) {
            string classCode = values[0];
            string ucCode = values[1];
            string weekday = values[2];
            double startHour = stod(values[3]);
            double duration = stod(values[4]);
            string type = values[5];

            Sloth sloth(ucCode, startHour, startHour + duration, type, weekday);

            classes.push_back(sloth);

        } else {
            cout << "A linha no arquivo CSV não contém dados suficientes: " << line << endl;
        }
    }
    file.close();
}

void DataManager::readClassesPerUC() {
    ifstream file("classes_per_uc.csv");
    string line;
    string value;

    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> values;

        while (getline(iss, value, ',')) {
            values.push_back(value);
        }

        if (values.size() == 2) {
            string ucCode = values[0];
            string classCode = values[1];
        }
    }
}
