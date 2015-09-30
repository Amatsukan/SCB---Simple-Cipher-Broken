#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define BLOCKSIZE 8
#define undefined 'a'


int pi[BLOCKSIZE]           = {4,1,6,2,7,3,8,5};
int inverse_pi[BLOCKSIZE]   = {2,4,6,1,8,3,5,7};

enum operation{ENCRYPT, DECRYPT};

int permute(int entry){
    return pi[entry % BLOCKSIZE]-1;
}

int permute_inverse(int entry){
    return inverse_pi[entry % BLOCKSIZE]-1;
}

char * makeBlock(char block[BLOCKSIZE], operation o){
    char *aux = (char*) calloc(BLOCKSIZE,sizeof(char));
    strcpy(aux, block);
    char * pt = (char*) calloc(BLOCKSIZE+1,sizeof(char));
    int i;
    for (i = 0; i < BLOCKSIZE; ++i)
    {
        switch(o){
            case 0    :   aux[i] = block[permute(i)];
            break;
            case 1    :   aux[i] = block[permute_inverse(i)];
        }
    }
    return aux;
}

const char *verifyAndCorrect(const char *text){
    int size = strlen(text);
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
    for (block = 0; block < (strlen(text))/BLOCKSIZE; ++block)
    {
        for (index = 0; index < BLOCKSIZE; ++index)
        {
            blocks[block][index] = text[textCounter++];
        }
    }
}

char *make(const char *text, operation o){
    int nblocks = (strlen(text))/BLOCKSIZE;
    char blocks[nblocks][BLOCKSIZE];

    const char *correctedText;

    switch(o){
            case 0    :   correctedText = verifyAndCorrect(text);
            break;
            case 1    :   correctedText = text;
    }

    char *finalText = (char*)calloc(strlen(correctedText), sizeof(char));

    setBlocks(correctedText, blocks);

    int i, block, textCounter=0;
    for (block = 0; block < nblocks; ++block)
    {
        char * funcedBlock = makeBlock(blocks[block], o);
        for (i = 0; i < BLOCKSIZE; ++i)
        {
            finalText[textCounter++] = funcedBlock[i];
        }
    }

    finalText[strlen(correctedText)] = '\0';
    return finalText;
}


int main(){
    const char * a = "pooesimplesmenteessencialparacco";
    const char * b = "epiomopsmlnetseeeecsisanrlcpcaoa";
    char *enc = make(b, DECRYPT);
    printf("%s\n", enc);
    return 0;
}
