#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void build_graph(pnode *head);
void insert_node(pnode *head);
void delete_node(pnode *head);
void printGraph(pnode head); //for self debug
void deleteGraph(pnode* head);
void shortsPath(pnode head);
void multipleShortestPath(pnode head);

#endif
