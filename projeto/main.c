#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    int input, cod;
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
            cod = listaTarefas(&lista);

            if (cod == 1) {
                printf("Lista de tarefas vazia!\n\n");
            }

            system("pause");
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
            //editar tarefa
        } else if (input == 5) {
            //exportar tarefas
        } else {
            printf("\nOpcao invalida!\n\n");
        }
    } while (input != 0);

}
