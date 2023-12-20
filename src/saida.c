#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/saida.h"

void imprimirResultados(const char *resultados, const Transacao *transacao, char letraMaxima) {
    FILE *arquivoSaida = fopen("../text/resultados.txt", "w");

    if (arquivoSaida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        exit(EXIT_FAILURE);
    }

    // Redireciona a saída para o arquivo
    fprintf(arquivoSaida, "Resultado da decifração:\n");

    int i;
    int lenC = strlen(transacao->C);

    // Imprime o valor decifrado
    for (i = 0; i < lenC; i++) {
        fprintf(arquivoSaida, "%d", transacao->correspondencia[transacao->C[i] - 'A']);
    }
    fprintf(arquivoSaida, "\n");

    // Imprime as correspondências
    fprintf(arquivoSaida, "Correspondências utilizadas:\n");
    for (i = 0; i <= letraMaxima - 'A'; i++) {
        if (transacao->correspondencia[i] != -1) {
            fprintf(arquivoSaida, "%c:%d\n", i + 'A', transacao->correspondencia[i]);
        }
    }

    // Fecha o arquivo
    fclose(arquivoSaida);
}
