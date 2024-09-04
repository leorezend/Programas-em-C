#include <stdio.h>
#include <string.h>
#include<stdlib.h> 
int main(int argc, char** argv){
	char palavra[50], auxiliar[50] , frase[50];
	int i,j;
    printf("Digite a frase que pretendes ser invertida: ");
	gets(palavra);
	printf("Digite a segunda frase que pretendes ser invertida: ");
	gets(frase);
	j=strlen(palavra)-1;
	for(i=0;palavra[i]!='\0';i++){        
       auxiliar[j]=palavra[i];
       j--;     
	}
	auxiliar[i]='\0'; 
	strcpy(palavra,auxiliar); 
	 printf("\nA frase inversa e:\n%s\n\n",palavra);
	int x,cont=0,y;
	for(x=0;palavra[x]!='\0';x++){
		if((palavra[x]== 'a')||(palavra[x]== 'A')){
			y=x;
			while(palavra[y]!= '\0'){
				palavra[x]='*';
				y++;	
			}
			cont++;
			if((palavra[x]== 'a')||(palavra[x]== 'A')){
				x--;
			}
		}
	}
	j=strlen(frase)-1;
	for(i=0;frase[i]!='\0';i++){        
       auxiliar[j]=frase[i];
       j--;     
	}
	auxiliar[i]='\0'; 
	strcpy(frase,auxiliar); 
	 printf("\nA segunda frase inversa e:\n%s\n\n",frase);
	for(x=0;frase[x]!='\0';x++){
		if((frase[x]== 'a')||(frase[x]== 'A')){
			y=x;
			while(frase[y]!= '\0'){
				frase[x]='*';
				y++;
				
			}
			cont++;
			if((frase[x]== 'a')||(frase[x]== 'A')){
				x--;
			}
		}
	}
	printf("\nA frase inversa com o A sensurado:\n%s\n\n",palavra);
	printf("\nA frase inversa com o A sensurado:\n%s\n\n",frase);

    return 0;
}
