#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define dependencies (c!='A') && (c!='B') && (c!='D') && (c!='S') && (c!='T')


void build_graph(pnode *head) {
    int num_vertices, vertex_num, neighbor, weight;
    char c;
    *head = NULL;

    //Initializing an array will contain the names of the vertices,
    // the vertices connected in a linked list to the neighbors of each of them
    scanf(" %d", &num_vertices);
    struct node *vertices[num_vertices];
    for (int i = 0; i <num_vertices ; ++i) {
        vertices[i]=NULL;
    }

    while (scanf(" %c", &c) != EOF && dependencies){
        if(c=='n'){
            scanf(" %d", &vertex_num);
            pnode new_node = (pnode)malloc(sizeof(node));
            new_node->node_num = vertex_num;
            new_node->edges = NULL;
            new_node->next = *head;
            *head = new_node;

            while (scanf("%d %d", &neighbor, &weight) == 2) {
                if (neighbor<0) {
                    break;
                }
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

void insert_node(pnode *head) {

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


