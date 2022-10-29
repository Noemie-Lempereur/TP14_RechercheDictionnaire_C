


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef TP14_2_RECHERCHE_H
#define TP14_2_RECHERCHE_H

#define MAX_CHAR 26

struct NodeTrie{
    char value;
    bool isEnd;
    struct NodeTrie* childs[MAX_CHAR];
};

void displayDict(char* nameFile);
struct NodeTrie* create(char* nameFile);
void prediction(struct NodeTrie* tree);
void search(struct NodeTrie* tree, char string[50], int indice);

#endif //TP14_2_RECHERCHE_H
