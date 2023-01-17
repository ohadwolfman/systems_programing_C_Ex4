#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define dependencies (c!='A') && (c!='B') && (c!='D') && (c!='S') && (c!='T')

void build_graph(pnode *head,int num_vertices,pnode vertices) {
    char c;
    *head = NULL;

    //Initializing an array will contain the names of the vertices,
    // the vertices connected in a linked list to the neighbors of each of them
//    for (int i = 0; i <num_vertices ; ++i) {
//        vertices[i]=NULL;
//    }
//    vertices[0] = head;

    for (int i = 0; i < num_vertices; ++i) {
        scanf(" %c", &c);
        if(c=='n'){
            int vertex_num, neighbor, weight;
            scanf("%d", &vertex_num);
            pnode new_node = (pnode)malloc(sizeof(node));
            new_node->node_num = vertex_num;
            new_node->edges = NULL;
            new_node->next = *head;
            *head = new_node;

            for (int j = 0; j < num_vertices; ++j) {
                scanf("%d %d", &neighbor, &weight);
                pedge new_edge = (pedge)malloc(sizeof(edge));
                new_edge->weight = weight;
                new_edge->next = new_node->edges;
                new_edge->endpoint = *head;
                while(new_edge->endpoint->node_num!=neighbor)
                    new_edge->endpoint = new_edge->endpoint->next;
                new_node->edges = new_edge;
            }
        }
    }
}

void insert_node(pnode *head, int num_vertices) {

}

//    struct node *ver;
//    int adj;
//    int edge;
//    char c;
//    scanf(" %d", &ver);
//    ver = (struct node*)malloc(sizeof (struct node*));
//    vertices[0] = ver;
//    scanf(" %d", &adj);
//    ver->adj = adj;
//    while (scanf(" %c", &c) != EOF && dependencies) {
//        ver->edge = (int)c;
//
//    }

void delete_node(pnode *head) {

}

void shortsPath(pnode head) {

}

void multipleShortestPath(pnode head) {

}

void deleteGraph(pnode* head){

}


void printGraph(pnode head){
    pnode p = head;
    while (p != NULL){
        printf("edges of %d:", p->node_num);
        pedge e = p->edges;
        while (e != NULL){
            printf("%d has edge to node: %d with weight:%d\n", p->node_num, e->endpoint->node_num, e->weight);
            e = e->next;
        }
        p = p->next;
    }
    printf("-------------\n");
}
