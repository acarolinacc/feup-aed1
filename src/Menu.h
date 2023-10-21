#ifndef MENU_H
#define MENU_H

#include "DataManager.h"

class Menu {
public:
    void setManagement(const DataManager &management);
    Menu(DataManager& management);
    void start();

private:
    DataManager management;
    void printStudentInfo(const Student& student);
    bool areStringsEqualIgnoreCase(const std::string& str1, const std::string& str2);
    void consultarHorarios();
    void consultarHorarioAluno();
    void consultarHorarioTurma();
    void consultarHorarioUC();
    void consultarHorarioUCTurma();
    bool studentBelongsToUCAndClass(const Student& student, const string& ucCode, const string& classCode);
    void realizarAlteracoes();

    void consultarInformacoesUCs();
    void consultarInformacoesAlunos();
    void consultarNumEstudantesInscritosN_UC();
    void consultarAlunosTurmaCursoAno();
    void consultarUcsComMaisEstudantes();

    void consultarTurmaAnoCursoUC();
    DataManager& management_;

    void consultarAlunosPorTurma();

    void consultarAlunosPorAno();

    bool isClassCodeValid(const string &input, const string &target) const;

    void displayClassSchedule(const ClassUC &uc) const;

    bool isStudentValid(const string &input, const Student &student) const;

    void displayStudentSchedule(const Student &student) const;
};

#endif
