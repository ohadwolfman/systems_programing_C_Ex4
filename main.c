#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int number_of_vertices;
int weight;
void createNewGraph();
void createNode();
void delete_node();
void shortestPath();
void multipleShortestPath();

int main() {
    char c;
    while (scanf("%c", &c) != EOF){
        if (c == 'A') {
            while (scanf("%c", &c) != EOF && (c!='A'&&'B'&&'D'&&'S'&&'T')) {
                createNewGraph();
            }
        }
        if (c == 'B') {
            while (scanf("%c", &c) != EOF && (c!='A'&&'B'&&'D'&&'S'&&'T')) {
                createNode(c);
            }
        }
        if (c == 'D') {
            while (scanf("%c", &c) != EOF);
            delete_node(c);
        }
        if (c == 'S') {
            while (scanf("%c", &c) != EOF);
            shortestPath(c);
        }
        if (c == 'T') {
            while (scanf("%c", &c) != EOF);
            multipleShortestPath(c);
    }
}
    return 0;
}
void createNewGraph() {
//    if(!pnode*) {
//        deleteGraph_cmd(*root);
//    }

    //Initializing an array will contain the names of the vertices,
    // the vertices connected in a linked list to the neighbors of each of them
    scanf("%d", &number_of_vertices);
    struct node *vertices[number_of_vertices];
    for (int i = 0; i <number_of_vertices ; ++i) {
        vertices[i]=NULL;
    }

    char c;
    while (scanf("%c", &c) != EOF && (c!='A'&&'B'&&'D'&&'S'&&'T')){
        if(c=='n'){
            createNode(vertices);
        }
    }
}

void createNode(node vertices) {
    struct node *ver;
    int adj;
    int edge;
    char c;
    scanf("%d", &ver);
    ver = (struct node*)malloc(sizeof (struct node*));
//    vertices[0] = ver;
    scanf("%d", &adj);
    ver->adj = adj;
    while (scanf("%c", &c) != EOF && (c!='A')&&(c!='B')&&(c!='D')&&(c!='S')&&(c!='T')&&(c!='n')) {
        ver->edge = (int)c;

    }
}

void delete_node() {

}

void shortestPath() {

}

void multipleShortestPath() {

}


