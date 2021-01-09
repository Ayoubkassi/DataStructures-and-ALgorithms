#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "linkedlist.h"



int comparer(void* value1,void* value2){
	return strcmp((char*) value1,(char*) value2);
}

char* display(void* value){
	return (char*) value;
}

//initialiser

static void initialiserListe(Liste* li,int type,int (*comparer) (void*,void*),char* (*display) (void*)){
	li->premier= NULL;
	li->dernier= NULL;
	li->courant= NULL;
	li->type = type;
	li->length = 0;
	li->comparer= comparer;
	li->display = display;
}

Liste* createListe(int type,int (*comparer) (void*,void*),char* (*display) (void*)){
	Liste* li = (Liste*) malloc(sizeof(Liste));
	initialiserListe(li,type,comparer,display);
	return li;
}

bool ListeVide(Liste* li){
	return li->length == 0;
}

int nbrElement(Liste* li){
	return li->length;
}

Element* createElement(){
	Element* element = (Element*) malloc(sizeof(Element));
	return element;
}

void InsertFirst(Liste* li,void* value){
	Element* new = createElement();
	new->value=value;
	new->next=li->premier;
	li->premier=new;
	if(li->dernier == NULL) li->dernier = new;
	li->length++;
}

//ajouter apres element

void insertAfter(Liste* li,void* value,Element* before){
	if(before == NULL){
		InsertFirst(li,value);
	}
	else{
		Element* new = createElement();
		new->value=value;
		new->next=before->next;
		before->next=new;
		if(before == li->dernier) li->dernier=new;
		li->length++;
	}
}

void insertLast(Liste* li,void* value){
	insertAfter(li,value,li->dernier);
}

void OuvrirListe(Liste* li){
	li->courant= li->premier;
}

bool finListe(Liste* li){
	return li->courant == NULL;
}

Element* elementCourant(Liste* li){
	Element* ptc = li->courant;
	if(li->courant != NULL) li->courant = li->courant->next;
	return ptc;
}

void* ObjetCourant(Liste* li){
	Element* ptc = elementCourant(li);
	return  ptc == NULL ? NULL:ptc->value;
}


void listerListe(Liste* li){
	OuvrirListe(li);
	while(!finListe(li)){
	void* value = ObjetCourant(li);
		printf("%s\n",li->display(value));
	}
}

void* Objetchercher(Liste* li,void* objetchercher){
	bool found = false;
	void* value;
	OuvrirListe(li);
	while(!finListe(li) && !found){
		value = ObjetCourant(li);
		found = li->comparer(value,objetchercher) == 0;
	}
	return   found ? value: NULL;
}


void* DeleteFirst(Liste* li){
	Element* ptc = li->premier;
	if(!ListeVide(li)){
		li->premier = li->premier->next;
		if(li->premier == NULL) li->dernier = NULL;
		li->length--;
	}
	return  ptc != NULL ? ptc->value : NULL;
}

static void* DeleteAfter (Liste* li,Element* before){
	if(before == NULL){
		return DeleteFirst(li);
	}
	else{
		Element* ptc = before->next;
		if(ptc!= NULL){
			before->next= ptc->next;
			if(ptc == li->dernier) li->dernier=before;
			li->length--;
		}
		return   ptc != NULL ? ptc->value : NULL;
	}
}


void* deleteLast(Liste* li){
	void* extrait;
	if(ListeVide(li)){
		extrait = NULL;
	}
	else if(li->premier == li->dernier) extrait = DeleteFirst(li);
	else{
		Element* ptc= li->premier;
		while(ptc->next != li->dernier) ptc= ptc->next;
		extrait = DeleteAfter(li,ptc);
	}
	return extrait;
}

void detruiteListe(Liste* li){
	OuvrirListe(li);
	while(!finListe(li)){
	 Element* ptc = elementCourant(li);
	 free(ptc);
	}
	initialiserListe(li,li->type,li->comparer,li->display);
}

bool deletebyValue(Liste* li,void* value){
	Element* before = NULL;
	Element* ptc = NULL;
	bool found = false;

	OuvrirListe(li);
	while(!finListe(li)){
		before=ptc;
		ptc = elementCourant(li);
		found = (ptc->value = value)  ?  true : false;

	}
	if(!found) return false;

	void* extrait = DeleteAfter(li,before);
	return true;
}






















