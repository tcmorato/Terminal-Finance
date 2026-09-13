#include <iostream>
#include <iomanip>
#include <vector>


void limparTela(){
    system("cls");
}

struct Transacao
{
    float valor;
    int tipo;
};


void armazenarTransf(const Transacao & transacao, std::vector<Transacao> & armazenador){
    armazenador.push_back(transacao);
}


//registra movimentação no saldo, seja adição ou subtração
float addTransacao(float saldo, std::vector<Transacao> & extrato) {
    
    Transacao novaTransacao;
    float novoSaldo;
    bool selecionouTipo = false;
    bool digitouValor = false;
    limparTela();

    while (selecionouTipo == false)
    {
        std::cout << "========== REGISTRO DE MOVIMENTAÇÃO ==========\n\n";
        std::cout << "Qual é o tipo de transferência?\n\n"
                    "1- Receita\n"
                    "2- Despesa\n"
                    "3- Voltar\n";
        std::cin >> novaTransacao.tipo;
        if (std::cin.fail())
        {
            std::cout << "Erro! Digite um tipo válido\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        else if (novaTransacao.tipo != 1 && novaTransacao.tipo != 2 && novaTransacao.tipo != 3) {
            std::cout << "Erro! Digite um tipo válido.\n";
            continue;
        }

        else{
            selecionouTipo = true;
        }
    }

    if (novaTransacao.tipo == 3)
    {
        return saldo;
    }
    
    while (digitouValor == false)
    {
    
        std::cout << "Digite o valor: ";
        std::cin >> novaTransacao.valor;
        if (std::cin.fail())
        {
            std::cout << "Erro! Digite um número valido.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        else {
            digitouValor = true;
        }
    }

    switch (novaTransacao.tipo)
    {
    case 1:
        novoSaldo = saldo + novaTransacao.valor;
        std::cout << "Receita: +" << std::fixed << std::setprecision(2) << novaTransacao.valor << std::endl;
        std::cout << "Saldo: " << std::fixed << std::setprecision(2) << novoSaldo << std::endl;
        break;
    case 2:
        novoSaldo = saldo - novaTransacao.valor;
        std::cout << "Despesa: -" << std::fixed << std::setprecision(2) << novaTransacao.valor << std::endl;
        std::cout << "Saldo: " << std::fixed << std::setprecision(2) << novoSaldo << std::endl;
        break;
    }
    armazenarTransf(novaTransacao, extrato);
    return novoSaldo;    
}


//mostra o saldo atual
void mostrarSaldo(float saldo) {

    limparTela();
    std::cout << "========== SALDO ==========\n\n";
    std::cout << "Seu saldo: " << std::fixed << std::setprecision(2) << saldo << std::endl;
    std::cout << "\nPressione ENTER para voltar...";
    
    std::cin.ignore();
    std::cin.get();

}

int main(){
    bool executando = true;
    int proxTela;
    float saldoAtual = 0.0;
    std::vector<Transacao> atualExtrato;
    
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
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        

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

            std::cout << std::fixed << std::setprecision(2);

            for (Transacao t : atualExtrato) {
                std::cout << "Valor: " << t.valor;
                if (t.tipo == 1)
                {
                    std::cout << " | Receita" << std::endl;
                }
                else if (t.tipo == 2)
                {
                    std::cout << " | Despesa" << std::endl;
                }
                
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