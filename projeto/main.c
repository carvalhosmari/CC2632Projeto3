#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    int input, cod, input2;
    ListaTarefas lista;

    cod = carregaTarefas(&lista, "arquivo");

    if (cod != 0) {
        lista.qtd = 0;
    }

    do {
        imprimeMenu();

        scanf("%d", &input);

        if (input == 0) {
            //encerra o programa
        } else if (input == 1) {
            cod = criaTarefa(&lista);

            if (cod != 0) {
                printf("Nao foi possivel cadastrar a tarefa!\n\n");
            } else {
                cod = cadastraTarefa(&lista, "arquivo");

                if (cod == 0) {
                    printf("Tarefa cadastrada com sucesso!\n\n");
                } else {
                    printf("Erro ao abrir arquivo de destino!\n\n");
                }
            }

            system("pause");
        } else if (input == 2) {
            do {
                imprimeMenuListar();

                scanf("%d", &input2);

                if (input2 == 0) {
                    //encerra o loop
                    break;
                } else if (input2 == 1) {
                    cod = listaTarefas(&lista);
                } else if (input2 == 2) {
                    cod = listaTarefasPorPrioridade(&lista);
                } else if (input2 == 3) {
                    //lista por status
                } else if (input2 == 4) {
                    //lista por categ
                } else if (input2 == 5) {
                    //lista por prioridade e categ
                } else {
                    printf("\nOpcao invalida!\n\n");
                }

                if (cod == 1) {
                    printf("Lista de tarefas vazia!\n\n");
                }

                system("pause");
            } while (input2 != 0);
        } else if (input == 3) {
            cod = deletaTarefa(&lista);

            if (cod == 0) {
                printf("Tarefa deletada com sucesso!\n\n");
            } else if (cod == 1) {
                printf("Lista de tarefas vazia!\n\n");
            } else {
                printf("Tarefa nao encontrada!\n\n");
            }

            system("pause");
        } else if (input == 4) {
            cod = editaTarefa(&lista);

            if (cod == 0) {
                printf("\nTarefa editada com sucesso!\n\n");
            } else if (cod == -1) {
                printf("\nTarefa nao encontrada!\n\n");
            } else if (cod == 1) {
                printf("\nLista de tarefas vazia!\n\n");
            }
        } else if (input == 5) {
            do {
                imprimeMenuExportar();

                scanf("%d", &input2);

                if (input2 == 0) {
                    //encerra o loop
                    break;
                } else if (input2 == 1) {
                    //exportar todas as tarefas
                } else if (input2 == 2) {
                    //exportar por prioridade
                } else if (input2 == 3) {
                    //exportar por status
                } else if (input2 == 4) {
                    //exportar por categ
                } else if (input2 == 5) {
                    //exportar por prioridade e categ
                } else {
                    printf("\nOpcao invalida!\n\n");
                }

                if (cod == 1) {
                    printf("Lista de tarefas vazia!\n\n");
                }

                system("pause");
            } while (input2 != 0);
        } else {
            printf("\nOpcao invalida!\n\n");
        }
    } while (input != 0);

}
