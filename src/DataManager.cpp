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