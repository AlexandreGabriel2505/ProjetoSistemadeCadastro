#include "Desenvolvedor.h"
#include <iostream>
#include <iomanip>

//Implementação dos métodos comuns
int Desenvolvedor::getQuantidadeDeProjetos(){
    return quantidadeDeProjetos;
}
void Desenvolvedor::setQuantidadeDeProjetos(int quantidadeDeProjetos){
    this->quantidadeDeProjetos = quantidadeDeProjetos;
}
//Calculo do Salario final
float Desenvolvedor::calcularSalarioFinal(){
    return getSalarioBase() + (500 * quantidadeDeProjetos);
}
//Exibe as insformaçoes do Desenvolvedor
void Desenvolvedor::exibirInformacoes(){
    //Reutilizando a função base
    Funcionario::exibirInformacoes();
    cout << "Tipo: Desenvolvedor" << endl;
    cout << "Projetos: " << getQuantidadeDeProjetos() << endl;
    cout << fixed << setprecision(2);
    cout << "Salario base: " << salarioBase << endl;
    
}
