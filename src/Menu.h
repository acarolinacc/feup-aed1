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

    void consultarHorarios();
    void consultarHorarioAluno();
    void consultarHorarioTurma();

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
};

#endif
