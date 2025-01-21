#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100  // Size of the hash table

// Define a simple hash set structure
typedef struct HashSet {
    int *table;    // Array to hold the elements
    int *flags;    // Array to indicate if a position is occupied or not (used for probing)
} HashSet;

// Hash function: simple modulus hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Initialize the hash set
void initSet(HashSet *set) {
    set->table = (int*)malloc(TABLE_SIZE * sizeof(int));
    set->flags = (int*)malloc(TABLE_SIZE * sizeof(int));

    for (int i = 0; i < TABLE_SIZE; i++) {
        set->flags[i] = 0;  // 0 means unoccupied
    }
}

// Insert an element into the set
void insert(HashSet *set, int key) {
    int index = hash(key);

    // Linear probing: If the slot is occupied, check the next slot
    while (set->flags[index] == 1) {
        if (set->table[index] == key) {
            return;  // Key already exists in the set
        }
        index = (index + 1) % TABLE_SIZE;
    }

    // Insert the key into the set
    set->table[index] = key;
    set->flags[index] = 1;  // Mark the slot as occupied
}

// Check if an element exists in the set
int contains(HashSet *set, int key) {
    int index = hash(key);

    // Linear probing: search for the key
    while (set->flags[index] != 0) {
        if (set->flags[index] == 1 && set->table[index] == key) {
            return 1;  // Found the key
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return 0;  // Key not found
}

// Print the elements in the hash set
void printSet(HashSet *set) {
    printf("HashSet: { ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (set->flags[i] == 1) {
            printf("%d ", set->table[i]);
        }
    }
    printf("}\n");
}

// Free the memory used by the hash set
void freeSet(HashSet *set) {
    free(set->table);
    free(set->flags);
}

int main() {
    // Create and initialize the hash set
    HashSet set;
    initSet(&set);

    // Example: Inserting elements into the hash set
    insert(&set, 10);
    insert(&set, 20);
    insert(&set, 30);
    insert(&set, 10);  // Duplicate, should not be added
    insert(&set, 40);

    // Print the hash set
    printSet(&set);

    // Check if certain elements exist in the hash set
    printf("Contains 20: %d\n", contains(&set, 20));  // Should return 1 (true)
    printf("Contains 50: %d\n", contains(&set, 50));  // Should return 0 (false)

    // Free the allocated memory
    freeSet(&set);

    return 0;
}
