#include <iostream>
#include <iomanip>



float addTransacao(float saldo) {
    float valorTransf;
    int tipoTransf;
    float novoSaldo;

    std::cout << "Digite o valor: ";
    std::cin >> valorTransf;
    std::cout << "Qual é o tipo de transferência?\n\n"
                 "1- Receita\n"
                 "2- Despesa\n"
                 "3- Voltar\n";
    std::cin >> tipoTransf;
    switch (tipoTransf)
    {
    case 1:
        novoSaldo = saldo + valorTransf;
        std::cout << "Receita: +" << std::fixed << std::setprecision(2) << valorTransf << std::endl;
        std::cout << "Saldo: " << std::fixed << std::setprecision(2) << novoSaldo << std::endl;
        break;
    case 2:
        novoSaldo = saldo - valorTransf;
        std::cout << "Receita: -" << std::fixed << std::setprecision(2) << valorTransf << std::endl;
        std::cout << "Saldo: " << std::fixed << std::setprecision(2) << novoSaldo << std::endl;
    default:
        std::cout << "Digite uma ação válida";
        break;
    }
    
    return novoSaldo;
}


//mostra o saldo atual
void mostrarSaldo(float saldo) {
    int voltar;

    std::cout << "Seu saldo: " << std::fixed << std::setprecision(2) << saldo;
    std::cout << "\n3- Voltar\n";
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
    
    while (executando)
    {
        std::cout << " ==================== TERMINAL DE FINANÇAS ====================\n\n";
        

        std::cout << "1- Fazer Transação\n"
                    "2- Ver saldo\n"
                    "3- Sair\n";
        std::cin >> proxTela;
    
        switch (proxTela)
        {
        case 1:
            saldoAtual = addTransacao(saldoAtual);
            break;
        case 2:
            mostrarSaldo(saldoAtual);
            break;
        case 3:
            std::cout << "\n\n\n =========== SISTEMA FECHADO ==========";
            executando = false;
            break;
        default:
            std::cout << "Digite uma tela válida";
            break;
        }
    }
}