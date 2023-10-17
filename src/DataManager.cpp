#include <iostream>
#include "DataManager.h"
#include "ClassUC.h"


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

            int sCode = stoi(values[0]);
            Student student = Student(sCode, values[1]);
            ClassUC classUcRead=ClassUC(values[2],values[3]);
            auto it = students.find(student);
            if (it != students.end()) {
                Student alterStudent = *it;
                students.erase(it);
                alterStudent.addClassUC(classUcRead);
                students.insert(alterStudent);}
            else {
                student.addClassUC(classUcRead);
                students.insert(student);

            }

        }
    }
    file.close();
}

const vector<ClassUC> &DataManager::getAllUC() const {
    return allUC_;
}

void DataManager::readClasses() {

    string fname = "classes.csv";
    ifstream file(fname);

    std::string line = "";
    std::string str = "";
    std::string previousUC = ""; //compares current uc code with the last one
    vector<std::string> temp;


    if (file.is_open()) {
        getline(file, line); //skip the first line, since is useless in this context
        while (getline(file, line)) {
            temp.clear();
            istringstream iss(line);

            while (getline(iss, str, ',')) {
                temp.push_back(str);
            }


            string classCode = temp[0];
            string ucCode = temp[1];
            string day = temp[2];
            string start = temp[3];
            string duration = temp[4];
            string type = temp[5];
            Slot slot (day, start, duration, type);



            if (ucCode != previousUC) {

                allUC_.push_back(ClassUC(ucCode,classCode,{slot}));

            } else {
                bool ucAlreadyIn = false;
                for (ClassUC& uc: allUC_) {
                    if (classCode == uc.getClassCode() && ucCode == uc.getUcCode()) {
                        uc.addSlot(slot);
                        ucAlreadyIn = true;
                    }
                }
                if (!ucAlreadyIn) { allUC_.push_back(ClassUC(ucCode, classCode, {slot})); }

            }

            previousUC=ucCode;
        }

    }
    else {cout << "Didn't manage to open classes.csv." << endl; }


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
