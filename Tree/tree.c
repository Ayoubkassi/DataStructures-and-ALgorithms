
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "linkedlist.h"



Noeud* createNoeud(void* value,Noeud* left,Noeud* right){
	Noeud* new = (Noeud*) malloc(sizeof(Noeud));
	new->value=value;
	new->right=right;
	new->left=left;
	return new;
}

Noeud* creteFeuille(void* value){
	return createNoeud(value,NULL,NULL);
}

void initialTree(Tree* arbre,Noeud* root,int (*comparer) (void*,void*),char* (*display) (void*)){
	arbre->root=root;
	arbre->comparer=comparer;
	arbre->display=display;
}

Tree* createTree(Noeud* racine,int (*comparer) (void*,void*),char* (*display)(void*,void*)){
	Tree* arbre= (Tree*) malloc(sizeof(Tree));
	initialTree(arbre,racine,comparer,display);
	return arbre;
}

//chercher Noeud

Noeud* chercherNoeud(Noeud* racine,void* valeur,int (*comparer) (void*,void*)){
	Noeud* new;
	if(racine == NULL){
		new = NULL;
	}
	else if(comparer(racine->value,valeur) == 0){
		new = racine;
	}
	else{
		new = chercherNoeud(racine->left,valeur,comparer);
		if(new == NULL) new = chercherNoeud(racine->right,valeur,comparer);
	}
	return new;
}

//BFS breadth first search

void BFS(Noeud* racine,char* (*display) (void*)){
	Liste* li = createListe(0,comparer,display);
	insertLast(li,racine);
	while(!ListeVide(li)){
		Noeud* extrait = (Noeud*) DeleteFirst(li);
		printf("%s\t",display(extrait->value));
		if(extrait->left != NULL) insertLast(li,extrait->left);
		if(extrait->right != NULL) insertLast(li,extrait->right);
	}
	printf("\n");
}

//est Feuille

bool estFeuille(Noeud* racine){
	return (racine->left == NULL) && (racine->right == NULL);
}

int Taille(Noeud* racine){
	if(racine == NULL){
		return 0;
	}
	else {
		return 1 + Taille(racine->left) + Taille(racine->right);
	}
}

//nombre de feuille

int Feuillenbr(Noeud* racine){
	if(racine == NULL){
		return 0;
	}
	else if(estFeuille(racine)){
		return 1;
	}
	else {
		return Feuillenbr(racine->right) + Feuillenbr(racine->left);
	}
}

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

// Hauteur
//HSY HSY

int Hauteur(Noeud* racine){
	if(racine == NULL){
		return 0;
	}
	else {
		return 1+ max(Hauteur(racine->left),Hauteur(racine->right));
	}
}

//comparerTree


bool comparerTree(Noeud* racine1,Noeud* racine2,int (*comparer) (void*,void*)){
	bool result = false;
	if((racine1 == NULL) && (racine2 == NULL)){
		result = true;
	}
	else if((racine1 != NULL) && (racine2 != NULL)){
		if(comparer(racine1->value,racine2->value) == 0){
			if(comparerTree(racine1->left,racine2->left,comparer)){
				result = comparerTree(racine1->right,racine2->right,comparer);
			}
		}
	}
	return result;
}







