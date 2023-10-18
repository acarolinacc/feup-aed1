#ifndef MENU_H
#define MENU_H

#include "DataManager.h"

class Menu {
public:
    Menu(DataManager& management);

    void start();

private:
    DataManager& management;  

    void consultarHorarios();
    void consultarHorarioAluno();
    void consultarHorarioTurma();
};

#endif
