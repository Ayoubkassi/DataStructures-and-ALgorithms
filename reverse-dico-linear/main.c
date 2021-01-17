#include <stdio.h>
#include <stdlib.h>

int linear(int t[],int n,int key){
    int i;
    for (i = 0; i < n; i++)
        if (t[i] == key)
            return i;
    return -1;
}

int dico(int t[],int l,int h,int k){
    int m=h+l/2;
    if(h>=l){
    if(t[m]==k) return m;
    else if(t[m]<k) {
        return dico(t,m+1,h,k);
    }
    else return dico(t,l,m-1,k);
    }
    return -1;
}

char* reverseString(char* str,int n)
{
    int l, i;
    char *begin_ptr, *end_ptr, ch;

    l = strlen(str);

    // Set the begin_pr and end_ptr
    // initially to start of string
    begin_ptr = str;
    end_ptr = str;

    // Move the end_ptr to the last character
    for (i = 0; i < l - 1; i++)
        end_ptr++;

    for (i = 0; i < l / 2; i++) {

        // swap character
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;

        // update pointers positions
        begin_ptr++;
        end_ptr--;
    }
}

int main()
{
 

      // Get the string
    char str[100] = "AyoubKassi";
    printf("Enter a string: %s\n", str);

    // Reverse the string
    reverseString(str,3);

    // Print the result
    printf("Reverse of the string: %s\n", str);


    return 0;
}
