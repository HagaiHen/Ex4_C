#include <malloc.h>
#include "graph.h"

static int size = 0;
static int count = 0;

void insert_node_cmd(pnode *head) {
    size = 0;
    count++;
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    *tmp = *head;
    while ((*tmp)->next != NULL) {
        size++;
        (*tmp) = (*tmp)->next;
    }

    if(count > 1) {
        pnode n = (pnode) malloc(
                sizeof(node));
        (*tmp)->next = n;
        n->node_num = (*tmp)->node_num + 1;
    } else {
        (*tmp)->node_num = size;
    }

}

void addEdge(pnode *head, int id, int w, int end) {
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    *tmp = *head;
    while ((*tmp)->node_num != id) {
        (*tmp) = (*tmp)->next;
    }
    pnode n = (*tmp);
    pedge e = (pedge) malloc(
            sizeof(edge));
    while (n->edges != NULL) {
        n->edges = n->edges->next;
    }
    e->weight = w;
    n->edges = e;
    e->next = NULL;
    *tmp = *head;
    while ((*tmp)->node_num != end) {
        (*tmp) = (*tmp)->next;
    }
    while (e->next != NULL) {
        e = e->next;
    }
    e->endpoint = (*tmp);
}


int main() {
    char ch[10] = "A4n02533";
    pnode n1 = (pnode) malloc(
            sizeof(node));
    pnode *ptr = &n1;
    pnode *head = &n1;
    for (int i = 0; i < 4; i++) {
        insert_node_cmd(ptr);
    }
    addEdge(head, 0, 5, 2);
    addEdge(head, 0, 4, 1);
    addEdge(head, 2, 4, 1);
}
