#include "graph.h"
#include "disjoint_set.h"
#include <stdlib.h>
#include <stdio.h>

int print_before(struct edge *e1, struct edge *e2) {
    if (e1->v1 < e2->v1) return 1;
    else if (e1->v1 > e2->v1) return 0;
    else {
        if (e1->v2 < e2->v2) return 1;
        else if (e1->v2 > e2->v2) return 0;
        else {
            if (e1->weight < e2->weight) return 1;
            else return 0;
        }
    }
}

int weight_before(struct edge *e1, struct edge *e2) {
    return e1->weight < e2->weight;
}

struct Graph *create_graph(int vertex_size) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("malloc failed\n");
        exit(1);
    }
    int max_edge_size = vertex_size * (vertex_size - 1) / 2;
    graph->edges = (struct edge *)malloc(sizeof(struct edge) * (unsigned long)max_edge_size);
    if (graph->edges == NULL) {
        printf("malloc failed\n");
        exit(1);
    }
    graph->edge_size = 0;
    graph->vertex_size = vertex_size;
    return graph;
}

void free_graph(struct Graph *graph) {
    free(graph->edges);
    free(graph);
}

void add_edge(struct Graph *graph, int v1, int v2, int weight) {
    if (v1> v2) {
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }
    if (v1 >= graph->vertex_size || v2 >= graph->vertex_size) {
        printf("vertex out of range\n");
        exit(1);
    }
    if (graph->edge_size == graph->vertex_size * (graph->vertex_size - 1) / 2) {
        printf("graph is full\n");
        exit(1);
    }
    graph->edges[graph->edge_size].v1 = v1;
    graph->edges[graph->edge_size].v2 = v2;
    graph->edges[graph->edge_size].weight = weight;
    graph->edge_size++;
}

void sort_edges(struct Graph *graph, compare_func compare) {
    for (int i = 0; i < graph->edge_size; i++) {
        for (int j = i + 1; j < graph->edge_size; j++) {
            if (compare(&graph->edges[j], &graph->edges[i])) {
                struct edge tmp = graph->edges[i];
                graph->edges[i] = graph->edges[j];
                graph->edges[j] = tmp;
            }
        }
    }
}

void print_graph(struct Graph *graph) {
    sort_edges(graph, print_before);
    for (int i = 0; i < graph->edge_size; i++) {
        printf("%d--%d\n", graph->edges[i].v1, graph->edges[i].v2);
    }
}

struct Graph *kruskal(struct Graph* graph) {
    sort_edges(graph, weight_before);
    struct Graph *mst = create_graph(graph->vertex_size);
    struct DisjointSet *set = createSet(graph->vertex_size);
    for (int i = 0; i < graph->edge_size; i++) {
        if (find(set, graph->edges[i].v1) != find(set, graph->edges[i].v2)) {
            unionSets(set, graph->edges[i].v1, graph->edges[i].v2);
            add_edge(mst, graph->edges[i].v1, graph->edges[i].v2, graph->edges[i].weight);
        }
    }
    destroySet(set);
    return mst;
}
