#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define BLOCKSIZE 8
#define undefined 'a'


int pi[BLOCKSIZE]           = {4,1,6,2,7,3,8,5};
int inverse_pi[BLOCKSIZE]   = {2,4,6,1,8,3,5,7};

int permute(int entry){
    return pi[entry % BLOCKSIZE]-1;
}

int permute_inverse(int entry){
    return inverse_pi[entry % BLOCKSIZE]-1;
}

void encriptBlock(char block[BLOCKSIZE]){
    char *aux = (char*) calloc(BLOCKSIZE,sizeof(char));
    strcpy(aux, block);

    int i;
    for (i = 0; i < BLOCKSIZE; ++i)
    {
        aux[i] = block[permute(i)];
    }

    strcpy(aux,block);
}

const char *verifyAndCorrect(const char *text){
    int size = strlen(text)-1;
    char * ret;
    if(size%BLOCKSIZE != 0){
        int i, diff = (BLOCKSIZE - (size%BLOCKSIZE));
        ret = (char*)calloc(size + diff,sizeof(char));
        ret[size + diff] = '\0';
        for (i = 0; i < size; ++i)
        {
             ret[i] = text[i];
        }
        ret[i++] = undefined;
        for (; i <(size+diff) ; ++i)
        {
            ret[i] = undefined;
        }
    }else{
        ret = (char*)calloc(size ,sizeof(char));
        strcpy(ret, text);
    }

    return ret;
}

void setBlocks(const char *text, char blocks[][BLOCKSIZE]){
    int block, index, textCounter = 0;
    for (block = 0; block < (strlen(text)-1)/BLOCKSIZE; ++block)
    {
        for (index = 0; index < BLOCKSIZE; ++index)
        {
            blocks[block][index] = text[textCounter++];
        }
    }
}

char *encript(const char *text){
    int nblocks = (strlen(text)-1)/BLOCKSIZE;
    char blocks[nblocks][BLOCKSIZE];

    const char *correctedText = verifyAndCorrect(text);
    char *finalText = (char*)calloc(strlen(correctedText), sizeof(char));

    setBlocks(correctedText, blocks);

    int i;
    for (i = 0; i < nblocks; ++i)
    {
        encriptBlock(blocks[i]);
        printf("%s\n",blocks[i]);
    }

    int block;
    for (block = 0; block < nblocks; ++block)
    {
        for (i = 0; i < strlen(correctedText)-1; ++i)
        {
            finalText[i] = blocks[block][i%8];
        }
    }
    finalText[strlen(correctedText)] = '\0';
    return finalText;
}


int main(){
    const char * a = "pooesimplismenteessencialparaocco";
    printf("%s\n", encript(a));
    return 0;
}
