#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_ITENS 10  // Define o número máximo de itens na mochila

// Estrutura que representa um item da mochila
struct Item {
    char nome[30];      // Nome do item
    char tipo[20];      // Tipo do item (ex: arma, poção, munição)
    int quantidade;     // Quantidade do item
};

int main() {
    struct Item mochila[MAX_ITENS];  // Vetor de até 10 itens
    int total = 0;                   // Quantidade atual de itens cadastrados
    int opcao;                       // Armazena a opção escolhida no menu
    char nomeBusca[30];              // Nome do item a ser removido

    do {
        // Exibe o menu principal
        printf("\n===== INVENTARIO BASICO =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado (evita problemas com fgets)

        switch (opcao) {
            case 1:
                // Adicionar um novo item
                if (total < MAX_ITENS) {
                    printf("\nNome do item: ");
                    fgets(mochila[total].nome, 30, stdin);
                    mochila[total].nome[strcspn(mochila[total].nome, "\n")] = 0; // Remove o \n do final

                    printf("Tipo do item: ");
                    fgets(mochila[total].tipo, 20, stdin);
                    mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = 0;

                    printf("Quantidade: ");
                    scanf("%d", &mochila[total].quantidade);
                    getchar(); // Limpa o buffer novamente

                    total++; // Incrementa o número total de itens cadastrados
                    printf("\nItem adicionado com sucesso!\n");
                } else {
                    printf("\nA mochila esta cheia! Nao e possivel adicionar mais itens.\n");
                }
                break;

            case 2:
                // Remover item pelo nome
                if (total > 0) {
                    printf("\nDigite o nome do item para remover: ");
                    fgets(nomeBusca, 30, stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = 0;

                    int encontrado = 0;
                    for (int i = 0; i < total; i++) {
                        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                            // Move todos os itens seguintes uma posição para trás
                            for (int j = i; j < total - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            total--; // Diminui o total de itens
                            encontrado = 1;
                            printf("\nItem removido com sucesso!\n");
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("\nItem nao encontrado.\n");
                    }
                } else {
                    printf("\nNao ha itens para remover.\n");
                }
                break;

            case 3:
                // Listar todos os itens cadastrados
                if (total > 0) {
                    printf("\nITENS CADASTRADOS:\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("---------------------------------------------\n");
                    for (int i = 0; i < total; i++) {
                        printf("%-20s %-15s %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                } else {
                    printf("\nNenhum item cadastrado.\n");
                }
                break;

            case 0:
                // Encerra o programa
                printf("\nSaindo do inventario...\n");
                break;

            default:
                // Caso o usuário digite uma opção inválida
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0); // Repete até o usuário escolher sair

    return 0;
}
