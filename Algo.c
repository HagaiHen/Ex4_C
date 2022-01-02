#define inf 100000000

#include <malloc.h>
#include <limits.h>
#include "graph.h"

int tsp = INT_MAX;

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

//int tsp (pnode *head, int listofnode [], int size) {
//    int dist[size][size];
//    for(int i=0; i< size; i++){                         //build a matrix of dijestra
//        for(int j=0; j<size; j++){
//            if(i != j){
//                dist[i][j]= shortestPath(head, listofnode[i], listofnode[j]);
//            }else{
//                dist[i][j]=inf;
//            }
//        }
//    }
//    int shortest = inf, sumofweight=0 ,min = inf, count=0;
//    int tempshortestarray [size];
//    int shortestarray [size];
//    for(int i=0; i<(size); i++){
//        for(int j=0; j<(size); j++){
//                if(dist[i][j] < min){
//                    min = dist[i][j];
//                    tempshortestarray[i] = j;
//                    sumofweight = sumofweight+dist[i][j];
//                }
//        }
//        for(int j=0; j<(size); j++){
//            if(tempshortestarray[i] != 0 || tempshortestarray[i] != inf) {
//                count++;
//            }
//        }
//        min=inf;
//        if(shortest>sumofweight && count == size) {
//            shortest = sumofweight;
//            for(int j=0; j<(size); j++){
//                shortestarray[j] = tempshortestarray[j];
//                tempshortestarray[i] = 0;
//            }
//        }
//        for(int j=0; j<(size); j++){
//            tempshortestarray[i] = 0;
//        }
//    }
//    int *p = shortestarray;
//    return p;
//}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(pnode *head, int *a, int start, int end) {
    if (start == end){
        int sum = 0;
        int j=1;
        for(int i=0; i<end-1; i++){
            if(j<=end){
                sum += shortestPath(head, i, j);
                j++;
            }
        }
        if(sum<tsp){
            tsp = sum;
        }
    }

    else{
        for(int i = start; i <= end; i++){
            swap((a+start), (a+i));
            permute(head, a, start+1, end);
            swap((a+start), (a+i)); //backtrack
        }
    }
}

void TSP(pnode *head) {
    int len = 3;
    pnode *temp = head;
    int arr[3] = {2, 1, 3};
    tsp = INT_MAX;
    permute(head, arr, 0, len-1);
    printf("TSP shortest path: %d\n", tsp);
}
