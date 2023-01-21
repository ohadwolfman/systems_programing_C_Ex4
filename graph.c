#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define INFINITE 9999999

graph* createGraphHeader() {
    graph *G = (graph *)malloc(sizeof(graph));
    G->number_vertices = 0;
    G->head = NULL;
    return G;
}

pnode addNode(graph* G, int num){
    pnode pointer = G->head;
    while(pointer->next!=NULL){
        if(pointer->node_num==num)
            return pointer;
        pointer=pointer->next;
    }
    pnode p = (pnode) malloc(sizeof(p));;
    p->node_num=num;
    p->next=NULL;
    p->edges=NULL;
    *(pointer->next) = *p;
    free(pointer);
    return p;
}

void addEdge(pnode node, int weight, pnode endpoint){
    pedge q=node->edges;
    while(q->next!=NULL){
        q=q->next;
    }
    pedge newEdge =(pedge) malloc(sizeof(edge));;
    newEdge->endpoint=endpoint;
    newEdge->weight=weight;
    q->next=newEdge;
    free(q);
}

void build_graph(graph* G) {
    int d;
    for (int i = 0; i < (G->number_vertices); ++i) {
        scanf(" %d",&d);
        if ((char)d == 'n') {
            pnode newNode;
            int vertex_num, weight;
            pnode neighbor;
            scanf(" %d",&vertex_num);
            newNode=addNode(G, vertex_num);

            if(scanf(" %d",&d)==EOF){
                break;
            }

            while ((char)d != 'n') {
                neighbor = addNode(G, d);
                scanf(" %d", &weight);
                addEdge(newNode, weight,neighbor);

                scanf(" %d",&d);
            }
        }
    }
}

void insert_node(pnode head) {
    int vertex_num, neighbor, weight;
    scanf(" %d", &vertex_num);

    pnode new_node = (pnode)malloc(sizeof(node));
    new_node->node_num = vertex_num;
    new_node->edges = NULL;
    new_node->next = NULL;
    pedge p;
    scanf(" %d", &neighbor);

    if (neighbor == EOF || neighbor == 65 || neighbor == 66 || neighbor == 68 || neighbor == 83 || neighbor == 84 || neighbor == '\0')
    {
        return;
    }
    while (neighbor == EOF || neighbor != 65 || neighbor != 66 || neighbor != 68 || neighbor != 83 || neighbor != 84 || neighbor != '\0') {
        //fscanf(file, "%c", &weight);
        weight = getchar();
        while (weight == ' ')
        {
            weight = getchar();
            // fscanf(file, "%c", &weight);
        }
        weight = weight - '0';
        neighbor = neighbor - '0';
        pedge new_edge = (pedge)malloc(sizeof(edge));
        new_edge->weight = weight;
        new_edge->endpoint = head + neighbor;
        new_edge->next = NULL;
        p = new_edge;
        if (new_node->edges == NULL) {
            new_node->edges = p;
        }
        else {
            new_node->edges->next = p;
            p->next = NULL;
        }
        neighbor = getchar();
        if (neighbor == EOF || neighbor == '\0')
        {
            break;
        }
        while (neighbor == ' ')
        {
            neighbor = getchar();
            //    fscanf(file, "%c", &neighbor);
        }
        if (neighbor == EOF || neighbor == '\0')
        {
            break;
        }
    }
    pnode current = head;
    pnode prev = NULL;
    while (current != NULL) {
        if (current->node_num == vertex_num) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
    if (head == NULL) {
        head = new_node;
        head->next = NULL;
    }
    else {
        pnode p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = new_node;
        new_node->next = NULL;
    }
}

void delete_node(pnode head)
{
    int node_num;
    node_num = getchar();
    while (node_num==' ')
    {
        node_num = getchar();
    }
    node_num = node_num - '0';
    pnode current = head;
    pnode previous = NULL;
    while (current != NULL) {
        if (current->node_num == node_num) {
            // Remove the node by adjusting the pointers of the previous and next nodes
            if (previous != NULL) {
                previous->next = current->next;
            }
                // If the node to be deleted is the head, update the head pointer
            else {
                head = current->next;
            }

            // Now we have to remove all edges from the node and from all the other nodes
            pedge edge = current->edges;
            while (edge != NULL) {
                delete_edge(edge->endpoint, node_num);
                edge = edge->next;
            }

            //free memory
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void delete_edge(pnode head, int node_num) {
    pnode current = head;
    pedge edge = current->edges;
    pedge prev = NULL;
    while (edge != NULL) {
        if (edge->endpoint->node_num == node_num) {
            if (prev != NULL) {
                prev->next = edge->next;
            }
            else {
                current->edges = edge->next;
            }
            free(edge);
            return;
        }
        prev = edge;
        edge = edge->next;
    }
}
void shortsPath(pnode head)
{
    int num_vertices = 0;
    pnode temp = head;
    while (temp != NULL)
    {
        num_vertices++;
        temp = temp->next;
    }
    int* dist = (int*)malloc(num_vertices * sizeof(int));
    int* visited = (int*)malloc(num_vertices * sizeof(int));
    int* previous = (int*)malloc(num_vertices * sizeof(int));
    int current_node;
    int i, j;

    // Initialize distances, visited and previous arrays
    for (i = 0; i < num_vertices; i++) {
        dist[i] = INFINITE;
        visited[i] = 0;
        previous[i] = -1;
    }

    // Set the distance of the starting node to 0
    int start_node = getchar();
    while (start_node == ' ')
    {
        start_node = getchar();
    }
    start_node = start_node - '0';
    dist[start_node] = 0;

    // Repeat the algorithm until all nodes have been visited
    for (i = 0; i < num_vertices; i++) {
        current_node = -1;
        for (j = 0; j < num_vertices; j++) {
            if (!visited[j] && (current_node == -1 || dist[j] < dist[current_node])) {
                current_node = j;
            }
        }

        // Mark the current node as visited
        visited[current_node] = 1;

        // Update the distances of the neighboring nodes
        pnode current = head + current_node;
        pedge edge = current->edges;
        while (edge != NULL) {
            int new_dist = dist[current_node] + edge->weight;
            if (new_dist < dist[edge->endpoint->node_num]) {
                dist[edge->endpoint->node_num] = new_dist;
                previous[edge->endpoint->node_num] = current_node;
            }
            edge = edge->next;
        }
    }

    // Print the shortest path
    int end_node = getchar();
    while (end_node == ' ')
    {
        end_node = getchar();
    }
    end_node = end_node - '0';
    if (dist[end_node] != INFINITE) {
        printf("Dykstra Shortest path  %d\n", dist[end_node]);
        /*printf("Path: %d", end_node);
        int current = end_node;
        while (current != start_node) {
            printf("<-%d", previous[current]);
            current = previous[current];
        }*/
    }
    else {
        printf("No path from node %d to node %d", start_node, end_node);
    }
    free(dist);
    free(visited);
    free(previous);
}

void multipleShortestPath(pnode head)
{
    int num_vertices = 0;
    pnode temp = head;
    while (temp != NULL)
    {
        num_vertices++;
        temp = temp->next;
    }
    int* dist = (int*)malloc(num_vertices * sizeof(int));
    int* visited = (int*)malloc(num_vertices * sizeof(int));
    int* previous = (int*)malloc(num_vertices * sizeof(int));
    int current_node;
    int i, j;

    // Initialize distances, visited and previous arrays
    for (i = 0; i < num_vertices; i++) {
        dist[i] = INFINITE;
        visited[i] = 0;
        previous[i] = -1;
    }
    int num_vert;
    num_vert = getchar();
    while (num_vert == ' ')
    {
        num_vert = getchar();
    }
    num_vert = num_vert - '0';
    int* nodes_to_visit = (int*)malloc(num_vert * sizeof(int));

    // Set the distance of the starting node to 0
    int start_node;

    for (int i = 0; i < num_vert; i++)
    {
        current_node = getchar();
        while (current_node == ' ')
        {
            current_node = getchar();
        }
        current_node = current_node - '0';
        nodes_to_visit[i] = current_node;
    }
    start_node = nodes_to_visit[0];
    dist[start_node] = 0;

    // Repeat the algorithm until all nodes have been visited
    for (i = 0; i < num_vertices; i++) {
        current_node = -1;
        for (j = 0; j < num_vertices; j++) {
            if (!visited[j] && (current_node == -1 || dist[j] < dist[current_node])) {
                current_node = j;
            }
        }

        // Mark the current node as visited
        visited[current_node] = 1;

        // Update the distances of the neighboring nodes
        pnode current = head + current_node;
        pedge edge = current->edges;
        while (edge != NULL) {
            int new_dist = dist[current_node] + edge->weight;
            if (dist[edge->endpoint->node_num]<0)
            {
                dist[edge->endpoint->node_num] = new_dist;
                previous[edge->endpoint->node_num] = current_node;
            }
            if (new_dist < dist[edge->endpoint->node_num]) {
                dist[edge->endpoint->node_num] = new_dist;
                previous[edge->endpoint->node_num] = current_node;
            }
            edge = edge->next;
        }
    }
    int end_node = nodes_to_visit[num_vert - 1];
    if (dist[end_node] != INFINITE) {
        printf("TSP Shortest path  %d\n", dist[end_node]);
        /*printf("Path: %d", end_node);
        int current = end_node;
        while (current != start_node) {
            printf("<-%d", previous[current]);
            current = previous[current];
        }*/
    }
    else {
        printf("No path from node %d to node %d", start_node, end_node);
    }

    free(visited);
    free(nodes_to_visit);
}


void deleteGraph(pnode head) {
    pnode tempN = head;
    pedge tempE;
    while (tempN != NULL)
    {
        tempE = tempN->edges;
        while(tempE!=NULL){
            pedge prevEdge=tempE;
            tempE=tempE->next;
            free(prevEdge);
        }
        tempN = head->next;
        free(head);
        head = tempN;
    }
}


void printGraph(graph G) {
    pnode p = G.head;
    while (p != NULL) {
        printf("edges of %d:", p->node_num);
        pedge e = p->edges;
        while (e != NULL) {
            printf("%d has edge to node: %d with weight:%d\n", p->node_num, e->endpoint->node_num, e->weight);
            e = e->next;
        }
        p = p->next;
    }
    printf("-------------\n");
}