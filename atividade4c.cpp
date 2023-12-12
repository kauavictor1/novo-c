#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ContaBancaria {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[20];
};


void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("deposito de R$ %.2f realizado com sucesso.\n", valor);
}


void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > conta->saldo) {
        printf("saldo insuficiente para saque.\n");
    } else {
        conta->saldo -= valor;
        printf("saque de R$ %.2f realizado com sucesso.\n", valor);
    }
}


void imprimirSaldo(const struct ContaBancaria *conta) {
    printf("saldo atual: R$ %.2f\n", conta->saldo);
}

int main() {
    
    struct ContaBancaria minhaConta = {123, "fulano", 1000.0, "corrente"};

    int escolha;
    float valor;

    do {
        printf("\nmenu de Operacoes:\n");
        printf("1. depositar\n");
        printf("2. sacar\n");
        printf("3. verificar Saldo\n");
        printf("4. Sair\n");
        printf("Escolha uma operacao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("digite o valor para depositar: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("digite o valor para sacar: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                imprimirSaldo(&minhaConta);
                break;
            case 4:
                printf("saindo...\n");
                break;
            default:
                printf("opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}
