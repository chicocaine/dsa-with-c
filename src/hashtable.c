#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct HashTable{
    Entry **buckets;
    size_t size;
} HashTable;

HashTable create_hashtable(size_t ini_size) {
    return (HashTable) {
        .buckets = calloc(ini_size, sizeof(Entry*)),
        .size = ini_size
    };
}

void ini_hashtable(HashTable *ht, size_t ini_size) {
    if (!ht) return;
    ht->buckets = calloc(ini_size, sizeof(Entry*));
    ht->size = ini_size;
}

unsigned int hash(const char *key, size_t table_size) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return (unsigned int)(hash % table_size);
}

void insert(HashTable *ht, char *key, int value) {
    unsigned int index = hash(key, ht->size);
    Entry *head = ht->buckets[index];

    for (Entry *e = head; e != NULL; e = e->next) {
        if (strcmp(key, e->key) == 0) {
            e->value = value;
            return;
        }
    }

    Entry *new_entry = malloc(sizeof(Entry));
    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = head;
    ht->buckets[index] = new_entry;
}

int *get(HashTable *ht, const char *key) {
    unsigned int index = hash(key, ht->size);
    for (Entry *e = ht->buckets[index]; e != NULL; e = e->next) {
        if (strcmp(key, e->key) == 0) return &e->value;
    }
    return NULL;
}

void free_table(HashTable *ht) {
    for (size_t i = 0; i < ht->size; i++) {
        Entry *e = ht->buckets[i];
        while (e) {
            Entry *tmp = e;
            e = e->next;
            free(tmp->key);
            free(tmp);
        }
    }
}