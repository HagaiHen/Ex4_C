#define inf 100000000

#include <malloc.h>
#include "graph.h"

int shortestPath(pnode *head, int src, int dest) {
    int dist[(*head)->size];
    int visited[(*head)->size];
    for (int i = 0; i < (*head)->size; i++) {
        dist[i] = inf;
        visited[i] = 0;
    }
    dist[src] = 0;
    struct Queue *queue = createQueue((*head)->size);
    enqueue(queue, src);
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    *tmp = *head;
    while (!(isEmpty(queue))) {
        int curr = dequeue(queue);
        if (visited[curr] == 0) {
            while ((*tmp)->node_num != curr) {
                (*tmp) = (*tmp)->next;
            }
            pedge e = (*tmp)->edges;
            while ((*tmp)->edges != NULL) {
                int distance = dist[curr] + (*tmp)->edges->weight;
                int target = (*tmp)->edges->endpoint->node_num;
                if (distance < dist[target]) {
                    dist[target] = distance;
                    enqueue(queue, target);
                }
                (*tmp)->edges = (*tmp)->edges->next;
            }
            (*tmp)->edges = e;
            (*tmp) = (*head);
        }
        visited[curr] = 1;
    }
    free(tmp);
    free(queue);
    free(queue->array);
    return dist[dest];
}