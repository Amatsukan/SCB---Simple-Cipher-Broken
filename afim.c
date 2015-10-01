#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "inversiveis.c"

#define a 5
#define b 7
#define m 26


int inverse_a = inverseof(a,m);


int charToInt(char c){
    return c - 97;
}

char intToChar(int i){
    return i + 97;
}

char * encript(const char * text){
    char * aux = (char *) calloc(strlen(text), sizeof(char));
    strcpy(aux, text);
    int i;
    for (i = 0; i < strlen(aux); ++i)
    {
        int value = mod((a * charToInt(text[i]) + b) , m);
        aux[i] = intToChar(value);
    }
    return aux;
}

char * decript(const char * text){
    char * aux = (char *) calloc(strlen(text), sizeof(char));
    strcpy(aux, text);
    inverse_a =  inverseof(a,m);
    int i;
    for (i = 0; i < strlen(aux); ++i)
    {   int sub = mod((charToInt(text[i]) - b),m);
        int value = mod((sub * inverse_a), m);
        aux[i] = intToChar(value);
    }
    return aux;
}


int main(int argc, char const *argv[])
{   const char * c= "qznhobxzd";
    const char * d= "howareyou";
    // printf("%s\n", decript(c));
    // printf("%s\n", encript(d));
    printf("%d\n", inverseof(a,m));
    return 0;
}
