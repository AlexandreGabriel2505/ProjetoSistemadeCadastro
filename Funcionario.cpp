#include "Funcionario.h"
#include <iostream>

//Implementação dos métodos comuns
string Funcionario::getNome(){
    return nome;
}
void Funcionario::setNome(string nome){
    this->nome = nome;
}
float Funcionario::getSalarioBase(){
    return salarioBase;
}
void Funcionario::setSalarioBase(float salarioBase){
    this->salarioBase = salarioBase;
}
int Funcionario::getId(){
    return id;
}
void Funcionario::setId(int id){
    this->id = id;
}

void Funcionario::exibirInformacoes(){
    cout << "ID: " << getId() << endl;
    cout << "Nome: " << getNome() << endl;
}


