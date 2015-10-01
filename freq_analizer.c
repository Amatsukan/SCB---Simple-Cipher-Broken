#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "afim.c"

// char *BUFF = (char*) calloc(1024,(sizeof(char)));

char *text;


int freq[26];
int textSize = 0;
char ordPrioChar[26];

char portugFreq[26]  = {'a','e','o','s','r','i','n','d','m','u','t','c','l','p','v','g','h','q','b','f','z','j','x','k','y','w'};
char englishFreq[26] = {'e','t','a','o','i','n','s','h','r','d','l','c','u','m','w','f','g','y','p','b','v','k','j','x','q','z'};

void vcoppy(int *origin, int *dest){
    int i;
    for (i = 0; i < 26; ++i)
    {
        dest[i] = origin[i];
    }
}

void bubbleSort(){
    int i, j, iAux;
    char cAux;

    int vAux[26];
    vcoppy(freq, vAux);

    for(i=26-1; i >= 1; i--) {

        for(j=0; j < i ; j++) {

            if(vAux[j]>vAux[j+1]) {

                iAux = vAux[j];
                vAux[j] = vAux[j+1];
                vAux[j+1] = iAux;
                cAux = ordPrioChar[j];
                ordPrioChar[j] = ordPrioChar[j+1];
                ordPrioChar[j+1] = cAux;
            }
        }
    }
}

void populate(){
    int i;
    for(i=0; i<26; i++){
        ordPrioChar[i] = intToChar(i);
    }
}

double frequence(char c){
    return ((double)freq[charToInt(c)])/(double)textSize;
}

void analyze(){
    char c;
    printf("Encoded text :\n%s\n\n\n", text);
    textSize = strlen(text);

    int i;
    for (i = 0; i < textSize; ++i){
        freq[charToInt(text[i])]++;
    }

    populate();
    bubbleSort();

    for(c = 25; c>=0; c--){
        printf("%c => %lf\n", ordPrioChar[c], frequence(ordPrioChar[c]));
    }
}

void map(){
    int i;

    printf("possible map: \n");
    for (i = 0; i < 26; ++i){
        printf("%c => %c\n", ordPrioChar[i], englishFreq[charToInt(ordPrioChar[i])]);
    }
}

void broke(){

    m = 26;
    printf("Possible keys:\n");
    printf("\t b = any element of Zm\n");
    int * as = makeTest(m,1);
    printf("%d posibity of keys\n", euler_phi(m) * m);
    int i, j;
    for(i = 0; i<euler_phi(m); i++){
        a=as[i];
        for (j = 0; j < m; ++j)
        {
            b=j;
            printf("%d %d\n",a, b );

            //printf("%s\n", decript(text));

        }
    }


 }

int main(){
    // printf("give-me the encoded text\n");
    // scanf("%s",BUFF);
    const char * BUFF = "emglosudcgdncuswysfhnsfcykdpumlwgyicoxysipjckkqerejebcppcjcrkieacuzbkrvpkrbcibqcarbjcvfcupkriofkpacuzqepbkrxpeiieabdkpbcpfcdccafieabdkpbcpfeqpkazbkrhaibkapcciburccdkdccjcidfuixpafferbiczdfkabicbbenefcupjcvkabpcydccdpkbcocperkivkscpicbrkijpkabi";

    textSize = strlen(BUFF);
    text =(char *) calloc(textSize, sizeof(char));

    strcpy(text, BUFF);

    analyze();
    map();

    // free(BUFF);
    // free(text);
    broke();
    return 0;
}
