#include <iostream>
#include "Menu.h"
#include "DataManager.h"

int main() {
    DataManager management;
    // Inicialize o objeto DataManager com os dados necessários.

    Menu menu(management); // Crie uma instância de Menu com o objeto DataManager.
    menu.start();

    return 0;
}

