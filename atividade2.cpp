#include <stdio.h>
#include <stdlib.h>


struct Aluno {
    char nome[50];
    char dataNascimento[20];
    double nota1;
    double nota2;
    double media;
};


double calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2.0;
}


char* verificarAprovacao(struct Aluno aluno) {
    if (aluno.media >= 7.0) {
        return "aprovado";
    } else {
        return "reprovado";
    }
}

int main() {
    struct Aluno alunos[5]; 

   
    for (int i = 0; i < 5; ++i) {
        printf("aluno %d:\n", i + 1);
        printf("nome: ");
        scanf("%s", alunos[i].nome);
        printf("data de Nascimento: ");
        scanf("%s", alunos[i].dataNascimento);
        printf("nota 1: ");
        scanf("%lf", &alunos[i].nota1);
        printf("nota 2: ");
        scanf("%lf", &alunos[i].nota2);

        
        alunos[i].media = calcularMedia(alunos[i]);
    }

    
    printf("\nmedia e situacao dos alunos:\n");
    for (int i = 0; i < 5; ++i) {
        printf("aluno %s: media = %.2lf, situacao = %s\n", alunos[i].nome, alunos[i].media, verificarAprovacao(alunos[i]));
    }

    return 0;
}
