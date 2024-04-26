// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], int size, bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int size)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < size; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int **graph, int num_vs, int src)
{
    int dist[num_vs]; // The output array.  dist[i] will hold the
                      // shortest
    // distance from src to i
    bool sptSet[num_vs]; // sptSet[i] will be true if vertex i is
                         // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < num_vs; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < num_vs - 1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, num_vs, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < num_vs; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, num_vs);
}
// driver's code
int main()
{
    /* Let us create the example graph discussed above */
    size_t num_of_vers;
    int dist;
    printf("please enter num of vertexs in the graph: \n");
    scanf("%zu", &num_of_vers);
    int **graph = (int **)malloc(num_of_vers * sizeof(int *));
    for (size_t i = 0; i < num_of_vers; i++)
    {
        graph[i] = (int *)malloc(num_of_vers * sizeof(int));
    }
    for (size_t i = 0; i < num_of_vers; i++)
    {
        for (size_t j = 0; j < num_of_vers; j++)
        {
            scanf("%d", &dist);
            char c = getchar();
            if (dist < 0)
            {
                printf("ERROR! dijkstra dos not soppurt negative weights!\n");
                return -1;
            }
            if (i == j && dist != 0)
            {
                printf("ERROR! distance from vertex to itself must be 0\n");
                return -1;
            }
            if (j == num_of_vers - 1 && c != '\n')
            {
                printf("ERROR! too many distances\n");
                return -1;
            }
            if (j != num_of_vers - 1 && c == '\n')
            {
                printf("ERROR! too few distances\n");
                return -1;
            }
            graph[i][j] = dist;
        }
    }
    dijkstra(graph, num_of_vers, 0);

    for (size_t i=0; i<num_of_vers;i++)
    {
            free(graph[i]);
    }
    free(graph);
    return 0;
}
