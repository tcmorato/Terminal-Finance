#include <iostream>
#include <iomanip>
#include <vector>


void limparTela(){
    system("cls");
}

void armazenarTransf(float transf, std::vector<float> & armazenador){
    armazenador.push_back(transf);
}


//registra movimentação no saldo, seja adição ou subtração
float addTransacao(float saldo, std::vector<float> & extrato) {
    float valorTransf;
    int tipoTransf;
    float novoSaldo;
    bool processo = true;

    while (processo == true)
    {
        limparTela();

        std::cout << "========== REGISTRO DE MOVIMENTAÇÃO ==========\n\n";
        std::cout << "Qual é o tipo de transferência?\n\n"
                    "1- Receita\n"
                    "2- Despesa\n"
                    "3- Voltar\n";
        std::cin >> tipoTransf;
        if (tipoTransf == 3)
        {
            processo = false;
        }
        
        std::cout << "Digite o valor: ";
        std::cin >> valorTransf;

        switch (tipoTransf)
        {
        case 1:
            novoSaldo = saldo + valorTransf;
            std::cout << "Receita: +" << std::fixed << std::setprecision(2) << valorTransf << std::endl;
            std::cout << "Saldo: " << std::fixed << std::setprecision(2) << novoSaldo << std::endl;
            armazenarTransf(valorTransf, extrato);
            break;
        case 2:
            novoSaldo = saldo - valorTransf;
            std::cout << "Receita: -" << std::fixed << std::setprecision(2) << valorTransf << std::endl;
            std::cout << "Saldo: " << std::fixed << std::setprecision(2) << novoSaldo << std::endl;
            armazenarTransf(-valorTransf, extrato);
            break;
        default:
            std::cout << "Digite uma ação válida";
            break;
        }
    }
    
    
    
    return novoSaldo;
}


//mostra o saldo atual
void mostrarSaldo(float saldo) {
    int voltar;

    limparTela();
    std::cout << "========== SALDO ==========\n\n";
    std::cout << "Seu saldo: " << std::fixed << std::setprecision(2) << saldo << std::endl;
    std::cout << "3- Voltar\n";
    std::cin >> voltar;
    if (voltar != 2)
    {
        std::cout << "Digite uma ação válida";
    }
    
}


int main(){
    bool executando = true;
    int proxTela;
    float saldoAtual = 0.0;
    std::vector<float> atualExtrato;
    
    //roda o código
    while (executando)
    {
        limparTela();
        std::cout << " ==================== TERMINAL DE FINANÇAS ====================\n\n";
        

        std::cout << "1- Fazer Transação\n"
                    "2- Ver saldo\n"
                    "3- Ver extrato\n"
                    "4- Sair\n";

        std::cin >> proxTela;
    
        switch (proxTela)
        {
        case 1:
            saldoAtual = addTransacao(saldoAtual, atualExtrato);
            
            break;
        case 2:
            mostrarSaldo(saldoAtual);
            break;
        case 3:
            limparTela();
            std::cout << "========== EXTRATO ==========\n\n";
            for (float t : atualExtrato) {
                std::cout << t << std::fixed << std::setprecision(2) << std::endl;
                
            }
            
            std::cout << "\nPressione ENTER para voltar...";
            std::cin.ignore();
            std::cin.get();
            
            break;
        case 4:
            std::cout << "\n\n\n =========== SISTEMA FECHADO ==========";
            executando = false;
            break;
        default:
            std::cout << "Digite uma tela válida";
            break;
        }
    }
}