#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;


void fantasmas() {
    MAPA copia;

    copiamapa(&copia, &m);

    for (int i = 0; i < m.linhas; i++){
        for (int j = 0; j < m.colunas; j++) {

            if (copia.matriz[i][j] == FANTASMA) {
                if (ehvalida(&m, i , j+1) && (ehvazia(&m, i, j+1))) {
                    andamapa(&m, i ,j, i, j+1);


                }
            }
        }
    }
    liberamapa(&copia);
}

int acabou() {
    return 0;
}

int ehdirecao(char direcao) {
    return(direcao == CIMA || direcao == ESQUERDA || direcao == BAIXO || direcao == DIREITA);
}

void move(char direcao) {
    if (!ehdirecao(direcao)) {
        printf("direcao invalida!");
        return;
    }

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch (direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case DIREITA:
            proximoy++;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
    }

    if (!ehvalida(&m, proximox, proximoy))
        return;

    if (!ehvazia(&m, proximox, proximoy))
        return;

    andamapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;

}

int main() {

    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);

    do {
        imprimemapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();
    }while(!acabou());

    liberamapa(&m);
}