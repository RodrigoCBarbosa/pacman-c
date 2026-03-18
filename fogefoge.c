#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

struct mapa m;

void alocamapa() {
    m.matriz = malloc(sizeof(char*) *m.linhas);
    for (int i = 0; i <     malinhas; i++) {
        m.matriz[i] = malloc(sizeof(char) * (colunas + 1));
    }
}

void lemapa() {
    FILE* f = fopen("mapa.txt", "r");
    if (f == NULL) {
        printf("erro");
        exit(1);
    }
    fscanf(f, "%d %d", &linhas, &colunas);
    printf("linhas %d, colunas %d\n", linhas, colunas);

    alocamapa();

    for (int i = 0; i < linhas; i++) {
        fscanf(f, "%s", mapa[i]);
    }
    fclose(f);
}

void imprimemapa() {
    for (int i = 0; i < linhas; i++) {
        printf("%s\n", mapa[i]);
    }
}

void liberamapa() {
    for (int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);
}

int acabou() {
    return 0;
}

void move(char direcao) {
    int x;
    int y;

    for (int i = 0; i < linhas; i++) {
        for (int j =0; j < colunas; j++) {
            if (mapa[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }
    switch (direcao) {
        case 'a':
            mapa[x][y-1] = '@';
            break;
        case 'd':
            mapa[x][y+1] = '@';
            break;
        case 'w':
            mapa[x-1][y] = '@';
            break;
        case 's':
            mapa[x+1][y] = '@';
            break;
    }
    mapa[x][y] = '.';

}

int main() {

    lemapa();

    do {
        imprimemapa();
        char comando;
        scanf(" %c", &comando);
        move(comando);

    }while(!acabou());
}