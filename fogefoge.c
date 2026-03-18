#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

MAPA m;

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
            matriz[x][y-1] = '@';
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
        printf("\n");
    }while(!acabou());
}