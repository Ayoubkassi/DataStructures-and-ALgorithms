#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personne.h"

Personne* creerPersonne (char* nom,char* prenom){
	Personne* p = (Personne*) malloc(sizeof(Personne));
	strcpy (p->nom,nom);
	strcpy (p->prenom,prenom);
	return p;
}

char* ecrirePersonne (void* value){
	Personne* p = (Personne*) value;
	char* output = (char*) malloc(sizeof(Personne));

	snprintf(output, sizeof(Personne),"%s %s\n",p->nom,p->prenom);
	return output;
}

int comparerPersonne(void* value1,void* value2){
	Personne* p1= (Personne*) value1;
	Personne* p2= (Personne*) value2;
	return strcmp(p1->nom,p2->nom);
}


