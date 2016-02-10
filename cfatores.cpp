#include <stdio.h>
#include <cmath>
int fatora(int n){
	int cont = 0;
	if(n%2 == 0)
		cont ++;
	while(n%2 == 0){
		n = n/2;
	}
	int i=3;
	int limite = sqrt(n);
	while(i<=limite){
		int aux = 0;
		while(n % i == 0){
			aux++;
			n = n/i;
		}
		if(aux>0)
			cont++;
		i+=2;
	}
	if(n>1)
		cont++;
	return cont;

}
int main(int argc, char const *argv[]){
	int n;
	while(true){
		scanf("%d",&n);
		if(n == 0)
			break;
		printf("%d : %d\n",n,fatora(n));
	}
	return 0;
}

