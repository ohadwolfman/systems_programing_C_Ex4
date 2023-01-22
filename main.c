#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
extern int Index;
extern char String[200];
int main()
{
    Index = 0;
    char function;
    int num_vertices;
    pnode head = NULL;
    pnode vertices = NULL;
    fgets(String, 200, stdin);
    function = String[Index++];
    while (function != EOF && function != '\0')
    {
        if (function == 'A') {
            num_vertices = String[Index++];
            while (num_vertices == ' ')
            {
                num_vertices = String[Index++];

            }
            num_vertices = num_vertices - '0';
            if (head != NULL)
            {
                deleteGraph(vertices);
                vertices = NULL;
                head = NULL;
            }
            vertices = (pnode)malloc(num_vertices * sizeof(node));
            build_graph(&head, num_vertices, vertices);
        }

        else if (function == 'B')
        {
            vertices=insert_node(&head,vertices,&num_vertices);
        }
        else if (function == 'D')
        {
            delete_node(head);
        }
        else if (function == 'S')
        {
            shortsPath(head);
        }
        else if (function == 'T')
        {
            multipleShortestPath(head,num_vertices);
        }
        function = String[Index++];
        while (function == ' ')
        {
            function = String[Index++];
        }
    }
    return 0;
}