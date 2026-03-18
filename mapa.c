#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void alocamapa(MAPA* m) {
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for (int i = 0; i < m->linhas; i++) {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void lemapa(MAPA* m) {
    FILE* f = fopen("mapa.txt", "r");
    if (f == NULL) {
        printf("erro");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    printf("linhas %d, colunas %d\n", m->linhas, m->colunas);

    alocamapa(m);

    for (int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void imprimemapa(MAPA* m) {
    for (int i = 0; i < m->linhas; i++) {
        printf("%s\n", m->matriz[i]);
    }
}

void liberamapa(MAPA* m) {
    for (int i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}