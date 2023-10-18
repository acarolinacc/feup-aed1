#include "Menu.h"
#include <iostream>

Menu::Menu(DataManager& management) : management(management) {}

void Menu::start() {
    int choice;
    do {
        // Menu Principal
        std::cout << "Menu Principal:" << std::endl;
        std::cout << "1. Consultar horários de alunos ou turmas." << std::endl;
        std::cout << "2. Consultar informações de alunos." << std::endl;
        std::cout << "3. Consultar informações de turmas." << std::endl;
        std::cout << "4. Realizar alterações em UC ou turmas." << std::endl;
        std::cout << "5. Sair do programa." << std::endl;
        std::cout << "Por favor, escolha uma opção (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                consultarHorarios();
                break;
            case 2:
                // Implemente a opção 2
                break;
            case 3:
                // Implemente a opção 3
                break;
            case 4:
                // Implemente a opção 4
                break;
            case 5:
                std::cout << "Saindo do programa." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Por favor, escolha uma opção válida (1-5)." << std::endl;
                break;
        }
    } while (choice != 5);
}

void Menu::consultarHorarios() {
    int choice;
    do {
        // Menu da Página de Consulta de Horários
        std::cout << "Página de Consulta de Horários:" << std::endl;
        std::cout << "1. Consultar horário de aluno." << std::endl;
        std::cout << "2. Consultar horário de turma." << std::endl;
        std::cout << "3. Voltar ao menu principal." << std::endl;
        std::cout << "Por favor, escolha uma opção (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                consultarHorarioAluno();
                break;
            case 2:
                consultarHorarioTurma();
                break;
            case 3:
                std::cout << "Voltando ao menu principal." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Por favor, escolha uma opção válida (1-3)." << std::endl;
                break;
        }
    } while (choice != 3);
}

void Menu::consultarHorarioAluno() {
    // Implemente a lógica para consultar o horário de um aluno (mesmo código da resposta anterior).
}

void Menu::consultarHorarioTurma() {
    // Implemente a lógica para consultar o horário de uma turma (mesmo código da resposta anterior).
}
