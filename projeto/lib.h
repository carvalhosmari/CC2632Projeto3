//
// Created by Mariane on 05/11/2023.
//

#ifndef PROJETO_LIB_H
#define PROJETO_LIB_H
typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
} Tarefa;
typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaTarefas;
void imprimeMenu();
int criaTarefa(ListaTarefas *lt);
int cadastraTarefa(ListaTarefas *lt, char *arquivo);
int deletaTarefa(ListaTarefas *lt);
int listaTarefas(ListaTarefas *lt);
int carregaTarefas(ListaTarefas *lt, char *arquivo);
#endif //PROJETO_LIB_H
