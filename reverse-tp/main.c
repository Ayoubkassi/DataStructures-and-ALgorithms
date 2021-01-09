#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multichar(char* s,int n){
    int i,j,k;
    int d=strlen(s);

    char* temp=(char*)malloc(d);
    char* out=(char*)malloc(d*n);
    for(k=0;k<d;k++){
        temp[k]=s[d-1-k];
    }
    for(i=0;i<d;i++){
        for(j=0;j<n;j++){
            out[j+i*n]=temp[i];
        }
    }
    return out;
}


int main()
{
    char* d="ENSA";
    d=multichar(d,3);
    printf("\n\t\t\t%s\n\n",d);
    return 0;
}
