#include <malloc.h>
#include "graph.h"

void addEdge(pnode *head, int id, int w, int end) {
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    pedge e = (pedge) malloc(
            sizeof(edge));
    *tmp = *head;
    while ((*tmp)->node_num != id) {
        if((*tmp)->next != NULL) {
            (*tmp) = (*tmp)->next;
        }else{
            insert_node_cmd(head);
            (*tmp) = (*tmp)->next;
        }
    }
    if ((*tmp)->edges != NULL) {
        while ((*tmp)->edges->next != NULL) {
            (*tmp)->edges->next = (*tmp)->edges->next->next;
        }
        e->weight = w;
        (*tmp)->edges->next = e;
        e->next = NULL;
    } else {
        e->weight = w;
        (*tmp)->edges = e;
        e->next = NULL;
    }
    *tmp = (*head);
    while ((*tmp)->node_num != end) {
        (*tmp) = (*tmp)->next;
    }
    while (e->next != NULL) {
        e = e->next;
    }
    e->endpoint = (*tmp);
    free(tmp);
    free(e);
}