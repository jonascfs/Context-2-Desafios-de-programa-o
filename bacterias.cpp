//
// Created by jc on 14/01/16.
//
#include <stdio.h>
#include <cmath>
int main(){
    int c,d,cont,maiorI;
    double maior = 0.0;
    scanf("%d",&cont);
    for (int i = 0; i < cont; ++i) {
        scanf("%d %d",&c,&d);
        if(d*log(c) > maior){
            maior = d*log(c);
            maiorI = i;
        }
    }
    printf("%d",maiorI);
}