#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "linkedlist.h"

  Tree* createTreeGene(){
        Noeud* racine = createNoeud("Samir",createNoeud("Kamal",
                                    createNoeud("Yassine",NULL,createNoeud("Hind",NULL,
                                                        creteFeuille("Yasmine"))),createNoeud("Sarah",
                                                                creteFeuille("Karim"),NULL)
                                                ),NULL);
                                return createTree(racine,comparer,display);
    }

    int menu(){
printf("\t___________________________________________________________________\n\n");
printf("\n\n\t\t\t           GESTION D'UNE ARBRE \t\n\n\n");
printf("\t___________________________________________________________________\n\n\n");
printf("\t0 - Fin\n");
printf("\t1 - Trouver Noeud\n");
printf("\t2 - EnLargeur\n");
printf("\t3 - Tailee\n");
printf("\t4 - Nombre de Feuilles\n");
printf("\t5 - Lister Feuille\n");
printf("\t6 - Hauteur\n");
printf("\t7 - egalité Arbre\n");
printf("\n");
printf("Votre choix : ");
int choice;
scanf("%d",&choice);
printf("\n");
return choice;

}

void main()
{
     Noeud* racine = createNoeud("Samir",createNoeud("Kamal",
                                    createNoeud("Yassine",NULL,createNoeud("Hind",NULL,
                                                        creteFeuille("Yasmine"))),createNoeud("Sarah",
                                                                creteFeuille("Karim"),NULL)
                                                ),NULL);

    Noeud* racine2 = createNoeud("Maroua",createNoeud("Meryem",
                                    createNoeud("Yassine",NULL,createNoeud("Ayoub",NULL,
                                                        creteFeuille("la7ya"))),createNoeud("Sarah",
                                                                creteFeuille("Karim"),NULL)
                                                ),NULL);

  Tree*  a = createTreeGene();

  bool fini = false;
	while(!fini){
		switch(menu()){
			case 0 :
				fini = true;
				break;
			case 1 : {
			     char name[20];
			    printf("Entrez la valeur que vous cherchez : ");
			    scanf("%s",&name);

            Noeud* cherche = chercherNoeud(racine,name,comparer);
            if(cherche == NULL) {printf("%s n'existe pas\n",name);
            break;}
            printf("Element trouve\n");



			} break;
			case 2: {
			    printf("Elements of Tree are : ");
			    BFS(racine,display);
			} break;
			case 3:{
			    int taille = Taille(racine);
                printf("Size of your tree is :  %d\n",taille);
			} break;
			case 4 : {
                int nbrFeu = Feuillenbr(racine);
                printf("Nombre de Feuille est :  %d\n",nbrFeu);
			} break;

			case 5:{

                printf("Feuille d'arbre sont : ");
			    Liste* li = createListe(0,comparer,display);
                insertLast(li,racine);
                while(!ListeVide(li)){
                    Noeud* extrait = (Noeud*) DeleteFirst(li);
                    if(estFeuille(extrait)) printf("%s\t",display(extrait->value));
                    if(extrait->left != NULL) insertLast(li,extrait->left);
                    if(extrait->right != NULL) insertLast(li,extrait->right);
                }
                printf("\n");

			} break;

			case 6:{
                int haut = Hauteur(racine);
                printf("hauteur d\'arbre est  :  %d\n",haut);
			} break;
			case 7:{
                bool a = comparerTree(racine,racine2,comparer);
               a ? printf("Arbres égaux\n") : printf("Arbres sont pas égaux\n");
			} break;



		}
	}


}
