

#include<stdio.h>
#include<stdlib.h>
int main()
{
 int x,i;
   printf("Entrez la taille du tableau : ");
   scanf("%d",&x);

   int *tableaudynamique = malloc(x * sizeof(int));

   for(int i=0;i<x;i++){
   	printf("Entrez le nombre %d : ",i+1);
   	scanf("%d",&tableaudynamique[i]);
   			}
   printf("\n\nvotre tableau est : [ ");
   for(int i=0;i<x;i++){
   	printf("%d  ",tableaudynamique[i]);
   			}
   printf("]");
   free(tableaudynamique);

      return 0;
}
