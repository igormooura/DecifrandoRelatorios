#ifndef DECIFRAR_RELATORIO_H
#define DECIFRAR_RELATORIO_H

#include <stdio.h>

typedef struct {
    char A[26];
    char B[26];
    char C[26];
    int correspondencia[26];
} Transacao;

void determinarLetras(Transacao *transacao, char *letras);
int decifrarRelatorio(Transacao *transacao, char *letras, int letraAtualIdx, FILE *arquivoSaida);

#endif