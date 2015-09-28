#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *BUFF = (char*) calloc(1024,(sizeof(char)));

char *text;


int freq[26];
int textSize = 0;
char ordPrioChar[26];

char portugFreq[26]  = {'a','e','o','s','r','i','n','d','m','u','t','c','l','p','v','g','h','q','b','f','z','j','x','k','y','w'};
char englishFreq[26] = {'e','t','a','o','i','n','s','h','r','d','l','c','u','m','w','f','g','y','p','b','v','k','j','x','q','z'};


int charToInt(char c){
    return c - 97;
}

char intToChar(int i){
    return i + 97;
}

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
    printf("Encoded text :\n%s\n", text);
    textSize = strlen(text);

    int i;
    for (i = 0; i < textSize; ++i){
        freq[charToInt(text[i])]++;
    }

    populate();
    bubbleSort();

    for(c = 25; c>=0; c--){
        printf("%c ~> %lf\n", ordPrioChar[c], frequence(ordPrioChar[c]));
    }
}

void broke(){
    int i;

    printf("possible map: \n");
    for (i = 0; i < 26; ++i){
        printf("%c => %c\n", ordPrioChar[i], englishFreq[charToInt(ordPrioChar[i])]);
    }
    printf("Trasnlate: \n");
    for (i = 0; i < textSize; ++i){
        printf("%c", englishFreq[charToInt(text[i])]);
    }
}

int main(){
    printf("give-me the encoded text\n");
    scanf("%s",BUFF);
    textSize = strlen(BUFF);
    text =(char *) calloc(textSize, sizeof(char));

    int i = 0;
    for (i = 0; BUFF[i] != '\0' ; ++i)
    {
        text[i] = BUFF[i];
    }
    text[++i] = '\0';

    analyze();
    broke();

    free(BUFF);
    free(text);
    return 0;
}
