#include<stdio.h>

int main(){
    int i,j;
    int n=5;

    for(i=0; i<=32; i++){

        printf("%3d %3o %3x\n", i, i, i);
    }

    for(i=0; i<=100; i++){
        printf("%3d ", i);

        if(i % 10 == 0){
            printf("\n");
        }
    }




    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j) printf("A");
            else if(n-1-i==j) printf("B");
            else printf("*");
        }
        printf("\n");
    }


    int stars=1;
    int blanks;
    n=5;

    blanks = n-1;

    for(i=0; i<2*n-1; i++){

        for(j=0; j<blanks; j++)
            printf(" ");

        for(j=0; j<stars; j++){
            printf("*");
        }
        if(i<n-1){
            stars += 2;
            blanks--;
        }else{
            stars -= 2;
            blanks++;
        }

        printf("\n");
    }



    return 0;
}
