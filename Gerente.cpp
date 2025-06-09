#include "Gerente.h"
#include <iostream>
#include <iomanip>

//Implementação dos métodos comuns
void Gerente::setBonusMensal(float bonusMensal){
    this->bonusMensal = bonusMensal;
}
float Gerente::getBonusMensal(){
    return bonusMensal;
}
float Gerente::calcularSalarioFinal(){
    return getSalarioBase() + bonusMensal;
}
void Gerente::exibirInformacoes(){
    Funcionario::exibirInformacoes(); //Reuso da Função base
    cout << "Tipo: Gerente" << endl;
    cout << "Bonus: " << getBonusMensal() << endl;
    cout << fixed << setprecision(2);
    cout << "Salario base: " << salarioBase << endl;
}