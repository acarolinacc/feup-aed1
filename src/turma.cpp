#include "Turma.h"

using namespace std;

Turma::Turma(int code) : code(code) {}

int Turma::getCode() const {
    return code;
}

void Turma::addSloth(const Sloth& sloth) {
    sloths.push_back(sloth);
}

const list<Sloth>& Turma::getSloths() const {
    return sloths;
}

