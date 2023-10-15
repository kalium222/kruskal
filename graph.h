#ifndef GRAPH_H
#define GRAPH_H

struct edge {
    int v1;
    int v2;
    int weight;
};

// function for compare two edges
typedef int (*compare_func)(struct edge *, struct edge *);

/**
 * @brief follow the rule of the output in the .md file
 * 
 * @param e1 
 * @param e2 
 * @return int True if e1 should be printed before e2
 */
int print_before(struct edge *e1, struct edge *e2);
/**
 * @brief compare by weight
 * 
 * @param e1 
 * @param e2 
 * @return int True if e1's weight is smaller than e2's
 */
int weight_before(struct edge *e1, struct edge *e2);

struct Graph {
    struct edge *edges;
    int edge_size;
    int vertex_size;
};

/**
 * @brief create a graph
 * 
 * @param vertex_size
 * @return struct Graph* 
 */
struct Graph *create_graph(int vertex_size);
/**
 * @brief free a graph
 * 
 * @param graph 
 */
void free_graph(struct Graph *graph);
/**
 * @brief add a edge to graph
 * 
 * @param graph 
 * @param from 
 * @param to 
 * @param weight 
 */
void add_edge(struct Graph *graph, int v1, int v2, int weight);
/**
 * @brief sort edges in a graph by compare function
 * 
 * @param graph 
 * @param compare 
 */
void sort_edges(struct Graph *graph, compare_func compare);
/**
 * @brief print a graph
 * 
 * @param graph 
 */
void print_graph(struct Graph *graph);
/**
 * @brief Kruskal's algorithm
 * 
 * @param graph 
 * @return struct Graph* a minimum spanning tree
 */
struct Graph *kruskal(struct Graph *graph);
/**
 * @brief Prim's algorithm
 * 
 * @param graph 
 * @return struct Graph* a minimum spanning tree
 */
struct Graph *prim(struct Graph *graph);

#endif // GRAPH_H