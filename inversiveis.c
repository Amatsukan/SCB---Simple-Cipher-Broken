#include <stdio.h>

const int n[3] = {26, 48, 91};

int mod(int x, int y){
    if(y < 0) return -1;

    if(x < 0){
        return x+y;
    }

    return x%y;
}

int mdc(int a, int b){
    if(b ==0 ){
        return a;
    }
    return(mdc(b, a % b));
}

int inverseof(int _value, int _mod){
    int i;
    for(i = 1; i < _mod; i++){
        if(mod((_value * i),_mod) == 1){
            return i;
        }
    }
    return -1;
}


int makeTest(){
    int i, nTest;

    for(i = 0; i<3; i++){

        printf("inversiveis em n = %d\n", n[i]);

        for (nTest = 0; nTest < n[i]; ++nTest)
        {
            int result = mdc(n[i], nTest);

            if(result == 1){
                printf("%d\t", nTest);
            }

        }
        printf("\n");
    }


    return 0;
}
