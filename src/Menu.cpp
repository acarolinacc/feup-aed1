#include "Menu.h"
#include "DataManager.h"


#include <iostream>


Menu::Menu(DataManager& management) : management_(management) {

}


string to_lower (string str)
{
    for(auto& elem : str)
    {elem = tolower(elem);}
    return str;
}

string to_upper (string str)
{
    for(auto& elem : str)
    {elem = toupper(elem);}
    return str;
}

void Menu::setManagement(const DataManager &management) {
    management_ = management;
}

void Menu::start() {
    int choice;
    do {
        // Menu Principal
        std::cout << "Menu Principal:" << std::endl;
        std::cout << "1. Consultar horários de alunos/turmas/UCs." << std::endl;
        std::cout << "2. Consultar dados de alunos." << std::endl;
        std::cout << "3. Consultar dados de UCs." << std::endl;
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
        std::cout << "3. Consultar horário de UC." << std::endl;
        std::cout << "4. Consultar horário de UC/turma." << std::endl;
        std::cout << "5. Voltar ao menu principal." << std::endl;
        std::cout << "Por favor, escolha uma opção (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                consultarHorarioAluno();
                break;
            case 2:
                consultarHorarioTurma();
                break;
            case 3:
                consultarHorarioUC();
                break;
            case 4:
                consultarHorarioUCTurma();
                break;
            case 5:
                std::cout << "A voltar ao menu principal." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Por favor, escolha uma opção válida (1-5)." << std::endl;
                break;
        }
    } while (choice != 5);
}




//consultar o horário de um aluno
void Menu::consultarHorarioAluno() {

}
//consultar o horário de um aluno




//consultar o horário de uma turma
void Menu::consultarHorarioTurma() {
    std::string classCode;
    std::cout << "--------------------------------------------------\n";
    std::cout << "Por favor, insira o código da turma ";
    std::cin >> classCode;
    std::cout << std::endl;

    bool isValid = false;
    const std::vector<ClassUC>& allUCs = management_.getAllUC();

    for (const ClassUC& uc : allUCs) {
        if (isClassCodeValid(classCode, uc.getClassCode())) {
            isValid = true;
            displayClassSchedule(uc);
        }
    }

    if (!isValid) {
        std::cout << "That's not a valid input." << std::endl;
    }
}

bool Menu::isClassCodeValid(const std::string& input, const std::string& target) const {
    return to_lower(input) == to_lower(target);
}

void Menu::displayClassSchedule(const ClassUC& uc) const {
    std::cout << uc.getUcCode() << std::endl;

    for (const Slot& a : uc.getSchedule()) {
        std::cout << '\t' << a.getDay() << ' ' << a.getStart() << ' ' << a.getDuration() << ' ' << a.getType() << '\n';
    }
}
//consultar o horário de uma turma



//consultar o horário de uma UC
void Menu::consultarHorarioUC() {
    std::string ucCode;

    std::cout << "--------------------------------------------------\n";
    std::cout << "Digite o Código da UC: ";
    std::cin >> ucCode;
    std::cout << std::endl;

    const std::vector<ClassUC>& todasAsTurmas = management_.getAllUC();
    bool encontrouUC = false;

    for (const ClassUC& turma : todasAsTurmas) {
        if (correspondeCodigoUC(turma, ucCode)) {
            encontrouUC = true;
            exibirHorarioDaUC(turma);
        }
    }

    if (!encontrouUC) {
        std::cout << "Código de UC inválido." << std::endl;
    }
}

bool Menu::correspondeCodigoUC(const ClassUC& turma, const std::string& ucCode) const {
    return compararIgnorandoMaiusculas(turma.getUcCode(), ucCode);
}

void Menu::exibirHorarioDaUC(const ClassUC& turma) const {
    std::cout << turma.getClassCode() << std::endl;
    for (const Slot& horario : turma.getSchedule()) {
        std::cout << '\t' << horario.getDay() << ' ' << horario.getStart() << ' ' << horario.getDuration() << ' ' << horario.getType() << '\n';
    }
}

bool Menu::compararIgnorandoMaiusculas(const std::string& str1, const std::string& str2) const {
    // Função para comparar strings ignorando maiúsculas e minúsculas
    return to_lower(str1) == to_lower(str2);
}

//consultar o horário de uma UC




//consultar o horário de uma UC/Turma
void Menu::consultarHorarioUCTurma() {
    std::string uccode;
    std::string classcode;

    std::cout << "--------------------------------------------------\n";
    std::cout << "Digite o Código da UC: ";
    std::cin >> uccode;
    std::cout << "Digite o Código da Turma: ";
    std::cin >> classcode;
    std::cout << std::endl;

    const std::vector<ClassUC>& todasAsTurmas = management_.getAllUC();
    bool encontrouTurma = false;

    for (const ClassUC& turma : todasAsTurmas) {
        if (correspondeCodigoUcETurma(turma, uccode, classcode)) {
            encontrouTurma = true;
            exibirHorarioDaTurma(turma);
        }
    }

    if (!encontrouTurma) {
        std::cout << "Código de UC ou Turma inválido." << std::endl;
    }
}

bool Menu::correspondeCodigoUcETurma(const ClassUC& turma, const std::string& uccode, const std::string& classcode) const {
    return (compararIgnorandoMaiusculas(turma.getUcCode(), uccode) && compararIgnorandoMaiusculas(turma.getClassCode(), classcode));
}

void Menu::exibirHorarioDaTurma(const ClassUC& turma) const {
    std::cout << turma.getUcCode() << " -- " << turma.getClassCode() << std::endl;
    for (const Slot& horario : turma.getSchedule()) {
        std::cout << '\t' << horario.getDay() << ' ' << horario.getStart() << ' ' << horario.getDuration() << ' ' << horario.getType() << '\n';
    }
}

//consultar o horário de uma UC/Turma




void Menu::consultarInformacoesAlunos() {
    cout << "Página de Consulta de Dados de Alunos:" << endl;
    cout << "1. Consultar alunos por turma ou ano." << endl;
    cout << "2. Consultar número de estudantes inscritos em, pelo menos, n UCs." << endl;
    cout << "Por favor, escolha uma opção (1-3): ";

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
    // Consultar alunos por turma ou ano.
    cout << "Página de Consulta de Alunos por Turma ou Ano." << endl;

    int opcao;
    cout << "Escolha uma opção:" << endl;
    cout << "1. Consultar alunos por UCs e por turmas." << endl;
    cout << "2. Consultar alunos por ano." << endl;
    cout << "3. Voltar ao menu principal." << endl;

    cout << "Por favor, escolha uma opção (1-3): ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            consultarAlunosPorTurma();
            break;
        case 2:
            consultarAlunosPorAno();
            break;
        case 3:
            // Voltar ao menu principal.
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
    }
}





//Consultar alunos por UCs e por turmas
void Menu::consultarAlunosPorTurma() {
    cout << "Consulta de Alunos por UCs e Turmas" << endl;

    string ucCode;
    cout << "Por favor, insira o código da UC: ";
    cin >> ucCode;

    string classCode;
    cout << "Por favor, insira o código da turma: ";
    cin >> classCode;

    cout << "Alunos pertencentes à UC " << ucCode << " e à turma " << classCode << ":" << endl;

    bool alunosEncontrados = false;

    for (const Student& student : management_.getStudents()) {
        if (studentBelongsToUCAndClass(student, ucCode, classCode)) {
            alunosEncontrados = true;
            cout << "Nome do aluno: " << student.getName() << endl;
            cout << "Número de estudante: " << student.getCode() << endl;
            cout << endl;
        }
    }

    if (!alunosEncontrados) {
        cout << "Nenhum aluno encontrado para a UC e turma especificadas." << endl;
    }
}

bool Menu::studentBelongsToUCAndClass(const Student& student, const string& ucCode, const string& classCode) {
    for (const ClassUC& classUC : student.getclassUC()) {
        if (to_lower(classUC.getUcCode()) == to_lower(ucCode) &&
            to_lower(classUC.getClassCode()) == to_lower(classCode)) {
            return true;
        }
    }
    return false;
}
//Consultar alunos por UCs e por turmas






//Consultar alunos por Ano
void Menu::consultarAlunosPorAno() {
    cout << "Consultar alunos por ano (1-3)." << endl;

    char yearChar;
    cout << "Por favor, insira o ano (1-3): ";
    cin >> yearChar;
    cout << endl;

    if (yearChar >= '1' && yearChar <= '3') {
        for (const Student& student : management_.getStudents()) {
            for (const ClassUC& classUC : student.getclassUC()) {
                if (classUC.getClassCode().front() == yearChar) {
                    cout << "Nome do aluno: " << student.getName() << endl;
                    cout << "Número de estudante: " << student.getCode() << endl;
                    cout << "Código da Turma: " << classUC.getClassCode() << endl;
                    cout << endl;
                }
            }
        }
    } else {
        cout << "Ano inválido. Insira um ano de 1 a 3." << endl;
    }
}
//Consultar alunos por Ano




void Menu::consultarNumEstudantesInscritosN_UC() {
    // consultar o número de estudantes inscritos em pelo menos n UCs.
    cout << "Consultar o número de estudantes inscritos em pelo menos n UCs" << endl;
}



void Menu::consultarInformacoesUCs() {
    cout << "Página de Consulta de Dados de UCs." << endl;

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