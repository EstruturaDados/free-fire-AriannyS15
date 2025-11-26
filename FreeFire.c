#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_ITENS 50

typedef struct {
    char nome[50];
    char tipo[50];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU DA MOCHILA =====\n");
        printf("1. Adicionar item\n");
        printf("2. Listar itens\n");
        printf("3. Buscar item por nome\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        if (opcao == 1) {
            if (total >= MAX_ITENS) {
                printf("Mochila cheia. Nao e possivel adicionar mais itens.\n");
            } else {
                printf("Nome do item: ");
                fgets(mochila[total].nome, 50, stdin);
                mochila[total].nome[strcspn(mochila[total].nome, "\n")] = '\0';

                printf("Tipo do item: ");
                fgets(mochila[total].tipo, 50, stdin);
                mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = '\0';

                printf("Quantidade: ");
                scanf("%d", &mochila[total].quantidade);
                getchar();

                total++;
                printf("Item adicionado com sucesso.\n");
            }
        
        } else if (opcao == 2) {
            if (total == 0) {
                printf("A mochila esta vazia.\n");
            } else {
                for (int i = 0; i < total; i++) {
                    printf("\nItem %d:\n", i + 1);
                    printf("Nome: %s\n", mochila[i].nome);
                    printf("Tipo: %s\n", mochila[i].tipo);
                    printf("Quantidade: %d\n", mochila[i].quantidade);
                }
            }

        } else if (opcao == 3) {
            if (total == 0) {
                printf("Nao ha itens para buscar.\n");
            } else {
                char busca[50];
                int encontrado = 0;

                printf("Digite o nome do item que deseja buscar: ");
                fgets(busca, 50, stdin);
                busca[strcspn(busca, "\n")] = '\0';

                for (int i = 0; i < total; i++) {
                    if (strcmp(mochila[i].nome, busca) == 0) {
                        printf("\nItem encontrado:\n");
                        printf("Nome: %s\n", mochila[i].nome);
                        printf("Tipo: %s\n", mochila[i].tipo);
                        printf("Quantidade: %d\n", mochila[i].quantidade);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Item nao encontrado.\n");
                }
            }
        }

    } while (opcao != 0);

    printf("Programa encerrado.\n");
    return 0;
}