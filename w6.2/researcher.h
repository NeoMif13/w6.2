#pragma once

#include "person.h"
#include <string>
using namespace std;

class Researcher : public Person {
private:
    string degree;
    string contractNumber;

public:
    Researcher(const string& name, const string& deg, const string& contract);

    
    void print() const override;
    virtual ~Researcher() {}
};



