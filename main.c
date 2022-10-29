#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "recherche.h"

int main() {
    struct NodeTrie* tree=create("dict_anglais2.txt");
    prediction(tree);
    return 0;
}
