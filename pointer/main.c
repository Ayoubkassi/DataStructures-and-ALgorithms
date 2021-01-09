#include <stdio.h>
#include <stdlib.h>

int main()
{

    int age;
    int *ptr;
    ptr=&age;

    age =18;
    printf("la valeur de age est : %d\n",age);
    printf("l'adresse memoire de age est :%p",&age);

    printf("\n\n---------------------------------\n");

     printf("la valeur de age est : %d\n",*ptr);
    printf("l'adresse memoire de age est :%p",ptr);
    return 0;
}
