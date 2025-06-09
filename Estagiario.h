#ifndef ESTAGIARIO_H
#define ESTAGIARIO_H
#include "Funcionario.h"
#include <string>
using namespace std;

//Herança da Classe Funcionário
class Estagiario : public Funcionario{
private:
    int horasTrabalhadas;
public:
    int getHorasTrabalhadas();
    void setHorasTrabalhadas(int);
     
    //Sobrescrita (Polimorfismo)
    float calcularSalarioFinal() override;
    void exibirInformacoes() override;
};





#endif