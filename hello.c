#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node *buckets[TABLE_SIZE];
} HashTable;

Node *create_node(char *key, char *value){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
};

unsigned int hash(char *key) {
    unsigned int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash = key[i] + (hash << 6) + (hash << 16) - hash;
    }
    return hash % TABLE_SIZE;
}

HashTable *create_table(){
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void insert(HashTable *table, const char *key, const char *value){
    unsigned int index = hash(key);
    Node *node = create_node(key, value);

    if (table->buckets[index] == NULL) {
        table->buckets[index] = node;
    } else {
        Node *current = table->buckets[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
};

char *search (HashTable *table, const char *key){
    unsigned int index = hash(key);
    Node *current = table->buckets[index];
    
    while(current){
        if (strcmp(current->key == key) == 0){
            return current->value;
        }
        current = current->next;
    }
    return NULL;
};

void delete(HashTable *table, const char key){
    unsigned int index = hash(key);
    Node *current = table->buckets[index];

    while (current != NULL && strcmp(current->key, key) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found\n");
        return;
    }

    if (prev == NULL) {
        table->buckets[index] = current->next;
    } else {
        prev->next = current->next;
    }

    free(current->key);
    free(current->value);
    free(current);

};

