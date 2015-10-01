#include <stdio.h>

const int n[3] = {26, 48, 91};

int mdc(int a, int b){
    if(b ==0 ){
        return a;
    }
    return(mdc(b, a % b));
}


int main(){
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
