#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#define DEFAULT_TOTAL_SIZE 100

struct DisjointSet {
    int *parent;
    int *rank;
    int size;
};

/**
 * @brief Create a Set object
 * 
 * @param size 
 * @return struct DisjointSet* 
 */
struct DisjointSet* createSet(int size);
/**
 * @brief find the root of the element
 * 
 * @param set 
 * @param element 
 * @return int 
 */
int find(struct DisjointSet *set, int element);
/**
 * @brief merge the set which contains x and the set which contains y
 * 
 * @param set 
 * @param x 
 * @param y 
 */
void unionSets(struct DisjointSet *set, int x, int y);
/**
 * @brief check if x and y are connected
 * 
 * @param set 
 * @param x 
 * @param y 
 * @return int 
 */
int areConnected(struct DisjointSet *set, int x, int y);
/**
 * @brief destroy the set
 * 
 * @param set 
 */
void destroySet(struct DisjointSet *set);

#endif // DISJOINT_SET_H
