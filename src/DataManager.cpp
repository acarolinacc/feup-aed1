#include <iostream>
#include "DataManager.h"


void DataManager::readStudentClasses(){
    ifstream file("students_classes.csv");
    string line;
    UcClass ucClassread;
    string value;

    vector<string> values;
    string studentName; string studentCode;
    while (getline(file,line)){
        istringstream iss(line);
        while (getline(iss,value,',')){    //values[0]-studentiD,value[1]-StudentName,value[2]-ucCode,value[3]-classCode
            values.push_back(value);
        }
        //adicionar os valores a um student e depois adicionar os students ao set de the estudantes
        int sCode=stoi(values[0]);
        Student student=Student(sCode,values[1]);
        ucClassread.ucCode=values[2];
        ucClassread.tCode=values[3];
        if(students.find(student)==students.end()){
            student.addUcClass(ucClassread);
            students.insert(student);
        }
        else{
            auto it=students.find(student);
            Student alterStudent=*it;
            students.erase(it);
            alterStudent.addUcClass(ucClassread);
            students.insert(alterStudent);
        }


    }


}

void DataManager::readClasses() {
    ifstream file("classes.csv");
    string line;
    string value;

    vector<Sloth> classes;  // Crie um vetor de objetos Sloth

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

            // Crie um objeto Sloth com os dados lidos
            Sloth sloth(ucCode, startHour, startHour + duration, type, weekday);

            // Adicione o objeto Sloth ao vetor classes
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
