#include <stdio.h>
#include "exstruct.h"



struct registro x;

int main() {
    scanf("%s %s", x.nome, &(x.telefone));

    printf("%s %s", x.nome, x.telefone);

    return 0;
}