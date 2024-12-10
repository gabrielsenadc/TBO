#include <stdio.h>
#include <stdlib.h>
#include "event.h"
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
    Event ** heap;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    // TODO: Implemente a criação da fila que suporta no máximo o número de
    //       de eventos informados no parâmetro.

    PQ * pq = malloc(sizeof(PQ));

    pq->max_size = max_N;
    pq->heap = calloc(max_N, sizeof(Event*));
    pq->size = 0;

    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    // TODO: Implemente essa função que libera toda a memória da fila,
    //       destruindo inclusive os eventos que estavam na fila.

    for(int i = 0; i < pq->size; i++) destroy_event(pq->heap[i]);
    
    free(pq->heap);
    free(pq);

}

void exchange(PQ * pq, int i, int j){
    Event * aux = pq->heap[i];
    pq->heap[i] = pq->heap[j];
    pq->heap[j] = aux;
}

void fix_up(PQ * pq, int n){
    while(n > 1 && compare(pq->heap[n/2], pq->heap[n]) > 0){
        exchange(pq, n/2, n);
        n /= 2;
    }
}

void fix_down(PQ* pq, int n){
    while(2 * n <= pq->size){
        int i = 2*n;
        if(i < pq->size && compare(pq->heap[i + 1], pq->heap[i]) < 0) i++;

        if(compare(pq->heap[n], pq->heap[i]) > 0) exchange(pq, n, i);
        else break;

        n = i;
    }
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
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

}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    // TODO: Implemente essa função que remove o evento com o menor tempo da
    //       fila e o retorna.

    if(pq->size == 0){
        printf("No events in Queue\n");
        return NULL;
    }

    Event * min = pq->heap[1];

    exchange(pq, 1, pq->size);
    pq->size--;

    fix_down(pq, 1);

    return min;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
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
