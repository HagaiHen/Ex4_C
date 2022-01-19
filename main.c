#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int caseA(pnode *head) {
    int numberOfNodes = 0;
    scanf("%d", &numberOfNodes);
    if(numberOfNodes ==' '){
        scanf("%d", &numberOfNodes);
    }
    for(int i=0; i<10; i++){
        insert_node_cmd(head);
    }
    char NextNodeOrDest = ' ';
    scanf("%c", &NextNodeOrDest);
    if(NextNodeOrDest ==' '){
        scanf("%c", &NextNodeOrDest);
    }
    while(NextNodeOrDest == 'n') {
        int NodeID = 0;
        scanf("%d", &NodeID);
        if(NodeID ==' '){
            scanf("%d", &NodeID);
        }
        scanf("%c", &NextNodeOrDest);
        if(NextNodeOrDest ==' '){
            scanf("%c", &NextNodeOrDest);
        }
        if(NextNodeOrDest<=90 && NextNodeOrDest>65){
            return NextNodeOrDest;
        }
        while(isdigit(NextNodeOrDest)){
            int destint = NextNodeOrDest - '0';
            char weight = 0;
            scanf("%c",&weight);
            if(weight ==' '){
                scanf("%c", &weight);
            }
            int w = weight -'0';
            addEdge(head,NodeID, w, destint);
            scanf("%c", &NextNodeOrDest);
            if(NextNodeOrDest ==' '){
                scanf("%c", &NextNodeOrDest);
            }
        }
    }
    return NextNodeOrDest;
}

int caseB(pnode *head) {
    int count = 0;
    pnode *tmp = (pnode *) malloc(
            sizeof(node));
    *tmp = *head;
    char NodeID;
    scanf("%c", &NodeID);
    if(NodeID ==' '){
        scanf("%c", &NodeID);
    }
    int id = NodeID - '0';
    while(*tmp != NULL){
        if(id == (*tmp)->node_num){
            while ((*tmp)->edges != NULL) {
                free((*tmp)->edges);
                (*tmp)->edges = (*tmp)->edges->next;
            }
            break;
        }
        *tmp = (*tmp)->next;
    }
    int Dest;
    while(isdigit(NodeID)) {
        if(count == 0) {
            scanf("%d", &Dest);
            if (Dest == ' ') {
                scanf("%d", &Dest);
            }
        }else{
            int temp = NodeID - '0';
            Dest = temp;}
        int Weight;
        scanf("%d", &Weight);
        if(Weight ==' '){
            scanf("%d", &Weight);
        }
        addEdge(head, id, Weight, Dest);
        scanf("%c", &NodeID);
        if(NodeID ==' '){
            scanf("%c", &NodeID);
        }count++;
    }
    free(tmp);
    return NodeID;
}

int caseD(pnode *head) {
    char NodeID;
    scanf("%c", &NodeID);
    if(NodeID ==' '){
        scanf("%c", &NodeID);
    }
    while(isdigit(NodeID)) {
        int id = NodeID - '0';
        delete_node_cmd(head, id);
        scanf("%c", &NodeID);
        if(NodeID ==' '){
            scanf("%c", &NodeID);
        }
    }
    return NodeID;
}

int caseS(pnode *head){
    char Start;
    scanf("%c", &Start);
    if(Start ==' '){
        scanf("%c", &Start);
    }
    while(isdigit(Start)){
        int from = Start - '0';
        char Dest;
        scanf("%c", &Dest);
        if(Dest ==' '){
            scanf("%c", &Dest);
        }
        int destint =  Dest - '0';
        pnode tmp = *head;
        int max =0;
        while(tmp !=NULL){
            if(tmp->node_num > max){
                max = tmp->node_num;
            } tmp = tmp->next;
        }
        int res = shortestPath(head,from, destint, max);
        printf("Dijsktra shortest path: %d\n", res);
        scanf("%c", &Start);
        if(Start ==' '){
            scanf("%c", &Start);
        }
    }
    return Start;
}

int caseT(pnode *head){
    int HowLong;
    scanf("%d", &HowLong);
    int Nodes [HowLong];
    for (int i = 0; i < HowLong; ++i) {
        int NodeID;
        scanf("%d", &NodeID);
        Nodes[i] = NodeID;
    }
    pnode tmp = *head;
    int max =0;
    while(tmp !=NULL){
        if(tmp->node_num > max){
            max = tmp->node_num;
        } tmp = tmp->next;
    }
    int res = TSP_cmd(head, Nodes, HowLong, max);
    printf("TSP shortest path: %d\n", res);
    char NextChar;
    scanf("%c", &NextChar);
    if(NextChar ==' '){
        scanf("%c", &NextChar);
    }
    return NextChar;
}


int main(void) {
    pnode n1 = (pnode) malloc(sizeof(node));
    pnode *head = &n1;
    char input = 0;
    scanf("%c", &input);
    while (1) {
        switch (input) {
            case 'A':
                input = caseA(head);
                break;
            case 'B':
                input = caseB(head);
                break;
            case 'D':
                input = caseD(head);
                break;
            case 'S':
                input = caseS(head);
                break;
            case 'T':
                input = caseT(head);
                break;
        }
    }
    free(n1);
}
