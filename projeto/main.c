#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    int input, cod, input2;
    ListaTarefas lista, listaProv;

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
                    cod = filtraTarefas(&lista, &listaProv, 1);
                    cod = listaTarefas(&listaProv);
                } else if (input2 == 3) {
                    cod = filtraTarefas(&lista, &listaProv, 2);
                    cod = listaTarefas(&listaProv);
                } else if (input2 == 4) {
                    cod = filtraTarefas(&lista, &listaProv, 3);
                    qsort(listaProv.tarefas, listaProv.qtd, sizeof(Tarefa), comparaInteiros);
                    cod = listaTarefas(&listaProv);
                } else if (input2 == 5) {
                    cod = filtraTarefas(&lista, &listaProv, 4);
                    qsort(listaProv.tarefas, listaProv.qtd, sizeof(Tarefa), comparaInteiros);
                    cod = listaTarefas(&listaProv);
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
                    cod = exportaTarefas(&lista, 0);
                } else if (input2 == 2) {
                    cod = filtraTarefas(&lista, &listaProv, 1);
                    cod = exportaTarefas(&listaProv, 1);
                } else if (input2 == 3) {
                    cod = filtraTarefas(&lista, &listaProv, 2);
                    cod = exportaTarefas(&listaProv, 2);
                } else if (input2 == 4) {
                    cod = filtraTarefas(&lista, &listaProv, 3);
                    qsort(listaProv.tarefas, listaProv.qtd, sizeof(Tarefa), comparaInteiros);
                    cod = exportaTarefas(&listaProv, 3);
                } else if (input2 == 5) {
                    cod = filtraTarefas(&lista, &listaProv, 4);
                    qsort(listaProv.tarefas, listaProv.qtd, sizeof(Tarefa), comparaInteiros);
                    cod = exportaTarefas(&listaProv, 4);
                } else {
                    printf("\nOpcao invalida!\n\n");
                }

                if (cod == 1) {
                    printf("Lista de tarefas vazia!\n\n");
                } else {
                    printf("Arquivo txt gerado com sucesso!\n\n");
                }

                system("pause");
            } while (input2 != 0);
        } else {
            printf("\nOpcao invalida!\n\n");
        }
    } while (input != 0);

}
