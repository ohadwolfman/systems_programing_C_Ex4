#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define dependencies (c!='A') && (c!='B') && (c!='D') && (c!='S') && (c!='T')

void build_graph(pnode head,int num_vertices,pnode vertices) {
    char c;

    //Initializing an array will contain the names of the vertices,
    // the vertices connected in a linked list to the neighbors of each of them
    for (int i = 0; i < num_vertices; ++i) {
        pnode new_node = NULL;
        scanf("%c", &c);
        if(c=='n') {
            int vertex_num, neighbor, weight;
            scanf("%d", &vertex_num);
            new_node = (pnode) malloc(sizeof(node));
            new_node->node_num = vertex_num;
            new_node->edges = NULL;
            new_node->next = NULL;

            if (scanf("%d", &neighbor) == EOF) //if we arrived to the last vertex with no edges
                break;

            pedge p;
            while (neighbor != 'n'){
                scanf("%d", &weight);
                pedge new_edge = (pedge) malloc(sizeof(edge));
                new_edge->weight = weight;
                new_edge->next = NULL;
                new_edge->endpoint=vertices + neighbor;
                p = new_edge;

                if (new_node->edges == NULL) {
                    new_node->edges = p;
                } else {
                    new_node->edges->next = p;
                    p->next = NULL;
                }

                if (head == NULL) {
                    head = new_node;
                    head->next=NULL;
                }
                else {
                    pnode p = head;
                    while (p->next != NULL)
                        p = p->next;
                    p->next = new_node;
                    new_node->next = NULL;
                }
                scanf("%d", &neighbor);
                c = neighbor;
            }
        }
    }
    vertices=head;
}

void insert_node(pnode head, int num_vertices) {

}

void delete_node(pnode head) {

}

void shortsPath(pnode head) {

}

void multipleShortestPath(pnode head) {

}

void deleteGraph(pnode head){

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
