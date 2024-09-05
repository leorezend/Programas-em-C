#include <stdio.h>
#include <stdlib.h>
int main(void){
  FILE *pont_arq;
  char texto[20]; 
  pont_arq = fopen("arquivo_arq2.txt", "a");
  if(pont_arq == NULL){
  	  printf("Erro na abertura do arquivo!");
  	  return 1;
  }
  if(texto==0){
  	  return 0;
  }else{
	printf("Escreva para gravar no arquivo: ");
	scanf("%s",texto);
	fprintf(pont_arq, "%s", texto);
  }
  fclose(pont_arq);
  printf("Dados gravados com sucesso!\n");
  
 	
	pont_arq=fopen("arquivo_arq2.txt","r");
	if(pont_arq==NULL){
		printf("nao abriu o arquivo\n");
		return 0;
	}
	char ler[100];
	while(fgets(ler,100,pont_arq) != NULL){
		printf("%s",ler);
	}
	fclose(pont_arq);
  return(0);
}