#ifndef MENU_H
#define MENU_H

#include "DataManager.h"

class Menu {
public:
    Menu(DataManager& management);

    void start();  // Esta função inicia o menu principal

private:
    DataManager& management;  // Referência para o gerenciamento de horários

    void consultarHorarios();
    void consultarHorarioAluno();
    void consultarHorarioTurma();
};

#endif
