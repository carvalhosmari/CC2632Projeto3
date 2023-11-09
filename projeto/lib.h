//
// Created by Mariane on 05/11/2023.
//

#ifndef PROJETO_LIB_H
#define PROJETO_LIB_H
typedef enum {
    naoIniciada = 1,
    emAndamento,
    completa
} StatusTarefa;
typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
    StatusTarefa status;
} Tarefa;
typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaTarefas;
void imprimeMenu();
void imprimeMenuListar();
void imprimeMenuExportar();
int criaTarefa(ListaTarefas *lt);
int cadastraTarefa(ListaTarefas *lt, char *arquivo);
int deletaTarefa(ListaTarefas *lt);
int listaTarefas(ListaTarefas *lt);
int carregaTarefas(ListaTarefas *lt, char *arquivo);
int editaTarefa(ListaTarefas *lt);
#endif //PROJETO_LIB_H
