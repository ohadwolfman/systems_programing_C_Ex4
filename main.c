#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define dependencies (c!='A')&&(c!='B')&&(c!='D')&&(c!='S')&&(c!='T')

int number_of_vertices;

int main() {
    char fuction;
    char c;
    pnode* head=NULL;
    while (scanf("%c", &fuction) != EOF){
        if (fuction == 'A') {
            if (head!=NULL)
            {
                deleteGraph(head);
            }
            while (scanf(" %c", &c) != EOF && dependencies) {
                build_graph( *head);
            }
            printGraph(*head);
        }
        if (fuction == 'B') {
            while (scanf(" %c", &c) != EOF && dependencies) {
                insert_node(*head);
            }
        }
        if (fuction == 'D') {
            while (scanf(" %c", &c) != EOF && dependencies);
            delete_node(*head);
        }
        if (fuction == 'S') {
            while (scanf(" %c", &c) != EOF && dependencies);
            shortsPath(head);
        }
        if (fuction == 'T') {
            while (scanf(" %c", &c) != EOF && dependencies);
            multipleShortestPath(c);
        }
    }
    return 0;
}