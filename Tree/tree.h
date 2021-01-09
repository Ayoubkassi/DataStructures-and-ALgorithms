#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct noeud{
	void* value;
	struct noeud* left;
	struct noeud*right;
}Noeud;

typedef struct{
	Noeud* root;
	int (*comparer) (void*,void*);
	char* (*display) (void*,void*);
}Tree;

int comparer(void* value1,void* value2);
char* display(void* value);
Noeud* createNoeud(void* value,Noeud* left,Noeud* right);
Noeud* creteFeuille(void* value);
void initialTree(Tree* arbre,Noeud* root,int (*comparer) (void*,void*),char* (*display) (void*));
Tree* createTree(Noeud* racine,int (*comparer) (void*,void*),char* (*display)(void*,void*));
Noeud* chercherNoeud(Noeud* racine,void* valeur,int (*comparer) (void*,void*));
void BFS(Noeud* racine,char* (*display) (void*));
bool estFeuille(Noeud* racine);
int Taille(Noeud* racine);
int Feuillenbr(Noeud* racine);
int Hauteur(Noeud* racine);
bool comparerTree(Noeud* racine1,Noeud* racine2,int (*comparer) (void*,void*));

