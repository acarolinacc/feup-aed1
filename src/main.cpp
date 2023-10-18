#include <iostream>
#include "Menu.h"  // Inclua o cabeçalho da classe Menu

int main() {
    // Crie uma instância do gerenciador de horários, por exemplo:
    DataManager management;

    // Crie uma instância da classe Menu
    Menu menu(management);

    // Inicie o menu principal
    menu.start();

    return 0;
}
