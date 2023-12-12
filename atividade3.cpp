#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

void realizarCompra(struct Produto *produto) {
    int quantidadeCompra;
    printf("digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra <= produto->quantidadeEstoque) {
        float valorTotal = quantidadeCompra * produto->preco;
        produto->quantidadeEstoque -= quantidadeCompra;
        printf("compra realizada com sucesso. valor total: R$ %.2f\n", valorTotal);
    } else {
        printf("quantidade indisponível em estoque.\n");
    }
}

void consultarEstoque(const struct Produto *produto) {
    printf("nome do produto: %s\n", produto->nome);
    printf("quantidade em estoque: %d\n", produto->quantidadeEstoque);
}

int main() {
    struct Produto meuProduto = {"produto Exemplo", 10.99, 50};

    int escolha;

    do {
        printf("\nmenu:\n");
        printf("1 - realizar uma compra\n");
        printf("2 - consultar estoque\n");
        printf("3 - sair do programa\n");
        printf("escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                realizarCompra(&meuProduto);
                break;
            case 2:
                consultarEstoque(&meuProduto);
                break;
            case 3:
                printf("saindo do programa\n");
                break;
            default:
                printf("opcao invalida. Tente novamente\n");
        }
    } while (escolha != 3);

    return 0;
}
