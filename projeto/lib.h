//
// Created by Mariane on 05/11/2023.
//

#ifndef PROJETO_LIB_H
#define PROJETO_LIB_H
// Enumeração para representar os diferentes status de uma tarefa.
typedef enum {
    naoIniciada = 1,
    emAndamento,
    completa
} StatusTarefa;

// Estrutura que define uma Tarefa, contendo informações como prioridade, categoria, descrição e status.
typedef struct {
    int prioridade;           // Prioridade da tarefa (de 0 a 10).
    char categoria[100];      // Categoria da tarefa (até 100 caracteres).
    char descricao[300];      // Descrição da tarefa (até 300 caracteres).
    StatusTarefa status;      // Status da tarefa (enumeração StatusTarefa).
} Tarefa;

// Estrutura que define uma ListaTarefas, contendo um array de tarefas e a quantidade atual de tarefas na lista.
typedef struct {
    Tarefa tarefas[100];      // Array de tarefas.
    int qtd;                  // Quantidade atual de tarefas na lista.
} ListaTarefas;

void imprimeMenu(); // Exibe um menu principal para o gerenciador de tarefas.

void imprimeMenuListar(); // Exibe um menu para listar tarefas com diferentes opções de filtragem.

void imprimeMenuExportar(); // Exibe um menu para exportar tarefas com diferentes opções de filtragem.

int criaTarefa(ListaTarefas *lt); // Cria uma nova tarefa e a adiciona à lista de tarefas fornecida.

int cadastraTarefa(ListaTarefas *lt, char *arquivo); // Salva a lista de tarefas em um arquivo binário.

int deletaTarefa(ListaTarefas *lt); // Deleta uma tarefa da lista de tarefas com base no número fornecido.

int listaTarefas(ListaTarefas *lt); // Lista todas as tarefas na lista de tarefas, exibindo informações como prioridade, categoria, descrição e status.

int carregaTarefas(ListaTarefas *lt, char *arquivo); // Carrega a lista de tarefas de um arquivo binário.

int editaTarefa(ListaTarefas *lt); // Permite ao usuário editar uma tarefa existente na lista.

int filtraTarefas(ListaTarefas *lt, ListaTarefas *ltProvisoria, int tipoFiltro); // Filtra as tarefas da ListaTarefas fornecida com base no tipo de filtro.

int exportaTarefas(ListaTarefas *lt, int tipoFiltro); // Exporta as tarefas da ListaTarefas fornecida para um arquivo de texto com base no tipo de filtro.

int comparaInteiros(const void* a, const void* b); // Função de comparação para qsort, compara dois inteiros (prioridades de tarefas) para ordenação.
#endif //PROJETO_LIB_H
