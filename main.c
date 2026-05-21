#include<stdio.h>
#include<stdlib.h>

#define MAX_HISTORICO 3

void exibirMenu();
void consultarSaldo(float saldo);
float realizarDeposito(float saldo);
float realizarSaque(float saldo);
void exibirExtrato(float historicoValores[], char historicoTipos[], int totalTransacoes, float saldoAtual);
void registrarTransacao(float historicoValores[], char historicoTipos[], int *totalTransacoes, float valor, char tipo);




