#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ch15 [16];

typedef struct {
	ch15 nom;
	ch15 prenom;
} Personne;

Personne* creerPersonne(char* nom,char* prenom);
char* ecrirePersonne(void* value);
int comparerPersonne (void* value1,void* value2);


