#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    char function;
    int num_vertices;
    pnode head=NULL;
    pnode vertices=NULL;

    while (scanf("%c", &function) != EOF){
        if (function == 'A') {
            scanf("%d", &num_vertices);
            vertices = (pnode)malloc(num_vertices*sizeof(node));
            head!=NULL ? deleteGraph(head) : head;

            build_graph(head,num_vertices, vertices);
            printGraph(head);
        }

        else if (function == 'B') {
            insert_node(head,num_vertices);
        }
        else if (function == 'D') {
            delete_node(head);
        }
        else if (function == 'S') {
            shortsPath(head);
        }
        else if (function == 'T') {
            multipleShortestPath(head);
        }
    }
    return 0;
}