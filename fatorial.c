#include <stdio.h>
int f(int x);
int main(int argc, char** argv){
	int n,i;
	printf("coloque um numero:");
	scanf("%d",&n);
	i=f(n);
	printf("%d",i);
	return 0;
}
int f(int x){
	if(x==1){
		return 1;
	}else{
		return x*f(x-1);
	}
}