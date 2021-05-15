#include <stdio.h>
#include <math.h>

void main(){
    int a[50],l[50],n=30,i,j;
    for(i=0;i<n;i++){
        a[i] = i;
    }
    for(i=2;i<sqrt(floor(n));i++){
        if(a[i]!=0){
            j = i*i;
            while(j<=n){
                a[j] = 0;
                j=j+i;
            }
        }
    }
    j=0;
    for(i=0;i<n;i++){
        if(a[i]!=0){
            l[j]=a[i];
            j++;
        }
    }
    for(i=0;i<j;i++){
        printf("%d ",l[i]);
    }
    printf("\n");
}

//gcc sieve.c -o op
//./op
//hello World
