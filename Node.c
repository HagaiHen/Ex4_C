#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

static int size = 0;
static int count = 0;

void insert_node_cmd(pnode *head) {
    (*head)->size++;
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
//        free(n);
    } else {
        (*tmp)->node_num = size;
    }
//    free(tmp);
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
void delete_node_cmd(pnode *head, int id){
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    *tmp = *head;
    if (*tmp == NULL) {
        printf("There is no place");
        exit(1);
    }
    pnode *prv = (pnode *) malloc(
            sizeof(node));
    while ((*tmp)->node_num != id) {
        *prv = *tmp;
        (*tmp) = (*tmp)->next;
    }
    while ((*tmp)->edges != NULL) {
        free((*tmp)->edges);
        (*tmp)->edges = (*tmp)->edges->next;
    }
    (*tmp) = (*tmp)->next;
    (*prv)->next = *tmp;
//    free((*tmp)->node_num);
//    (*head) = (*tmp);
    *tmp = *head;
    //free((*tmp)->edges);

    pedge *ptmp = (pedge *) malloc(
            sizeof(edge));
    *ptmp = (*head)->edges;
    while((*tmp) != NULL){
        *ptmp = (*tmp)->edges;
        while((*ptmp) != NULL){
            if((*ptmp)->endpoint->node_num == id){
                if((*ptmp)->next == NULL){
                    free((*ptmp)->endpoint);
                }
                if((*ptmp)->next != NULL){
                    (*tmp)->edges = (*ptmp)->next;
                }
            } *ptmp = (*head)->edges->next;
        }(*tmp)= (*tmp)->next;
    }
}

void printGraph_cmd(pnode head) {
    pnode tempnode = (pnode) malloc(
            sizeof(node));
    pedge tempedge = (pedge) malloc(
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
