#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

static int size = 0;
static int count = 0;

void insert_node_cmd(pnode *head) {
    count++;
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    *tmp = *head;
    while ((*tmp)->next != NULL) {
        (*tmp) = (*tmp)->next;
    }
    if (count > 1) {
        pnode n = (pnode) malloc(
                sizeof(node));
        (*tmp)->next = n;
        n->node_num = (*tmp)->node_num + 1;
    } else {
        (*tmp)->node_num = size;
    }
    free(tmp);
}

void addEdge(pnode *head, int id, int w, int end) {
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    *tmp = *head;
    while ((*tmp)->node_num != id) {
        (*tmp) = (*tmp)->next;
    }
    pedge e = (pedge) malloc(
            sizeof(edge));
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
    *tmp = *head;
    while ((*tmp)->node_num != end) {
        (*tmp) = (*tmp)->next;
    }
    while (e->next != NULL) {
        e = e->next;
    }
    e->endpoint = (*tmp);
    free(tmp);
//    free(e);
}

void B(pnode *head, int id, int w, int end) {
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    *tmp = *head;
    while ((*tmp)->node_num != id && (*tmp)->next != NULL) {
        (*tmp) = (*tmp)->next;
    }
    if ((*tmp)->next == NULL) {
        if ((*tmp)->node_num == id) {
            addEdge(head, id, w, end);
        } else {
            pnode n = (pnode) malloc(
                    sizeof(node));
            (*tmp)->next = n;
            n->node_num = (*tmp)->node_num + 1;
            addEdge(head, id, w, end);
        }
    } else {
        (*tmp)->edges = NULL;
        addEdge(head, id, w, end);
    }
    free(tmp);
}

void delete_node_cmd(pnode *head) {
    if (*head == NULL)
        return;
    pnode *temp = (pnode *) malloc(
            sizeof(node));
    *temp = *head;
    int position = (*head)->node_num;
    // If head needs to be removed
    if (position == 0) {
        *head = (*temp)->next; // Change head
        free(temp); // free old head
        return;
    }
    for (int i = 0; *temp != NULL && i < position - 1; i++)
        *temp = (*temp)->next;
    if (*temp == NULL || (*temp)->next == NULL)
        return;
    pnode next = (*temp)->next->next;
    free((*temp)->next); // Free memory
    (*temp)->next = next; // Unlink the deleted node from list
}

void deleteGraph_cmd(pnode *head) {
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    *tmp = *head;
    while ((*head) != NULL) {
        while ((*head)->edges != NULL) {
            free((*head)->edges);
            (*head)->edges = (*head)->edges->next;
        }
        (*tmp) = (*head)->next;
        free(*head);
        (*head) = (*tmp);
    }
    free(tmp);
}

void printGraph_cmd(pnode head) {
    pnode tempnode = (pnode *) malloc(
            sizeof(node));
    pedge tempedge = (pedge *) malloc(
            sizeof(edge));
    *tempnode = *head;
    *tempedge = *head->edges;
    while (tempnode != NULL) {
        printf("Node %d \n", (tempnode)->node_num);
        tempedge = tempnode->edges;
        while (tempedge != NULL) {
            printf("Edge to Node %d\n", ((tempedge)->endpoint->node_num));
            tempedge = tempedge->next;
        }
        tempnode = tempnode->next;
    }
    free(tempnode);
    free(tempedge);
}

int main() {
    pnode n1 = (pnode) malloc(sizeof(node));
    pnode *head = &n1;
    char *ch = "A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 5 0 2 B 4 0 4 2 1";
    int i = 0;
    while (1) {
        if (ch[i] == 'A') {
            //deleteGraph_cmd(head);
            i = i + 2;
            int tmp = ((int) ch[i]) - 48;
            for (int j = 0; j < tmp; j++) {
                insert_node_cmd(head);
            }
            i = i + 2;
        }
        if (ch[i] == 'n') {
            i = i + 2;
            int src = ch[i] - 48;
            while (ch[i] != 'n') {
                if ((int) ch[i + 2] >= 48 && (int) ch[i + 2] <= 58) {
                    if (ch[i + 2] == 'n') {
                        i = i + 2;
                        break;
                    } else {
                        addEdge(head, src, (int) ch[i + 4] - 48, (int) ch[i + 2] - 48);
                        i = i + 4;
                    }
                } else {
                    i = i + 2;
                    break;
                }
            }
        }
        if (ch[i] == 'B') {
            int src = (int) ch[i + 2] - 48;
            i = i + 2;
            while ((int) ch[i + 2] >= 48 && (int) ch[i + 2] <= 58) {
                B(head, src, (int) ch[i + 4] - 48, (int) ch[i + 2] - 48);
                i = i + 4;
            }
            i = i + 2;
        }
        if (ch[i] == '\n' || i >= strlen(ch)) {
            break;
        }
    }
//    for (int i = 0; i < 4; i++) {
//        insert_node_cmd(head);
//    }
//    addEdge(head, 0, 5, 2);
//    addEdge(head, 0, 4, 1);
//    addEdge(head, 0, 3, 3);
//    B(head, 4, 3, 2);
//    B(head, 0, 3, 2);

//    printGraph_cmd(n1);
    //delete_node_cmd(head);
    deleteGraph_cmd(head);
    //free(n1);
}
