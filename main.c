#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORICO 3

void exibirMenu() {
    printf("\n========================\n");
    printf("    CAIXA ELETRONICO    \n");
    printf("========================\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Realizar Saque\n");
    printf("3 - Realizar Deposito\n");
    printf("4 - Exibir Extrato\n");
    printf("0 - Sair\n");
    printf("========================\n");
    printf("Escolha uma opcao: ");
}

void consultarSaldo(float saldo) {
    printf("\n--- SALDO ATUAL ---\n");
    printf("R$ %.2f\n", saldo);
    printf("-------------------\n");
}

void registrarTransacao(float historicoValores[], char historicoTipos[], int *totalTransacoes, float valor, char tipo) {
    if (*totalTransacoes < MAX_HISTORICO) {
        historicoValores[*totalTransacoes] = valor;
        historicoTipos[*totalTransacoes] = tipo;
        (*totalTransacoes)++;
    } else {
        for (int i = 0; i < MAX_HISTORICO - 1; i++) {
            historicoValores[i] = historicoValores[i + 1];
            historicoTipos[i] = historicoTipos[i + 1];
        }
        historicoValores[MAX_HISTORICO - 1] = valor;
        historicoTipos[MAX_HISTORICO - 1] = tipo;
    }
}

float realizarSaque(float saldo, float historicoValores[], char historicoTipos[], int *totalTransacoes) {
    float valor;
    printf("Valor do saque: ");
    scanf("%f", &valor);
    if (valor <= saldo && valor > 0) {
        saldo -= valor;
        registrarTransacao(historicoValores, historicoTipos, totalTransacoes, valor, 'S');
        printf("Saque realizado!\n");
    } else {
        printf("Saldo insuficiente ou valor invalido!\n");
    }
    return saldo;
}

float realizarDeposito(float saldo, float historicoValores[], char historicoTipos[], int *totalTransacoes) {
    float valor;
    printf("Digite o valor do deposito: ");
    scanf("%f", &valor);
    if (valor > 0) {
        saldo += valor;
        registrarTransacao(historicoValores, historicoTipos, totalTransacoes, valor, 'D');
        printf("Deposito realizado!\n");
    } else {
        printf("Valor invalido!\n");
    }
    return saldo;
}

void exibirExtrato(float historicoValores[], char historicoTipos[], int totalTransacoes, float saldoAtual) {
    printf("\n--- EXTRATO (Ultimas %d transacoes) ---\n", MAX_HISTORICO);
    if (totalTransacoes == 0) {
        printf("Nenhuma transacao realizada.\n");
    } else {
        for (int i = 0; i < totalTransacoes; i++) {
            if (historicoTipos[i] == 'S') {
                printf("[-] Saque:    R$ %.2f\n", historicoValores[i]);
            } else if (historicoTipos[i] == 'D') {
                printf("[+] Deposito: R$ %.2f\n", historicoValores[i]);
            }
        }
    }
    printf("-------------------------------------\n");
    printf("Saldo Atual: R$ %.2f\n", saldoAtual);
    printf("-------------------------------------\n");
}
int main() {
    float saldo = 0.0;
    int opcao;
    float historicoValores[MAX_HISTORICO];
    char historicoTipos[MAX_HISTORICO];
    int totalTransacoes = 0;

    do {
        exibirMenu();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                saldo = realizarSaque(saldo, historicoValores, historicoTipos, &totalTransacoes);
                break;
            case 3:
                saldo = realizarDeposito(saldo, historicoValores, historicoTipos, &totalTransacoes);
                break;
            case 4:
                exibirExtrato(historicoValores, historicoTipos, totalTransacoes, saldo);
                break;
            case 0:
                printf("Saindo do sistema. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
            getchar();
        }
    } while(opcao != 0);
    return 0;
}
