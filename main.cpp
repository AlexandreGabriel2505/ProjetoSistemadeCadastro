#include <iostream>
#include <iomanip>
#include <limits>
#include "Funcionario.h"
#include "Desenvolvedor.h"
#include "Gerente.h"
#include "Estagiario.h"

using namespace std;

int main() {
    //Criação do vetor de ponteiros
    const int Max_Funcionarios = 10;

    Funcionario *funcionarios[Max_Funcionarios];

    //Cadastro dos funcionarios
    int quantidadeFuncionarios = 0;

    while(quantidadeFuncionarios < 6){
        //Dados específicos conforme o tipo
        cout << "\nCadastro do Funcionario " 
        << (quantidadeFuncionarios + 1) << endl;
        cout << "Tipo (1 - Desenvolvedor, 2 - Gerente, 3 - Estagiario): ";
        int tipo;
        cin >> tipo; 
        // Valida a entrada do usuário para evitar erros
        if (cin.fail()) {
            cout << "Erro: Entrada invalida. Por favor, digite um numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        //Instanciando e armazenando no vetor
        Funcionario* f = nullptr;

        if (tipo == 1){
            f = new Desenvolvedor();
            string nome;
            int id, qtdProjetos;
            float salario;
            
            cout << "ID: ";
            cin >> id;
            f->setId(id);
            cout << "Nome: ";
            cin >> nome;
            f->setNome(nome);
            cout << "Projetos: ";
            cin >> qtdProjetos;
            static_cast <Desenvolvedor*>(f)->setQuantidadeDeProjetos(qtdProjetos);
            cout << "Salario base: ";
            cin >> salario;
            f->setSalarioBase(salario);
        }
        else if (tipo == 2){
            f = new Gerente();
            string nome;
            int id, bonus;
            float salario;

            cout << "ID: ";
            cin >> id;
            f->setId(id);
            cout << "Nome: ";
            cin >> nome;
            f->setNome(nome);
            cout << "Salario base: ";
            cin >> salario;
            f->setSalarioBase(salario);
            cout << "Bonus: ";
            cin >> bonus;
            static_cast<Gerente*>(f)->setBonusMensal(bonus);
        }
        else if (tipo == 3){
            f = new Estagiario();
            string nome;
            int id;
            float salario, horas;

            cout << "ID: ";
            cin >> id;
            f->setId(id);
            cout << "Nome: ";
            cin >> nome;
            f->setNome(nome);
            cout << "Horas trabalhadas: ";
            cin >> horas;
            static_cast<Estagiario*>(f)->setHorasTrabalhadas(horas);
            cout << "Salario base: ";
            cin >> salario;
            f->setSalarioBase(salario);
        } else {
            cout << "Tipo invalido, tente novamente."
            << endl;
            continue;
        }
        funcionarios[quantidadeFuncionarios] = f;
        quantidadeFuncionarios++;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //Percorrendo o vetor / Relatório dos funcionários (Polimorfismo)
    cout << fixed << setprecision(2); //Formatação numérica
    cout << "\n--- Relatorio dos Funcionarios ---\n";
    for (int i = 0; i < quantidadeFuncionarios; i++){
        funcionarios[i]->exibirInformacoes();
        cout << "Salario final: " << funcionarios[i]->calcularSalarioFinal() << endl;
        cout << "-----------------------" << endl;
    }
    //Liberação da memoria
    for (int i = 0; i < quantidadeFuncionarios; i++){
        delete funcionarios[i];
    }
    return 0;
}
