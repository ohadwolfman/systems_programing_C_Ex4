#ifndef GRAPH_H
#define GRAPH_H
char String[200];
int Index;

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
} node, * pnode;

int check(int n);
void build_graph(pnode* head, int num_vertices, pnode vertices);
pnode insert_node(pnode* head, pnode vertices, int* size);
void delete_node(pnode head);
void printGraph(pnode head); //for self debug
void deleteGraph(pnode head);
void shortsPath(pnode head);
int  Dijkstra(pnode head, int start, int node1);
void multipleShortestPath(pnode head);
void delete_edge(pnode head, int node_num);
int TSP(pnode head, int* nodes_to_visit, int size);
#endif