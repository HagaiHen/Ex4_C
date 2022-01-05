#define inf 100000000

#include <malloc.h>
#include <limits.h>
#include "graph.h"

int res = INT_MAX;

int shortestPath(pnode *head, int src, int dest, int max) {
    int dist[max+1];
    int visited[max+1];
    for (int i = 0; i < max+ 1; i++) {
        dist[i] = inf;
        visited[i] = 0;
    }
    dist[src] = 0;
    struct Queue *queue = createQueue((*head)->size);
    enqueue(queue, src);
    pnode tmp = *head;
    pedge p;
    while (!(isEmpty(queue))) {
        int curr = dequeue(queue);
        if (visited[curr] == 0) {
            if((tmp)->node_num == curr){
                p = (tmp)->edges;
            }else {
                while ((tmp)->node_num != curr) {
                    if ((tmp)->next != NULL) {
                        (tmp) = (tmp)->next;
                        p = (tmp)->edges;
                    } else {
                        p = NULL;
                        break;
                    }

                }
            }
//            pedge e = (*tmp)->edges;
            while (p != NULL) {
                int distance = dist[curr] + p->weight;
                int target = p->endpoint->node_num;
                if (distance < dist[target]) {
                    dist[target] = distance;
                    enqueue(queue, target);
                }
                p = p->next;
            }
//            (*tmp)->edges = p;
            (tmp) = (*head);
        }
        visited[curr] = 1;

    }
    free(queue->array);
    free(queue);
    return dist[dest];
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void check(pnode *head, int *a, int from, int dest, int max) {
    if (from == dest){
        int sum = 0, j=1;
        for(int i=0; i<dest-1; i++){
            if(j<=dest){
                sum += shortestPath(head, i, j, max);
                j++;
            }
        }
        if(sum<res){
            res = sum;
        }
    }
    else{
        for(int i = from; i <= dest; i++){
            swap((a+from), (a+i));
           check(head, a, from+1, dest, max);
            swap((a+from), (a+i)); //backtrack
        }
    }
}

int TSP_cmd(pnode *head, int array [], int size, int max) {
    int len = size;
    res = INT_MAX;
    check(head, array, 0, len-1, max);
    return res;
}
