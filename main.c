#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    graph* G = NULL;
    char function;

    int num_vertices;

    scanf("%c", &function);
    while (function != EOF) {

        if (function == 'A') {
            scanf(" %d", &num_vertices);
            if (G != NULL) {
                deleteGraph(G->head);
            }
            G = createGraphHeader();
            G->number_vertices = num_vertices;

            build_graph(G);
            printGraph(*G);
        }
        else if (function == 'B') {
            insert_node(G->head);
        }
        else if (function == 'D') {
            delete_node(G->head);
        }
        else if (function == 'S') {
            shortsPath(G->head);
        }
        else if (function == 'T') {
            multipleShortestPath(G->head);
        }
        scanf(" %c", &function);
    }
    free(G);
    return 0;
}