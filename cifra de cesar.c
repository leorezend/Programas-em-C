#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char mensagem[100];
    int i, x;

    printf("Digite a frase:");
    
    fgets(mensagem, sizeof(mensagem), stdin);
    size_t length = strlen(mensagem);
    if (mensagem[length - 1] == '\n') {
        mensagem[length - 1] = '\0';
    }

    for (i = 0; mensagem[i] != '\0'; i++) {
        x = mensagem[i];
        if (x >= 'a' && x <= 'z') {
            x = x + 3;
            if (x > 'z') {
                x = x - 'z' + 'a' - 1;
            }
        } else if (x >= 'A' && x <= 'Z') {
            x = x + 3;
            if (x > 'Z') {
                x = x - 'Z' + 'A' - 1;
            }
        }
        mensagem[i] = x;
    }

    printf("Mensagem incriptada: %s\n", mensagem);

    return 0;
}