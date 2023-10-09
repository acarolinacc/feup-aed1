#ifndef TURMA_H
#define TURMA_H

#include <string>
#include <list>
#include "Sloth.h"

using namespace std;

class Turma {
public:
    Turma(int code);
    
    int getCode() const;
    
    void addSloth(const Sloth& sloth);

    void removeSloth(const Sloth& sloth);
    
    const list<Sloth>& getSloths() const;

private:
    int code; 
    list<Sloth> sloths;
};

#endif
