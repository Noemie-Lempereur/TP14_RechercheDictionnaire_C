#include "recherche.h"

void displayDict(char* nameFile){
    FILE* file = fopen("dict_anglais2.txt", "r");
    if(file == NULL) {
        return;
    }
    char name[50];
    while(! feof(file)){
        fgets(name,50,file);
        name[strlen(name)-1]='\0';
        printf("%s\n",name);
    }
    fclose(file);
}

struct NodeTrie* create(char* nameFile){
    char ch;
    FILE* fp;
    fp=fopen("dict_anglais2.txt","r");
    if(fp==NULL) {
        printf("Error in opening file");
        return NULL;
    }
    struct NodeTrie* tree = malloc(sizeof(struct NodeTrie));
    struct NodeTrie* tpar = tree;
    tree->isEnd=false;
    int i=0;
    while(!feof(fp)){
        ch=fgetc(fp);
        if(ch != -1 && ch != 13 && ch != 10) {
            if(tpar->childs[(ch-97)] == NULL) {
                tpar->childs[(ch-97)] = malloc(sizeof(struct NodeTrie));
            }
            if(tpar->isEnd!=true){
                tpar->isEnd=false;
            }
            tpar->childs[(ch-97)]->value = ch;
            tpar = tpar->childs[(ch-97)];
            //printf("%c", ch);
        }else {
            i=0;
            tpar->isEnd=true;
            tpar = tree;
            //printf("\n");
        }
    }
    printf(("Chargement terminé\n"));
    fclose(fp);
    return tree;
}

void prediction(struct NodeTrie* tree) {
    char c[1] = {0};
    char s[50] = {0};
    struct NodeTrie *tpar = tree;
    int i = 0;
    int a = 0;
    int k=1;
    while(((c[0] - 97 < 0 || c[0] - 97 >= 26) && c[0] != '#')||(k=1)){
        k=0;
        printf(("Entrez une lettre ou # pour passer au mot suivant\n"));
        scanf("%s", c);
        s[i] = c[0];
        if (c[0] == '#') {
            for(int j=0;j<=i;j++){
                s[j]=0;
            }
            i=0;
            continue;
        }
        tpar = tpar->childs[c[0] - 97];
        if (tpar == NULL) {
            printf("Pas de résultat");
            return;
        }
        search(tpar, s,i);
        i++;
    }
}

void search(struct NodeTrie* tree, char string[50],int indice) {
    char t[50]={0};
    for (int h=0;h<=indice;h++){
        t[h]=string[h];
    }
    if(tree->isEnd==true){
        printf("%s\n",string);
    }
    for (int j=0;j<MAX_CHAR;j++){
        if(tree->childs[j]!=NULL){
            t[indice+1]=(char)(j+97);
            search(tree->childs[j],t,indice+1);
        }
    }
}