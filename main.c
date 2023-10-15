#include <stdio.h>

#include "disjoint_set.h"
#include "graph.h"

int main() {
    int edge_size, vertex_size;
    scanf("%d%d", &edge_size, &vertex_size);
    struct Graph *graph = create_graph(vertex_size);
    for (int i = 0; i < edge_size; i++) {
        int v1, v2, weight;
        scanf("%d%d%d", &v1, &v2, &weight);
        add_edge(graph, v1, v2, weight);
    }
    struct Graph *mst = kruskal(graph);
    print_graph(mst);
    free_graph(graph);
    free_graph(mst);
    return 0;
}
