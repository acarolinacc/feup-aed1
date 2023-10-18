#include "uc.h"
#include "slot.h"
#include "DataManager.h"
#include <iostream>


#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        // Menu Principal
        cout << "Menu Principal:" << endl;
        cout << "1. Consultar horários de alunos ou turmas." << endl;
        cout << "2. Consultar informações de alunos." << endl;
        cout << "3. Consultar informações de turmas." << endl;
        cout << "4. Realizar alterações em UC ou turmas." << endl;
        cout << "5. Sair do programa." << endl;
        cout << "Por favor, escolha uma opção (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Navegue para a página de horários de alunos ou turmas.
                // Implemente a lógica para essa funcionalidade.
                break;
            case 2:
                // Navegue para a página de consulta de informações de alunos.
                // Implemente a lógica para essa funcionalidade.
                break;
            case 3:
                // Navegue para a página de consulta de informações de turmas.
                // Implemente a lógica para essa funcionalidade.
                break;
            case 4:
                // Navegue para a página de realização de alterações em UC ou turmas.
                // Implemente a lógica para essa funcionalidade.
                break;
            case 5:
                cout << "O programa está encerrando. Obrigado!" << endl;
                break;
            default:
                cout << "Opção inválida. Por favor, escolha uma opção válida (1-5)." << endl;
                break;
        }

    } while (choice != 5);

    return 0;
}
