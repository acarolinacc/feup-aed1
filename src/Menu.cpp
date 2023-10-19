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
        std::cout << "3. Consultar informações de UCs." << std::endl;
        std::cout << "4. Realizar alterações em UC ou turmas." << std::endl;
        std::cout << "5. Sair do programa." << std::endl;
        std::cout << "Por favor, escolha uma opção (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                consultarHorarios();
                break;
            case 2:
                consultarInformacoesAlunos();
                break;
            case 3:
                consultarInformacoesUCs();
                break;
            case 4:
                realizarAlteracoes();
                break;
            case 5:
                std::cout << "A sair do programa." << std::endl;
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
                std::cout << "A voltar ao menu principal." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Por favor, escolha uma opção válida (1-3)." << std::endl;
                break;
        }
    } while (choice != 3);
}

void Menu::consultarHorarioAluno() {
    //consultar o horário de um aluno
}

void Menu::consultarHorarioTurma() {
    //  consultar o horário de uma turma
}


void Menu::consultarInformacoesAlunos() {
    cout << "Página de Consulta de Informações de Alunos:" << endl;
    cout << "Escolha uma opção:" << endl;
    cout << "1. Consultar alunos por turma, curso ou ano." << endl;
    cout << "2. Consultar número de estudantes inscritos em, pelo menos, n UCs." << endl;

    int escolha;
    cin >> escolha;

    switch (escolha) {
        case 1:
            consultarAlunosTurmaCursoAno();
            break;
        case 2:
            consultarNumEstudantesInscritosN_UC();
            break;
        default:
            cout << "Escolha uma opção válida." << endl;
    }
}


void Menu::consultarAlunosTurmaCursoAno() {
    // consultar alunos por turma, curso ou ano.
    cout << "Opção: Consultar alunos por turma, curso ou ano" << endl;

}

void Menu::consultarNumEstudantesInscritosN_UC() {
    // consultar o número de estudantes inscritos em pelo menos n UCs.
    cout << "Opção: Consultar o número de estudantes inscritos em pelo menos n UCs" << endl;
}



void Menu::consultarInformacoesUCs() {
    cout << "Página de Consulta de Informações de UCs." << endl;

    int opcao;
    cout << "Escolha uma opção:" << endl;
    cout << "1. Consultar a turma/ano/curso de uma UC." << endl;
    cout << "2. Consultar as UCs com maior número de estudantes." << endl;
    cout << "3. Voltar ao menu principal." << endl;

    cout << "Por favor, escolha uma opção (1-3): ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            consultarTurmaAnoCursoUC();
            break;
        case 2:
            consultarUcsComMaisEstudantes();
            break;
        case 3:
            // Volte ao menu principal
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
    }
}

void Menu::consultarTurmaAnoCursoUC() {
    //  consultar a turma, ano ou curso da UC.
    cout << "Opção: Consultar a turma, ano ou curso da UC" << endl;
}

void Menu::consultarUcsComMaisEstudantes() {
    //  consultar as UCs com maior número de estudantes.
    cout << "Opção: Consultar as UCs com maior número de estudantes" << endl;
}




void Menu::realizarAlteracoes() {
    int choice;
    do {
        // Menu da Página de Realização de Alterações
        cout << "Página de Realização de Alterações:" << endl;
        cout << "1. Realizar alterações em UC." << endl;
        cout << "2. Realizar alterações em turmas." << endl;
        cout << "3. Voltar ao menu principal." << endl;
        cout << "Por favor, escolha uma opção (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                // realizar alterações em UC.
                break;
            case 2:
                //  realizar alterações em turmas.
                break;
            case 3:
                cout << "A voltar ao menu principal." << endl;
                break;
            default:
                cout << "Opção inválida. Por favor, escolha uma opção válida (1-3)." << endl;
                break;
        }
    } while (choice != 3);
}
