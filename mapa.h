struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

void lemapa(MAPA* m);
void liberamapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);



