//
// Created by Mariane on 05/11/2023.
//

#include "lib.h"
#include <stdio.h>
#include <string.h>

// Exibe um menu simples para o usuário e solicita uma escolha
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

// Adiciona uma nova tarefa à lista com informações fornecidas pelo usuário.
int criaTarefa(ListaTarefas *lt) {
    char desc[300], categ[100];
    Tarefa *t = &lt->tarefas[lt->qtd];

    // Solicita informações sobre a nova tarefa ao usuário
    printf("prioridade da tarefa (0 a 10): ");
    scanf("%d", &t->prioridade);

    printf("categoria a qual esta tarefa pertence: ");
    fgetc(stdin); //limpa o buffer do teclado
    scanf("%[^\n]", categ);
    strcpy(t->categoria, categ);

    fgetc(stdin); //limpa o buffer do teclado
    printf("breve descricao desta tarefa: ");
    scanf("%[^\n]", desc);
    strcpy(t->descricao, desc);

    // Define o status inicial como 1 (não iniciada)
    t->status = 1;

    // Incrementa a quantidade total de tarefas na lista
    lt->qtd++;

    return 0;
}

// Salva a lista de tarefas em um arquivo.
int cadastraTarefa(ListaTarefas *lt, char *arquivo){
    FILE *f = fopen(arquivo, "wb");

    // Verifica se o arquivo foi aberto com sucesso
    if (f == NULL) {
        return -1;
    }

    // Escreve a lista de tarefas no arquivo binário
    fwrite(lt, sizeof (ListaTarefas), 1, f);

    // Fecha o arquivo
    fclose(f);

    return 0;
}

// Lista as tarefas presentes na ListaTarefas fornecida.
int listaTarefas(ListaTarefas *lt) {

    // Verifica se a lista está vazia
    if (lt->qtd == 0) {
        return 1;
    }

    for (int i = 0; i < lt->qtd; i++) {
        char *status;

        // Determina o status da tarefa com base no valor do status
        if (lt->tarefas[i].status == 1) {
            status = "nao iniciada";
        } else if (lt->tarefas[i].status == 2) {
            status = "em andamento";
        } else {
            status = "completa";
        }

        // Exibe informações sobre a tarefa
        printf("Tarefa [%d]:\n", (i + 1));
        printf("\tprioridade: %d\n\tcategoria: %s\n\tdescricao: %s\n\tstatus: %s\n\n", lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].descricao, status);
    }

    return 0;
}

// Deleta uma tarefa da lista com base no número fornecido pelo usuário.
int deletaTarefa(ListaTarefas *lt) {
    int indice, indiceReal;

    // Verifica se a lista está vazia
    if (lt->qtd == 0) {
        return 1;
    } else {
        // Solicita ao usuário o número da tarefa a ser deletada
        printf("Digite o numero da tarefa que voce gostaria de deletar: ");
        scanf("%d", &indice);

        // Ajusta o índice para a representação interna (começando de 0)
        indiceReal = indice - 1;

        // Verifica se o índice fornecido é válido
        if (indice > lt->qtd || indice <= 0) {
            return -1;
        }

        // Desloca as tarefas para preencher o espaço da tarefa deletada
        for (int i = 0; i < lt->qtd; i++) {
            if (indiceReal <= i) {
                lt->tarefas[i] = lt->tarefas[(i + 1)];
            }
        }

        // Decrementa a quantidade total de tarefas
        lt->qtd--;

        // Salva a lista atualizada
        cadastraTarefa(lt, "arquivo");
    }

    return 0;
}

// Carrega as tarefas de um arquivo binário para a ListaTarefas fornecida.
int carregaTarefas(ListaTarefas *lt, char *arquivo) {
    FILE *f = fopen(arquivo, "rb");

    // Verifica se o arquivo foi aberto com sucesso
    if (f == NULL) {
        return 1;
    }

    // Lê as tarefas do arquivo binário para a lista
    fread(lt, sizeof(ListaTarefas), 1, f);

    // Fecha o arquivo
    fclose(f);

    return 0;
}

// Exibe um menu para listar tarefas com diferentes opções de filtragem.
void imprimeMenuListar() {
    printf("O que voce gostaria de fazer?\n");
    printf("\n");
    printf("\t1 - listar todas as tarefas;\n");
    printf("\t2 - listar tarefas por prioridade;\n");
    printf("\t3 - listar tarefas por status;\n");
    printf("\t4 - listar tarefas por categoria;\n");
    printf("\t5 - listar tarefas por prioridade e categoria;\n");
    printf("\t0 - voltar.\n\n");
    printf("digite sua opcao: ");
}

// Exibe um menu para exportar tarefas com diferentes opções de filtragem.
void imprimeMenuExportar() {
    printf("O que voce gostaria de fazer?\n");
    printf("\n");
    printf("\t1 - exportar todas as tarefas;\n");
    printf("\t2 - exportar tarefas por prioridade;\n");
    printf("\t3 - exportar tarefas por status;\n");
    printf("\t4 - exportar tarefas por categoria;\n");
    printf("\t5 - exportar tarefas por prioridade e categoria;\n");
    printf("\t0 - voltar.\n\n");
    printf("digite sua opcao: ");
}

// Permite ao usuário editar uma tarefa existente na lista.
int editaTarefa(ListaTarefas *lt) {
    int indice, indiceReal, input;

    // Verifica se a lista está vazia
    if (lt->qtd == 0) {
        return 1;
    } else {
        // Solicita ao usuário o número da tarefa a ser editada
        printf("Digite o numero da tarefa que voce gostaria de editar: ");
        scanf("%d", &indice);

        // Ajusta o índice para a representação interna (começando de 0)
        indiceReal = indice - 1;

        // Verifica se o índice fornecido é válido
        if (indice > lt->qtd || indice <= 0) {
            return -1;
        }

        // Solicita ao usuário o campo da tarefa que deseja editar
        printf("digite o campo que deseja editar:\n\t1 - prioridade;\n\t2 - categoria;\n\t3 - descricao;\n\t4 - status.\n\ndigite sua opcao: ");
        scanf("%d", &input);

        // Realiza a edição com base no campo escolhido
        if (input == 1) {
            // Edita a prioridade da tarefa
            printf("digite a nova prioridade: ");
            scanf("%d", &input);

            lt->tarefas[indiceReal].prioridade = input;
        } else if (input == 2) {
            // Edita a categoria da tarefa
            char categ[100];

            printf("digite a nova categoria: ");
            fgetc(stdin); //limpa o buffer do teclado
            scanf("%[^\n]", categ);

            strcpy(lt->tarefas[indiceReal].categoria, categ);
        } else if (input == 3) {
            // Edita a descrição da tarefa
            char desc[300];

            printf("digite a nova descricao: ");
            fgetc(stdin); //limpa o buffer do teclado
            scanf("%[^\n]", desc);

            strcpy(lt->tarefas[indiceReal].descricao, desc);
        } else if (input == 4) {
            // Edita o status da tarefa
            printf("digite o novo status:\n\t1 - nao iniciada;\n\t2 - em andamento\n\t3 - completa.\n\ndigite sua opcao: ");
            scanf("%d", &input);

            lt->tarefas[indiceReal].status = input;
        }

        // Salva a lista atualizada
        cadastraTarefa(lt, "arquivo");

        return 0;
    }
}

// Filtra as tarefas da ListaTarefas fornecida com base no tipo de filtro.
int filtraTarefas(ListaTarefas *lt, ListaTarefas *ltProvisoria, int tipoFiltro) {
    int input;
    ltProvisoria->qtd = 0;

    // Aplica o filtro com base no tipo fornecido
    if (tipoFiltro == 1) {
        // Filtra por prioridade
        printf("digite a prioridade: ");
        scanf("%d", &input);

        for (int i = 0; i < lt->qtd; i++) {
            // Verifica na lista geral se ha alguma tarefa com as especificacoes do filtro,
            // em caso positivo, a tarefa é adicionada em uma lista provisoria
            if (input == lt->tarefas[i].prioridade) {
                ltProvisoria->tarefas[ltProvisoria->qtd] = lt->tarefas[i];
                ltProvisoria->qtd++;
            }
        }
    } else if (tipoFiltro == 2) {
        // Filtra por status
        printf("digite o status:\n\t1 - nao iniciada;\n\t2 - em andamento;\n\t3 - completa.\ndigite a opcao desejada: ");
        scanf("%d", &input);

        for (int i = 0; i < lt->qtd; i++) {
            // Verifica na lista geral se ha alguma tarefa com as especificacoes do filtro,
            // em caso positivo, a tarefa é adicionada em uma lista provisoria
            if (input == lt->tarefas[i].status) {
                ltProvisoria->tarefas[ltProvisoria->qtd] = lt->tarefas[i];
                ltProvisoria->qtd++;
            }
        }
    } else if (tipoFiltro == 3) {
        // Filtra por categoria
        char categ[100];

        printf("digite a categoria: ");
        fgetc(stdin);
        scanf("%[^\n]", categ);

        for (int i = 0; i < lt->qtd; i++) {
            // Verifica na lista geral se ha alguma tarefa com as especificacoes do filtro,
            // em caso positivo, a tarefa é adicionada em uma lista provisoria
            if (strcasecmp(categ, lt->tarefas[i].categoria) == 0) {
                ltProvisoria->tarefas[ltProvisoria->qtd] = lt->tarefas[i];
                ltProvisoria->qtd++;
            }
        }
    } else {
        // Filtra por prioridade e categoria
        char categ[100];

        printf("digite a prioridade: ");
        scanf("%d", &input);

        printf("digite a categoria: ");
        fgetc(stdin);
        scanf("%[^\n]", categ);

        for (int i = 0; i < lt->qtd; i++) {
            // Verifica na lista geral se ha alguma tarefa com as especificacoes do filtro,
            // em caso positivo, a tarefa é adicionada em uma lista provisoria
            if (strcasecmp(categ, lt->tarefas[i].categoria) == 0 && input == lt->tarefas[i].prioridade) {
                ltProvisoria->tarefas[ltProvisoria->qtd] = lt->tarefas[i];
                ltProvisoria->qtd++;
            }
        }
    }

    // Retorna 1 se não houver tarefas após o filtro
    if (ltProvisoria->qtd == 0) {
        return 1;
    }

    return 0;
}

// Exporta as tarefas da ListaTarefas fornecida para um arquivo de texto com base no tipo de filtro.
int exportaTarefas(ListaTarefas *lt, int tipoFiltro) {
    char *tipo, *status;

    // Verifica se a lista está vazia
    if (lt->qtd != 0) {
        // Determina o tipo de exportação com base no tipo de filtro
        if (tipoFiltro == 1) {
            tipo = "prioridade";
        } else if (tipoFiltro == 2) {
            tipo = "status";
        } else if (tipoFiltro == 3) {
            tipo = "categoria [ordenadas da maior prioridade para a menor]";
        } else if (tipoFiltro == 4) {
            tipo = "prioridade e categoria";
        } else {
            tipo = "todas as tarefas";
        }

        // Abre um arquivo de texto para escrita
        FILE *f = fopen("exportTarefas.txt", "w");

        // Escreve cabeçalho no arquivo
        fprintf(f,"LISTA DE TAREFAS\n");
        fprintf(f,"filtrado por: \t%s\n", tipo);
        fprintf(f, "--------------------------------------------------------\n");

        for (int i = 0; i < lt->qtd; i++) {
            // Determina o status da tarefa com base no valor do status
            if (lt->tarefas[i].status == 1) {
                status = "nao iniciada";
            } else if (lt->tarefas[i].status == 2) {
                status = "em andamento";
            } else {
                status = "completa";
            }

            // Escreve informações sobre a tarefa no arquivo
            fprintf(f, "Tarefa [%d]\tprioridade: %d \tcategoria: %s\tstatus: %s\tdescricao: %s\n", (i + 1), lt->tarefas[i].prioridade, lt->tarefas[i].categoria, status, lt->tarefas[i].descricao);
        }

        // Fecha o arquivo
        fclose(f);

        return 0;
    } else {
        return 1;
    }
}

// Função de comparação para qsort, compara dois inteiros (prioridades de tarefas) para ordenação.
int comparaInteiros(const void* a, const void* b) {
    const int x = ((const Tarefa *)a)->prioridade;
    const int y = ((const Tarefa *)b)->prioridade;

    // Retorna um valor negativo se x > y, um valor positivo se x < y, e 0 se x == y.
    if(x < y)
        return 1;
    else if(x > y)
        return -1;
    else
        return 0;
}