#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

struct posicao {
    int x;
    int y;
};

typedef struct posicao POSICAO;
typedef struct mapa MAPA;

void lemapa(MAPA* m);
void liberamapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);
void encontramapa(MAPA* m, POSICAO* p, char c);

int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA*m, int x, int y);
int andamapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);



