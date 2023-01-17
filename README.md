# systems_programing_C_Ex4

In this code we will implement weighted directed graph.

The progeam use an array of linked lists to save the vertices, as long as the first cell in the array is the current vertex, and the linked list after it is all the edges it is connected to.

Details of the functions:
For command A, followed by number of the vertices - the program will create a new graph (delete the previous graph if there was one) Every time that the user wants to start working on a new vertex he will enter n followed by the number of the vertex and then Pairs of numbers where the first symbolizes the position of the bow and the second its weight

For command B we will create a new vertex with a number that the user will give us and its edges (if The vertex already exists, delete all the arcs coming out of it and update to the news but do not disconnect the arcs entering it)

For the command D followed by number we will delete the vertex we received

For the command S with two numbers we will print the length of the shortest path between the two vertices or -1 if there is no route

For the command T followed by a number k followed by k numbers that represent vertices we will print the length of the shortest path at most that starts at some vertex and works through all the other vertices
