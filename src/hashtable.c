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

void insert(HashTable *ht, char *key, void *value, void (*free_fn)(void*)) {
    unsigned int index = hash(key, ht->size);
    Entry *head = ht->buckets[index];

    for (Entry *e = head; e != NULL; e = e->next) {
        if (strcmp(key, e->key) == 0) {
            if (free_fn) free_fn(e->value);
            e->value = value;
            return;
        }
    }

    Entry *new_entry = malloc(sizeof(Entry));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = head;
    ht->buckets[index] = new_entry;
}

void delete(HashTable *ht, char *key, void (*free_fn)(void*)) {
    unsigned int index = hash(key, ht->size);
    Entry *current = ht->buckets[index];
    Entry *prev = NULL;

    while (current) {
        if (strcmp(key, current->key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                ht->buckets[index] = current->next;
            }
            if (free_fn) free_fn(current->value);
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void *get(HashTable *ht, const char *key) {
    unsigned int index = hash(key, ht->size);
    for (Entry *e = ht->buckets[index]; e != NULL; e = e->next) {
        if (strcmp(key, e->key) == 0) return e->value;
    }
    return NULL;
}

void free_table(HashTable *ht, void (*free_fn)(void*)) {
    for (size_t i = 0; i < ht->size; i++) {
        Entry *e = ht->buckets[i];
        while (e) {
            Entry *tmp = e;
            e = e->next;
            if (free_fn) free_fn(tmp->value);
            free(tmp->key);
            free(tmp);
        }
    }
    free(ht->buckets);
    ht->buckets = NULL;
    ht->size = 0;
}