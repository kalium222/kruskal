#include <stdio.h>
#include <stdlib.h>

struct DisjointSet {
    int *parent;
    int *rank;
    int size;
};

struct DisjointSet* createSet(int size) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    if (!set) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    set->size = size;
    set->parent = (int*)malloc((unsigned long)size * sizeof(int));
    set->rank = (int*)malloc((unsigned long)size * sizeof(int));

    if (!set->parent || !set->rank) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
}

int find(struct DisjointSet* set, int element) {
    if (element != set->parent[element]) {
        set->parent[element] = find(set, set->parent[element]);
    }
    return set->parent[element];
}

void unionSets(struct DisjointSet* set, int x, int y) {
    int rootX = find(set, x);
    int rootY = find(set, y);

    if (rootX != rootY) {
        if (set->rank[rootX] < set->rank[rootY]) {
            set->parent[rootX] = rootY;
        } else if (set->rank[rootX] > set->rank[rootY]) {
            set->parent[rootY] = rootX;
        } else {
            set->parent[rootY] = rootX;
            set->rank[rootX]++;
        }
    }
}

int areConnected(struct DisjointSet* set, int x, int y) {
    return find(set, x) == find(set, y);
}

void destroySet(struct DisjointSet* set) {
    free(set->parent);
    free(set->rank);
    free(set);
}
