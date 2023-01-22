#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define INFINITE 9999999
char String[200];
int Index;
int check(int n)
{
    if (n == EOF || n == 65 || n == 66 || n == 68 || n == 83 || n == 84 || n == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void build_graph(pnode* head, int num_vertices, pnode vertices) {
    char c;

    for (int i = 0; i < num_vertices; ++i)
    {
        c = String[Index++];
        while (c == ' ')
        {
            c = String[Index++];
        }
        if (c == 'n') {
            int vertex_num, neighbor, weight;
            vertex_num = String[Index++];
            while (vertex_num == ' ')
            {
                vertex_num = String[Index++];
            }
            vertex_num = vertex_num - '0';
            vertices[vertex_num].node_num = vertex_num;
            vertices[vertex_num].edges = NULL;
            vertices[vertex_num].next = NULL;
            pnode new_node = &vertices[vertex_num];
            neighbor = String[Index++];
            while (neighbor == ' ')
            {
                neighbor = String[Index++];
            }
            if (neighbor == '\0' || neighbor == EOF || neighbor == 65 || neighbor == 66 || neighbor == 68 || neighbor == 83 || neighbor == 84 || neighbor == '\0')
            {
                if (*head == NULL) {
                    *head = new_node;
                    (*head)->next = NULL;
                }
                else {
                    pnode p = *head;
                    while (p->next != NULL)
                        p = p->next;
                    p->next = new_node;
                    new_node->next = NULL;
                }
                break;
            }
            while (neighbor != 'n' && check(neighbor) != 1)
            {
                weight = String[Index++];
                while (weight == ' ')
                {
                    weight = String[Index++];
                }
                weight = weight - '0';
                pedge new_edge = (pedge)malloc(sizeof(edge));
                new_edge->weight = weight;
                new_edge->next = NULL;
                neighbor = neighbor - '0';
                new_edge->endpoint = &vertices[neighbor];
                if (new_node->edges == NULL) {
                    new_node->edges = new_edge;
                }
                else {
                    pedge p = new_node->edges;
                    while (p->next != NULL)
                        p = p->next;
                    p->next = new_edge;
                }
                neighbor = String[Index++];
                if (neighbor == EOF || neighbor == '\0')
                {
                    break;
                }
                while (neighbor == ' ')
                {
                    neighbor = String[Index++];
                }
                if (neighbor == EOF || neighbor == '\0')
                {
                    break;
                }
            }
            Index--;
            if (*head == NULL) {
                *head = new_node;
                (*head)->next = NULL;
            }
            else {
                pnode p = *head;
                while (p->next != NULL)
                    p = p->next;
                p->next = new_node;
                new_node->next = NULL;
            }
        }
    }
    Index--;
}
pnode insert_node(pnode* head, pnode vertices, int* size)
{
    pnode new_node;
    int ch=0, loop;
    int vertex_num, neighbor, weight;
    vertex_num = String[Index++];
    while (vertex_num == ' ')
    {
        vertex_num = String[Index++];
    }
    vertex_num = vertex_num - '0';
    if (vertex_num < *size && vertices[vertex_num].node_num > 0) {
        //delete_edge(*head,vertex_num);
        vertices[vertex_num].edges = NULL;
        new_node = &vertices[vertex_num];
    }
    else if (vertex_num<*size&& vertices[vertex_num].node_num<0)
    {
        new_node = &vertices[vertex_num];

    }
    else
    {
        ch = 1;
        loop = *size;
        if (vertex_num>*size)
        {
            *size = vertex_num+1;

        }
        vertices = (pnode)realloc(vertices, *size * sizeof(node));
        *head=&vertices[0];
        for (int k = 0; k < loop; ++k)
        {
            pedge temp;
            temp=vertices[k].edges;
            while (temp!=NULL)
            {
                if(temp->endpoint->node_num>loop)
                {
                    temp->endpoint->node_num=vertices[0].node_num;
                }
                temp=temp->next;
            }
        }
        for (int i = loop; i < *size; i++)
        {
            vertices[i].node_num = -1;
        }
        vertices[*size - 1].node_num = vertex_num;
        vertices[*size - 1].edges = NULL;
        vertices[*size - 1].next = NULL;
        new_node = &vertices[*size - 1];
    }
    neighbor = String[Index++];
    while (neighbor == ' ')
    {
        neighbor = String[Index++];
    }
    if (neighbor == '\0' || neighbor == EOF || neighbor == 65 || neighbor == 66 || neighbor == 68 || neighbor == 83 || neighbor == 84 || neighbor == '\0')
    {
        Index--;
    }
    else
    {
        while (neighbor != 'n' && check(neighbor) != 1)
        {
            weight = String[Index++];
            while (weight == ' ')
            {
                weight = String[Index++];
            }
            weight = weight - '0';
            pedge new_edge = (pedge)malloc(sizeof(edge));
            new_edge->weight = weight;
            new_edge->next = NULL;
            neighbor = neighbor - '0';
            new_edge->endpoint = &vertices[neighbor];
            if (new_node->edges == NULL) {
                new_node->edges = new_edge;
            }
            else {
                pedge p = new_node->edges;
                while (p->next != NULL)
                    p = p->next;
                p->next = new_edge;
            }
            neighbor = String[Index++];
            if (neighbor == EOF || neighbor == '\0')
            {
                break;
            }
            while (neighbor == ' ')
            {
                neighbor = String[Index++];
            }
            if (neighbor == EOF || neighbor == '\0')
            {
                break;
            }
        }
        Index--;
    }
    if (*head == NULL) {
        *head = &vertices[vertex_num];
        (*head)->next = NULL;
    }
    else {
        if (ch == 0)
        {
            pnode p = *head;
            while (p->node_num != vertex_num)
            {
                p = p->next;
            };
            p->edges = new_node->edges;
        }
        else
        {
            pnode p = *head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = &vertices[*size - 1];
            vertices[*size - 1].next = NULL;
        }
    }
    return vertices;
}

void delete_node(pnode head)
{
    int vertex_num;
    vertex_num = String[Index++];
    while (vertex_num == ' ')
    {
        vertex_num = String[Index++];
    }
    vertex_num = vertex_num - '0';

    pnode current = head;
    while (current != NULL) {
        pedge edge = current->edges;
        pedge prev = NULL;
        while (edge != NULL) {
            if (edge->endpoint->node_num == vertex_num) {
                if (prev == NULL) {
                    current->edges = edge->next;
                }
                else {
                    prev->next = edge->next;
                }
                free(edge);
                break;
            }
            prev = edge;
            edge = edge->next;
        }
        current = current->next;
    }
    current = head;
    while (current != NULL) {
        if (current->node_num == vertex_num) {
            break;
        }
        current = current->next;
    }
    if (current != NULL) {
        pedge edge = current->edges;
        while (edge != NULL) {
            pedge temp = edge->next;
            free(edge);
            edge = temp;
        }
    }
    head[vertex_num].edges = NULL;
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
    for (i = 0; i < num_vertices; i++) {
        dist[i] = INFINITE;
        visited[i] = 0;
        previous[i] = -1;
    }
    int start_node = String[Index++];
    while (start_node == ' ')
    {
        start_node = String[Index++];
    }
    start_node = start_node - '0';
    dist[start_node] = 0;
    for (i = 0; i < num_vertices; i++) {
        current_node = -1;
        for (j = 0; j < num_vertices; j++) {
            if (!visited[j] && (current_node == -1 || dist[j] < dist[current_node])) {
                current_node = j;
            }
        }
        visited[current_node] = 1;
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

    int end_node = String[Index++];
    while (end_node == ' ')
    {
        end_node = String[Index++];
    }
    end_node = end_node - '0';
    if (dist[end_node] != INFINITE) {
        printf("Dijsktra shortest path: %d\n", dist[end_node]);
    }
    else
    {
        printf("-1");
    }
    free(dist);
    free(visited);
    free(previous);
}

void multipleShortestPath(pnode head,int total)
{
    int num_vert;
    num_vert = String[Index++];
    while (num_vert == ' ')
    {
        num_vert = String[Index++];
    }
    num_vert = num_vert - '0';
    int* nodes_to_visit = (int*)malloc(num_vert * sizeof(int));
    int current_node;
    for (int i = 0; i < num_vert; i++)
    {
        current_node = String[Index++];
        while (current_node == ' ')
        {
            current_node = String[Index++];
        }
        current_node = current_node - '0';
        nodes_to_visit[i] = current_node;
    }
    current_node = TSP(head, nodes_to_visit, num_vert,total);
    Index--;
    if (current_node == INFINITE||current_node>30)
        current_node = -1;
    printf("TSP shortest path: %d\n", current_node);
    free(nodes_to_visit);
}

void deleteGraph(pnode head) {
    pnode current = head;
    while (current != NULL)
    {
        pnode temp = current;
        current = current->next;
        pedge e = temp->edges;
        while (e != NULL) {
            pedge temp_edge = e;
            e = e->next;
            free(temp_edge);
        }
    }
    free(head);
}


void printGraph(pnode head) {
    pnode p = head;
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
void permute(int arr[], int n, int result[][10], int* count, int level) {
    if (level == n) {
        for (int i = 0; i < n; i++)
        {
            result[*count][i] = arr[i];
        }
        *count += 1;
        return;
    }
    for (int i = level; i < n; i++) {
        int temp = arr[level];
        arr[level] = arr[i];
        arr[i] = temp;
        permute(arr, n, result, count, level + 1);
        temp = arr[level];
        arr[level] = arr[i];
        arr[i] = temp;
    }
}

int TSP(pnode head, int* nodes_to_visit, int size,int total) {
    int* check = (int*)malloc(size * sizeof(int));
    int min_cost = 0;
    int result[100][10] = { 0 };
    int count = 0;
    int v=0;
    int final = INFINITE;
    permute(nodes_to_visit,size, result, &count, 0);
    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < size; i++)
        {
            check[i] = 0;
        }
        min_cost = 0;
        check[0] = 1;
        for (int i = 0; i < size; i++)
        {
            if (check[(i + 1) % size] != 1)
            {
                int node1 = result[j][i];
                int node2 = result[j][(i + 1) % size];
                v= Dijkstra(head, node1, node2,total);
                if(v<INFINITE)
                {
                    min_cost +=v;
                } else
                {
                    min_cost=INFINITE;
                    break;
                }
                check[i + 1] = 1;
            }
        }
        if (min_cost<final&&min_cost>0)
        {
            final = min_cost;
        }
    }
    free(check);
    return final;
}
int Dijkstra(pnode head, int start, int node1,int total)
{
    if(head[start].edges==NULL)
        return INFINITE;
    int* dist = (int*)malloc(total * sizeof(int));
    int* visited = (int*)malloc(total * sizeof(int));
    int* previous = (int*)malloc(total * sizeof(int));
    int current_node;
    int i, j;
    for (i = 0; i < total; i++) {
        dist[i] = INFINITE;
        visited[i] = 0;
        previous[i] = -1;
    }
    int start_node = start;
    dist[start_node] = 0;
    for (i = 0; i < total; i++) {
        if (head[i].node_num != -1)
        {
            current_node = -1;
        }
        for (j = 0; j < total; j++) {
            while (head[j].node_num == -1)
            {
                j++;
            }
            if (!visited[j] && (current_node == -1 || dist[j] < dist[current_node]))
            {
                current_node = j;
            }
        }
        visited[current_node] = 1;
        pnode current = head + current_node;
        pedge edge = current->edges;
        while (edge != NULL) {
            int new_dist = dist[current_node] + edge->weight;
            if (new_dist>INFINITE)
            {
                new_dist = edge->weight;
            }
            if (new_dist < dist[edge->endpoint->node_num]) {
                dist[edge->endpoint->node_num] = new_dist;
                previous[edge->endpoint->node_num] = current_node;
            }
            edge = edge->next;
        }
    }
    int end_node = node1;
    start=dist[end_node] ;
    return start;
}