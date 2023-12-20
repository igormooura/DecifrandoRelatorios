#ifndef ENTRADA_H
#define ENTRADA_H

typedef struct {
    char A[9];
    char B[9];
    char C[9];
    int correspondencia[26];  // Nova adição
} Transacao;

void lerRelatorios(const char *codigos, Transacao *transacao);

#endif
