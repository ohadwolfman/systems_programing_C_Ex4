#include <stdio.h>
#include "graph.h"

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
            delete_node(
            char input);
        }
        if (c == 'S') {
            while (scanf("%c", &c) != EOF);
            shortestPath(
            char input);
        }
        if (c == 'T') {
            while (scanf("%c", &c) != EOF);
            multipleShortestPath(
            char input);
    }
}
    return 0;
}
void createNewGraph() {
    char c;
    while (scanf("%c", &c) != EOF && (c!='A'&&'B'&&'D'&&'S'&&'T')){
        if(c=='n'){
            createNode();
        }
    }
}

void createNode() {
    char c;
    while (scanf("%c", &c) != EOF && (c!='A')&&(c!='B')&&(c!='D')&&(c!='S')&&(c!='T')&&(c!='n')) {

    }
}

void delete_node() {

}

void shortestPath() {

}

void multipleShortestPath() {

}


