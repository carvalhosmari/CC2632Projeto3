//
// Created by Mariane on 05/11/2023.
//

#include "lib.h"
#include <stdio.h>
#include <string.h>

void imprimeMenu() {
    printf("********************************************\n");
    printf("********** GERENCIADOR DE TAREFAS **********\n");
    printf("********************************************\n");
    printf("\n");
    printf("O que voce gostaria de fazer?\n");
    printf("\n");
    printf("\t1 - cadastrar nova tarefa;\n");
    printf("\t2 - listar tarefas;\n");
    printf("\t3 - deletar tarefa;\n");
    printf("\t4 - editar tarefa;\n");
    printf("\t5 - exportar tarefas;\n");
    printf("\t0 - sair da aplicacao.\n\n");
    printf("digite sua opcao: ");
}

int criaTarefa(ListaTarefas *lt) {
    char desc[300], categ[100];
    Tarefa *t = &lt->tarefas[lt->qtd];

    printf("Digite a prioridade da tarefa (0 a 10): ");
    scanf("%d", &t->prioridade);

    printf("Digite a categoria a qual esta tarefa pertence: ");
    fgetc(stdin); //limpa o buffer do teclado
    scanf("%[^\n]", categ);
    strcpy(t->categoria, categ);

    printf("Digite uma breve descricao desta tarefa: ");
    fgetc(stdin); //limpa o buffer do teclado
    scanf("%[^\n]", desc);
    strcpy(t->descricao, desc);
    printf("\n");

    lt->qtd++;

    return 0;
}

int cadastraTarefa(ListaTarefas *lt, char *arquivo){
    FILE *f = fopen(arquivo, "wb");

    if (f == NULL) {
        return -1;
    }

    fwrite(lt, sizeof (ListaTarefas), 1, f);

    fclose(f);

    return 0;
}

int listaTarefas(ListaTarefas *lt) {

    if (lt->qtd == 0) {
        return 1;
    }

    for (int i = 0; i < lt->qtd; i++) {
        printf("Tarefa [%d]:\n", (i + 1));
        printf("\tprioridade: %d\n\tcategoria: %s\n\tdescricao: %s\n\n", lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].descricao);
    }

    return 0;
}

int deletaTarefa(ListaTarefas *lt) {
    int indice, indiceReal;

    if (lt->qtd == 0) {
        return 1;
    } else {
        printf("Digite o numero da tarefa que voce gostaria de deletar: ");
        scanf("%d", &indice);

        indiceReal = indice - 1;

        if (indice > lt->qtd || indice <= 0) {
            return -1;
        }

        for (int i = 0; i < lt->qtd; i++) {
            if (indiceReal <= i) {
                lt->tarefas[i] = lt->tarefas[(i + 1)];
            }
        }

        lt->qtd --;
        cadastraTarefa(lt, "arquivo");
    }

    return 0;
}

int carregaTarefas(ListaTarefas *lt, char *arquivo) {
    FILE *f = fopen(arquivo, "rb");

    if (f == NULL) {
        return 1;
    }

    fread(lt, sizeof(ListaTarefas), 1, f);

    fclose(f);

    return 0;
}

