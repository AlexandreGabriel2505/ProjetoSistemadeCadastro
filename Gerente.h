#ifndef GERENTE_H
#define GERENTE_H
#include "Funcionario.h"
#include <string>
using namespace std;

//Herança da Classe Funcionário
class Gerente : public Funcionario {
private:
    float bonusMensal;
public:
    float getBonusMensal();
    void setBonusMensal(float);
    //Sobrescrita (Polimorfismo)    
    float calcularSalarioFinal() override;
    void exibirInformacoes() override;
};











#endif