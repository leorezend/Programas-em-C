#include <stdio.h>
#include <string.h>

typedef struct carro {
    char modelo[50];
    float consumoPorDistancia;
} carro;

int main(){
    carro carros[5];
    int i;
    float n;

    for(i = 0; i < 5; i++){
        printf("Digite o modelo do carro: ");
        scanf("%s", carros[i].modelo);
        printf("Digite quantos kilometros por litro o carro faz: ");
        scanf("%f", &carros[i].consumoPorDistancia);
        printf("\n");
    }

    printf("\n\nLista dos carros mais economicos:\n\n");
    for (i = 0; i < 5; i++){
        printf("%s : %.2f km/L\n", carros[i].modelo, carros[i].consumoPorDistancia);
    }

    for (i = 0; i < 5; i++){
        n = 1000 / carros[i].consumoPorDistancia; // Corrigido para usar float
        printf("\nO %s percorre 1000 quilometros com %.2f litros\n", carros[i].modelo, n);
    }

    return 0;
}
