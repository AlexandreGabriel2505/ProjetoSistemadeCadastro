#ifndef DESENVOLVEDOR_H
#define DESENVOLVEDOR_H
#include "Funcionario.h"
#include <string>
using namespace std;

//Herança da Classe Funcionário
class Desenvolvedor : public Funcionario {
//Atributos    
private:
    int quantidadeDeProjetos;
public:
    //Métodos comuns
    int getQuantidadeDeProjetos();
    void setQuantidadeDeProjetos(int);
    //Sobrescrita (Polimorfismo)
    float calcularSalarioFinal() override;
    void exibirInformacoes() override;

};


#endif
