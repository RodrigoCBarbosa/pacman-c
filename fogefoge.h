void lemapa();
void fechamapa();
void liberamapa();
void alocamapa();

int acabou();
void move(char direcao);
void imprimapa();

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;