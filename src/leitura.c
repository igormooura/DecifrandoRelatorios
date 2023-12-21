#include "../include/leitura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerArquivoEntrada(const char *codigos, Transacao *transacao) {
    FILE *arquivoEntrada = fopen("../text/codigos.txt", "r");
    if (!arquivoEntrada) {
        fprintf(stderr, "Erro ao abrir o arquivoEntrada de entrada.\n");
        return 0;  // Indica falha
    }

    // Implemente a leitura dos dados do arquivoEntrada de entrada
    // Exemplo:
    fscanf(arquivoEntrada, "%s", transacao->A);
    fscanf(arquivoEntrada, "%s", transacao->B);
    fscanf(arquivoEntrada, "%s", transacao->C);

    fclose(arquivoEntrada);
    return 1;  // Indica sucesso
}