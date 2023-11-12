#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    int input, cod, input2;
    ListaTarefas lista, listaProv;

    // Carrega as tarefas do arquivo
    cod = carregaTarefas(&lista, "arquivo");

    // Se houver um erro ao carregar, inicializa a lista de tarefas.
    if (cod != 0) {
        lista.qtd = 0;
    }

    do {
        // Imprime menu principal
        imprimeMenu();

        scanf("%d", &input);

        if (input == 0) {
            //encerra o programa
        } else if (input == 1) {
            // Cria uma nova tarefa.
            cod = criaTarefa(&lista);

            if (cod != 0) {
                // Caso retorne algo diferente de 0, indica insucesso na operacao
                printf("\nNao foi possivel cadastrar a tarefa!\n\n");
            } else {
                // Cadastra uma nova tarefa na lista.
                cod = cadastraTarefa(&lista, "arquivo");

                if (cod == 0) {
                    // Caso retorne 0, indica sucesso na operacao
                    printf("\nTarefa cadastrada com sucesso!\n\n");
                } else {
                    // Indica um possivel erro na abertura do arquivo
                    printf("\nErro ao abrir arquivo de destino!\n\n");
                }
            }

            system("pause");
        } else if (input == 2) {
            do {
                // Exibe o menu de listar tarefas.
                imprimeMenuListar();

                scanf("%d", &input2);

                if (input2 == 0) {
                    //encerra o loop
                    break;
                } else if (input2 == 1) {
                    // Lista todas as tarefas cadastradas
                    cod = listaTarefas(&lista);
                } else if (input2 == 2) {
                    // Lista de tarefas filtradas por prioridade
                    cod = filtraTarefas(&lista, &listaProv, 1);
                    cod = listaTarefas(&listaProv);
                } else if (input2 == 3) {
                    // Lista de tarefas filtradas por status
                    cod = filtraTarefas(&lista, &listaProv, 2);
                    cod = listaTarefas(&listaProv);
                } else if (input2 == 4) {
                    // Lista de tarefas filtradas por categoria e ordenada da maior prioridade para a menor
                    cod = filtraTarefas(&lista, &listaProv, 3);
                    qsort(listaProv.tarefas, listaProv.qtd, sizeof(Tarefa), comparaInteiros);
                    printf("\n[Tarefas ordenadas da maior prioridade para a menor]\n");
                    cod = listaTarefas(&listaProv);
                } else if (input2 == 5) {
                    // Lista de tarefas filtradas por categoria e prioridade
                    cod = filtraTarefas(&lista, &listaProv, 4);
                    cod = listaTarefas(&listaProv);
                } else {
                    printf("\nOpcao invalida!\n\n");
                }

                if (cod == 1) {
                    // Caso retorne 1, indica que a lista de tarefas esta vazia
                    printf("\nLista de tarefas vazia!\n\n");
                }

                system("pause");
            } while (input2 != 0);
        } else if (input == 3) {
            // Deleta a tarefa de acordo com o indice fornecido pelo usuario
            cod = deletaTarefa(&lista);

            if (cod == 0) {
                // Caso retorne 0, indica sucesso
                printf("\nTarefa deletada com sucesso!\n\n");
            } else if (cod == 1) {
                // Caso retorne 1, indica que a lista de tarefas esta vazia
                printf("\nLista de tarefas vazia!\n\n");
            } else {
                // Caso contrario, indica que nao ha tarefa com o indice fornecido pelo usuario
                printf("\nTarefa nao encontrada!\n\n");
            }

            system("pause");
        } else if (input == 4) {
            // Edita a tarefa de acordo com o indice fornecido pelo usuario
            cod = editaTarefa(&lista);

            if (cod == 0) {
                // Caso retorne 0, indica sucesso
                printf("\nTarefa editada com sucesso!\n\n");
            } else if (cod == -1) {
                // Caso retorne -1, indica que nao ha tarefa com o indice fornecido pelo usuario
                printf("\nTarefa nao encontrada!\n\n");
            } else if (cod == 1) {
                // Caso retorne 1, indica que a lista de tarefas esta vazia
                printf("\nLista de tarefas vazia!\n\n");
            }

            system("pause");
        } else if (input == 5) {
            do {
                // Exibe o menu de exportar tarefas.
                imprimeMenuExportar();

                scanf("%d", &input2);

                if (input2 == 0) {
                    //encerra o loop
                    break;
                } else if (input2 == 1) {
                    // Exporta todas as tarefas
                    cod = exportaTarefas(&lista, 0);
                } else if (input2 == 2) {
                    // Exporta as tarefas filtradas por prioridade
                    cod = filtraTarefas(&lista, &listaProv, 1);
                    cod = exportaTarefas(&listaProv, 1);
                } else if (input2 == 3) {
                    // Exporta as tarefas filtradas por status
                    cod = filtraTarefas(&lista, &listaProv, 2);
                    cod = exportaTarefas(&listaProv, 2);
                } else if (input2 == 4) {
                    // Exporta as tarefas filtradas por categoria, ordenadas da maior prioridade para a menor
                    cod = filtraTarefas(&lista, &listaProv, 3);
                    qsort(listaProv.tarefas, listaProv.qtd, sizeof(Tarefa), comparaInteiros);
                    cod = exportaTarefas(&listaProv, 3);
                } else if (input2 == 5) {
                    // Exporta as tarefas filtradas por categoria e prioridade
                    cod = filtraTarefas(&lista, &listaProv, 4);
                    cod = exportaTarefas(&listaProv, 4);
                } else {
                    printf("\nOpcao invalida!\n\n");
                }

                if (cod == 1) {
                    // Caso retorne 1, indica que a lista de tarefas esta vazia
                    printf("\nLista de tarefas vazia!\n\n");
                } else {
                    // Caso contrario, indica sucesso
                    printf("\nArquivo txt gerado com sucesso!\n\n");
                }

                system("pause");
            } while (input2 != 0);
        } else {
            printf("\nOpcao invalida!\n\n");
        }
    } while (input != 0);

}
