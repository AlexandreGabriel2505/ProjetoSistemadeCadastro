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

    //Pergunta quantos funcionários o usuário deseja cadastrar
    int quantidade = 0;
    while(true) {
        cout << "Quantos Funcionários deseja cadastrar ? (min 6, max 10): ";
        cin >> quantidade;

        if (cin.fail()) { 
            cin.clear();
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida! Digite um numero.\n";
            continue;
        }
        if (quantidade < 6 || quantidade > 10) {
            cout << "Numero fora do intervalo. Tente novamente.\n";
            continue;
        }
        
        break;
    }
    
    //Cadastro dos funcionários
    for(int i = 0; i < quantidade; i++) {
        cout << "\nCadastro do Funcionario " << (i + 1) << endl;
        cout << "Tipo (1 - Desenvolvedor, 2 - Gerente, 3 - Estagiario): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int tipo;
        cin >> tipo;

        //Verifica se a entrada do tipo é invalida
        if (cin.fail() || tipo < 1 || tipo > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Tipo invalido. Tente novamente.\n";
            i--; //volta uma iteração para repetir o cadastro
            continue;
        }

        //Instanciando e armazenando no vetor
        cin.ignore();
        Funcionario* f = nullptr;

        if (tipo == 1){
            f = new Desenvolvedor();
            string nome;
            int id, qtdProjetos;
            float salario;
            
            cout << "ID: "; 
            cin >> id;
            cout << "Nome: ";
            cin >> nome;
            cout << "Projetos: ";
            cin >> qtdProjetos;
            cout << "Salario base: ";
            cin >> salario;

            f->setId(id);
            f->setNome(nome);
            f->setSalarioBase(salario);
            static_cast <Desenvolvedor*>(f)->setQuantidadeDeProjetos(qtdProjetos);
        }
        else if (tipo == 2){
            f = new Gerente();
            string nome;
            int id, bonus;
            float salario;

            cout << "ID: ";
            cin >> id;
            cout << "Nome: ";
            cin >> nome;
            cout << "Salario base: ";
            cin >> salario;
            cout << "Bonus: ";
            cin >> bonus;

            f->setId(id);
            f->setNome(nome);
            f->setSalarioBase(salario);
            static_cast<Gerente*>(f)->setBonusMensal(bonus);   
        }
        else if (tipo == 3){
            f = new Estagiario();
            string nome;
            int id;
            float salario, horas;

            cout << "ID: ";
            cin >> id;
            cout << "Nome: ";
            cin >> nome;
            cout << "Horas trabalhadas: ";
            cin >> horas;
            cout << "Salario base: ";
            cin >> salario;

            f->setId(id);
            f->setNome(nome);
            f->setSalarioBase(salario);
            static_cast<Estagiario*>(f)->setHorasTrabalhadas(horas);  
        }
        funcionarios[i] = f; //armazena o ponteiro no vetor
        
    }
    //Exibe as informações dos funcionários cadastrados
    cout << fixed << setprecision(2); //mostra o valor com duas casas decimais
    cout << "\n--- Relatorio dos Funcionarios ---\n";

    for (int i = 0; i < quantidade; i++){
    funcionarios[i]->exibirInformacoes();
    cout << "Salario final: " << funcionarios[i]->calcularSalarioFinal() << endl;
    cout << "-----------------------" << endl;
    }
    
    return 0;
}

