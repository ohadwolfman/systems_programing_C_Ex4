#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_* pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_* next;
} edge, * pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_* next;
} node, *pnode;

typedef struct graph {
    int number_vertices;
    pnode head;
} graph;

void build_graph(graph* G);
void insert_node(pnode head);
void delete_node(pnode head);
void printGraph(graph G); //for self debug
void deleteGraph(pnode head);
void shortsPath(pnode head);
void multipleShortestPath(pnode head);
void delete_edge(pnode head, int node_num);
graph* createGraphHeader();

#endif