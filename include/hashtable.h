#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    char *key;
    void *value;
    struct Entry *next;
} Entry;

typedef struct HashTable{
    Entry **buckets;
    size_t size;
} HashTable;

HashTable create_hashtable(size_t ini_size);

void ini_hashtable(HashTable *ht, size_t ini_size);

unsigned int hash(const char *key, size_t table_size);

void insert(HashTable *ht, char *key, void *value, void (*free_fn)(void*));

void delete(HashTable *ht, char *key, void (*free_fn)(void*));

void *get(HashTable *ht, const char *key);

void free_table(HashTable *ht, void (*free_fn)(void*));

#endif