#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void limpa_linha();
int main(int argc, char** argv){
	FILE *arquivo1;
    FILE *arquivo2;
    
    char texto1 [300], texto2 [300];
    int k;
    printf ("Digite o nome do arquivo 1: ");
    scanf ("%[^\n]s", texto1);
    limpa_linha();
    printf ("Digite o nome do arquivo 2: ");
    scanf ("%[^\n]s", texto2);
    limpa_linha();
    arquivo1 = fopen (texto1, "r");
    if (arquivo1==NULL) { 
        printf("Nao foi possivel abrir o arquivo 1!\n");
    }
    arquivo2 = fopen (texto2, "r");
    if (arquivo2==NULL) {
        printf("Nao foi possivel abrir o arquivo 2!\n");
    }
  	while(fgets(texto1,300,arquivo1) != NULL){
		  fread(&texto1, sizeof(texto1), 1, arquivo1);
        do{
            fread(&texto2, sizeof(texto2), 1, arquivo2);
            if(strcmp(texto1, texto2)==0){
                k=1;
            }
        }while(!feof(arquivo2) && k==0);
	  }
	  if(texto1==texto2){
		  printf("o primeiro arquivo e igual ao segundo arquivo\n");
	  }else{
		  printf("o primeiro arquivo e diferente do segundo arquivo\n");
	  }
	  fclose(arquivo1);
	  fclose(arquivo2);
	return 0;
}
void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}