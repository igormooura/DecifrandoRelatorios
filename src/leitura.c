#include <stdio.h>
#include <stdlib.h>
#include "../include/leitura.h"

void lerRelatorios(const char *codigos, Transacao *transacao) {
    FILE *arquivoLeitura = fopen("../text/codigos.txt", "r");

    if (arquivoLeitura == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        exit(EXIT_FAILURE);
    }

    if (fscanf(arquivoLeitura, "%s %s %s", transacao->A, transacao->B, transacao->C) != 3) {
        fprintf(stderr, "Erro ao ler os relatórios do arquivo de entrada\n");
        fclose(arquivoLeitura);
        exit(EXIT_FAILURE);
    }

    fclose(arquivoLeitura);
}
