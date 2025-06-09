#include "Estagiario.h"
#include <iostream>
#include <iomanip>

//Implementação métodos comuns
int Estagiario::getHorasTrabalhadas(){
    return horasTrabalhadas;
}
void Estagiario::setHorasTrabalhadas(int horasTrabalhadas){
    this->horasTrabalhadas = horasTrabalhadas;
}
float Estagiario::calcularSalarioFinal(){
    return salarioBase * (horasTrabalhadas / 160.0);
    
}
void Estagiario::exibirInformacoes(){
    //Reutilizando a função base
    Funcionario::exibirInformacoes();
    cout << "Tipo: Estagiario" << endl;
    cout << "Horas trabalhadas: " 
    << getHorasTrabalhadas() << endl; 
    cout << fixed << setprecision(2);
    cout << "Salario base: " << salarioBase << endl;

}