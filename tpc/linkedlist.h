#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



typedef struct element{
	void* value;
	struct element* next;
} Element;

typedef struct{
	Element* premier;
	Element* dernier;
	Element* courant;
	int type;
	int length;
	int (*comparer) (void*,void*);
	char* (*display) (void*);
} Liste;


int comparer(void* value1,void* value2);
char* display(void* value);
static void initialiserListe(Liste* li,int type,int (*comparer) (void*,void*),char* (*display) (void*));
Liste* createListe(int type,int (*comparer) (void*,void*),char* (*display) (void*));
bool ListeVide(Liste* li);
int nbrElement(Liste* li);
Element* createElement();
void InsertFirst(Liste* li,void* value);
void insertAfter(Liste* li,void* value,Element* before);
void insertLast(Liste* li,void* value);
void OuvrirListe(Liste* li);
bool finListe(Liste* li);
Element* elementCourant(Liste* li);
void* ObjetCourant(Liste* li);
void listerListe(Liste* li);
void* Objetchercher(Liste* li,void* objetchercher);
void* DeleteFirst(Liste* li);
static void* DeleteAfter (Liste* li,Element* before);
void* deleteLast(Liste* li);
void detruiteListe(Liste* li);
bool deletebyValue(Liste* li,void* value);
