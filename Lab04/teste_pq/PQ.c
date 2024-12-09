#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

// TODO: Crie a struct pq.

struct pq {
    int size;
    int max_size;
    int * heap;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    // TODO: Implemente a criação da fila que suporta no máximo o número de
    //       de eventos informados no parâmetro.

    PQ * pq = malloc(sizeof(PQ));

    pq->max_size = max_N;
    pq->heap = calloc(max_N + 1, sizeof(int));
    pq->size = 0;

    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    // TODO: Implemente essa função que libera toda a memória da fila,
    //       destruindo inclusive os eventos que estavam na fila.
    
    free(pq->heap);
    free(pq);

}

void exchange(PQ * pq, int i, int j){
    int aux = pq->heap[i];
    pq->heap[i] = pq->heap[j];
    pq->heap[j] = aux;
}

void fix_up(PQ * pq, int n){
    while(n > 0 && pq->heap[n/2] < pq->heap[n]){
        exchange(pq, n/2, n);
        n /= 2;
    }
}

void fix_down(PQ* pq, int n){
    while(2 * n < pq->size){
        int i = 2*n;
        if(pq->heap[i+ 1] > pq->heap[i]) i++;

        if(pq->heap[n] > pq->heap[i]) exchange(pq, n, i);
        else break;

        n = i;
    }
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, int e) {
    // TODO: Implemente essa função que insere o evento dado na fila segundo
    //       o tempo do evento.
    //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
    //       em uma fila que já contém o número máximo de eventos) para evitar
    //       dores de cabeça com acessos inválidos na memória.

    if(pq->size == pq->max_size){
        printf("Queue Overflow\n");
        return;
    }

    pq->size++;

    pq->heap[pq->size] = e;
    fix_up(pq, pq->size);

    for(int i = 0; i < pq->size; i++) printf("%d ", pq->heap[i]);
    printf("\n");
}

/*
 * Remove e retorna o evento mais próximo.
 */
int PQ_delmin(PQ *pq) {
    // TODO: Implemente essa função que remove o evento com o menor tempo da
    //       fila e o retorna.

    if(pq->size == 0){
        printf("No events in Queue\n");
        return 0;
    }

    int min = pq->heap[0];

    pq->heap[0] = pq->heap[pq->size];
    pq->size--;

    fix_down(pq, 0);

    return min;
}

/*
 * Testa se a fila está vazia.
 */
int PQ_is_empty(PQ *pq) {
    // TODO: Implemente essa função.

    return !pq->size;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    // TODO: Implemente essa função.

    return pq->size;
}
