void lemapa();
void liberamapa();
void alocamapa();
void imprimemapa();

int acabou();
void move(char direcao);


struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;