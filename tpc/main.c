#include <stdio.h>
#include <stdlib.h>
#include "personne.h"
#include "linkedlist.h"

int menu(){
printf("\t___________________________________________________________________\n\n");
printf("\n\n\t\t\tGESTION D'UNE LISTE DE PERSONNE\t\n\n\n");
printf("\t___________________________________________________________________\n\n\n");
printf("\t0 - Fin\n");
printf("\t1 - Insertion en téte de liste\n");
printf("\t2 - Insertion en fin de liste\n");
printf("\t3 - Retrait en téte de liste\n");
printf("\t4 - Retrait en fin de liste\n");
printf("\t5 - Retrait d'un élement à partir de son nom\n");
printf("\t6 - Parcours de la liste\n");
printf("\t7 - Recherche d'un élément à partie de son nom\n");
printf("\t8 - Destruction de la liste\n");
printf("\n");
printf("Votre choix : ");
int choice;
scanf("%d",&choice);
printf("\n");
return choice;

}

void main()
{

    Liste* lp = createListe(0,comparerPersonne,ecrirePersonne);
    bool fini = false;
    while(!fini){
    	switch(menu()){
    		case 0:
    			fini = true;
    			break;
    		case 1: {
    			printf("Nom de la personne à creer : ");
    			ch15 nom;
    			scanf("%s",nom);
    			printf("Prénom de la personne à creer : ");
    			ch15 prenom;
    			scanf("%s",prenom);
    			Personne* nouveau = creerPersonne(nom,prenom);

    			InsertFirst(lp,nouveau);
    		}
    		        break;

    		case 2 : {
    				printf("Nom de la personne à creer : ");
    			ch15 nom;
    			scanf("%s",nom);
    			printf("Prénom de la personne à creer : ");
    			ch15 prenom;
    			scanf("%s",prenom);
    			Personne* nouveau = creerPersonne(nom,prenom);

    			insertLast(lp,nouveau);
    		}
    			break;

    		case 3 : {
    			Personne*extrait = (Personne*) DeleteFirst(lp);
    			if(extrait != NULL){
    				printf("Element %s %s extrait en tete de la liste ",extrait->nom,extrait->prenom);
    			}
    			else{
    				printf("Liste vide");
    			}
    		} break;

    		case 4 : {
    					Personne*extrait = (Personne*) deleteLast(lp);
    			if(extrait != NULL){
    				printf("Element %s %s extrait en tete de la liste ",extrait->nom,extrait->prenom);
    			}
    			else{
    				printf("Liste vide");
    			}
    		} break;

   		case 5 : {
   			printf("Nom de la personne à extraite : ");
   			ch15 nom;
   			scanf("%s",nom);
   			Personne* cherche = creerPersonne(nom,"?");
   			Personne* pp = (Personne*) Objetchercher(lp,cherche);
   			if(deletebyValue(lp,pp)){
   				printf("Element %s %s extrait de la liste",pp->nom,pp->prenom);
   			}
   		} break;

   		case 6 :
   			listerListe(lp);
   			break;

   		case 7 : {
   			printf(" Nom de la personne recherchée : ");
   			ch15 nom;
   			scanf("%s",nom);
   			Personne* cherche = creerPersonne(nom,"?");
   			Personne* pp = (Personne*) Objetchercher(lp,cherche);
   			if(pp != NULL){
   				printf("%s %s trouvée dans la liste\n",pp->nom,pp->prenom);
   			} else{
   				printf("%s inconnue dans la liste\n",nom);
	}

   		} break;

   		case 8 :
   			detruiteListe(lp);
   			break;

    	}
    }
}










