#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
using namespace std;

//Classe Abstrata
class Funcionario {
//Atributos            
protected:
    string nome;
    float salarioBase;
private:
    int id;
//Métodos públicos    
public:
    //Métodos Get e Set
     string getNome();
     void setNome(string);

     float getSalarioBase();
     void setSalarioBase(float);

     int getId();
     void setId(int);
    //Método virtual comum
     virtual void exibirInformacoes();
    //Método virtual puro
     virtual float calcularSalarioFinal() = 0;
    //Destrutor 
     virtual ~Funcionario() {}
};

#endif