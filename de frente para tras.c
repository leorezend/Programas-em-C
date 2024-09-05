#include <stdio.h>
#include <string.h>
#include<stdlib.h> 
int main(int argc, char** argv){
	char palavra[50], auxiliar[50];
	int i,j;
    printf("Digite a frase que pretendes ser invertida: ");
	gets(palavra);
	j=strlen(palavra)-1;
	for(i=0;palavra[i]!='\0';i++){        
       auxiliar[j]=palavra[i];
       j--;     
	}
	auxiliar[i]='\0'; 
	strcpy(palavra,auxiliar); 
	 printf("\nA frase inversa e:\n%s\n\n",palavra);
	return 0;
}
