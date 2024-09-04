#include <stdio.h>


int main(int argc, char** argv){
    int f(int x);
	int n,i;
	printf("coloque um numero:");
	scanf("%d",&n);
	int vet[n];
	for(i=0;i<n;i++){
		vet[i]=f(i);
	}
	for(i=0;i<n;i++){
		printf("%d,",vet[i]);
	}
	
	return 0;
}
int f(int x){
	if(x==0){
		return 3;
	}else{	
		return 2*f(x-1);
	}
}