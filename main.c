#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    char function;
    int num_vertices;
    pnode *vertices;
    vertices = (pnode)malloc(num_vertices*sizeof(node));

    scanf(" %d", &num_vertices);
    pnode *head=(pnode)malloc(sizeof(pnode));
    while (scanf("%c", &function) != EOF){
        if (function == 'A') {
            head!=NULL ? deleteGraph(head) : NULL;

            build_graph( *head,num_vertices, vertices);
            printGraph(*head);
        }

        if (function == 'B') {
            insert_node(*head,num_vertices);
        }
        if (function == 'D') {
            delete_node(*head);
        }
        if (function == 'S') {
            shortsPath(head);
        }
        if (function == 'T') {
            multipleShortestPath(head);
        }
    }
    return 0;
}