#include <stdio.h>
#include <ctype.h>
#include "Node.c"
#include "Edge.c"
#include "Algo.c"

int main() {
    pnode n1 = (pnode) malloc(sizeof(node));
    pnode *head = &n1;
    char input;
    scanf("%c", &input);
    while (1) {
        switch (input) {
            case 'A':
                input = caseA(*head);
            case 'B':
                input = caseB(head);
            case 'D':
                input = caseD(head);
            case 'S':
                input = caseS(head);
            case 'T':
                input = caseT(head);
        }
    }
}

int caseA(pnode *head) {
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    int CheckOrWeight;
    scanf("%d", &CheckOrWeight);
    if(CheckOrWeight == 'n') {
        int NodeID;
        scanf("%d", &NodeID);
        insert_node_cmd(head);
        while(isdigit(CheckOrWeight)){
            scanf("%d", &CheckOrWeight);
            int dest;
            scanf("%d", &dest);
            addEdge(head,NodeID, CheckOrWeight, dest);
            scanf("%d", &CheckOrWeight);
        }
        return CheckOrWeight;
    }
}

int caseB(pnode *head) {
    char NodeID;
    scanf("%c", &NodeID);
    while(isdigit(NodeID)) {
        int id = NodeID - '0';
        int Dest;
        scanf("%d", &Dest);
        int Weight;
        scanf("%d", &Weight);
        B(head, id, Weight, Dest);
        scanf("%c", &NodeID);
    }
    return NodeID;
}

int caseD(pnode *head) {
    char NodeID;
    scanf("%c", &NodeID);
    while(isdigit(NodeID)) {
        int id = NodeID - '0';
        delete(head, id);
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
        shortestPath(head,start,dest);
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
    tsp(head, Nodes, HowLong);
    char NextChar;
    scanf("%c", &NextChar);
    return NextChar;
}

