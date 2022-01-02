#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "graph.h"


int caseA(pnode *head) {
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    char CheckOrWeight;
    scanf("%c", &CheckOrWeight);
    if(CheckOrWeight ==' '){
        scanf("%c", &CheckOrWeight);
    }
    if(CheckOrWeight == 'n') {
        int NodeID;
        scanf("%d", &NodeID);
        if(NodeID ==' '){
            scanf("%d", &NodeID);
        }
        insert_node_cmd(head);
        while(isdigit(CheckOrWeight)){
            int weight = CheckOrWeight - '0';
            int dest;
            scanf("%d", &dest);
            if(dest ==' '){
                scanf("%d", &dest);
            }
            addEdge(head,NodeID, weight, dest);
            scanf("%c", &CheckOrWeight);
            if(dest ==' '){
                scanf("%c", &CheckOrWeight);
            }
        }
        return CheckOrWeight;
    }
}

int caseB(pnode *head) {
    char NodeID;
    scanf("%c", &NodeID);
    if(NodeID ==' '){
        scanf("%d", &NodeID);
    }
    while(isdigit(NodeID)) {
        int id = NodeID - '0';
        int Dest;
        scanf("%d", &Dest);
        if(Dest ==' '){
            scanf("%d", &Dest);
        }
        int Weight;
        scanf("%d", &Weight);
        if(Weight ==' '){
            scanf("%d", &Weight);
        }
        B(head, id, Weight, Dest);
        scanf("%c", &NodeID);
        if(NodeID ==' '){
            scanf("%d", &NodeID);
        }
    }
    return NodeID;
}

int caseD(pnode *head) {
    char NodeID;
    scanf("%c", &NodeID);
    while(isdigit(NodeID)) {
        int id = NodeID - '0';
        delete_node_cmd(head, id);
        scanf("%c", &NodeID);
    }
    return NodeID;
}

int caseS(pnode *head){
    char Start;
    scanf("%c", &Start);
    while(isdigit(Start)){
        char Dest;
        scanf("%c", &Dest);
        int start = Start - '0';
        int dest =  Dest - '0';
        int res = shortestPath(head,start,dest);
        printf("Dijsktra shortest path: %d\n", res);
        scanf("%c", &Start);
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
    int res = TSP_cmd(head, Nodes, HowLong);
    printf("TSP shortest path: %d\n", res);
    char NextChar;
    scanf("%c", &NextChar);
    return NextChar;
}


int main() {
    pnode n1 = (pnode) malloc(sizeof(node));
    pnode *head = &n1;
    char input;
    scanf("%c", &input);
//    while (input != 'E') {
        switch (input) {
            case 'A':
                input = caseA(head);
            case 'B':
                input = caseB(head);
            case 'D':
                input = caseD(head);
            case 'S':
                input = caseS(head);
            case 'T':
                input = caseT(head);
        }
//    }
}

