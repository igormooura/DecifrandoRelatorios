#include "../include/decifrar_relatorio.h"
#include "../include/saida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void determinarLetras(Transacao *transacao, char *letras) {
    int i, j;
    int letraPresente[26] = {0};

    // Marcar letras presentes em A, B e C
    for (i = 0; i < strlen(transacao->A); i++) {
        letraPresente[transacao->A[i] - 'A'] = 1;
    }
    for (i = 0; i < strlen(transacao->B); i++) {
        letraPresente[transacao->B[i] - 'A'] = 1;
    }
    for (i = 0; i < strlen(transacao->C); i++) {
        letraPresente[transacao->C[i] - 'A'] = 1;
    }

    // Preencher 'letras' com letras presentes, na ordem de A, B e C
    j = 0;
    for (i = 0; i < 26; i++) {
        if (letraPresente[i]) {
            letras[j++] = 'A' + i;
        }
    }
    letras[j] = '\0';
}

int decifrarRelatorio(Transacao *transacao, char *letras, int letraAtualIdx, FILE *arquivoSaida) {
    if (letras[letraAtualIdx] == '\0') {
        int valorA = 0, valorB = 0, valorC = 0;

        for (int i = 0; i < strlen(transacao->A); i++) {
            valorA = valorA * 10 + transacao->correspondencia[transacao->A[i] - 'A'];
        }

        for (int i = 0; i < strlen(transacao->B); i++) {
            valorB = valorB * 10 + transacao->correspondencia[transacao->B[i] - 'A'];
        }

        for (int i = 0; i < strlen(transacao->C); i++) {
            valorC = valorC * 10 + transacao->correspondencia[transacao->C[i] - 'A'];
        }

        if (valorA + valorB == valorC) {
            fprintf(arquivoSaida, "%d\n", valorC);
            imprimirResultado(arquivoSaida, transacao, letras);
            // Remova o exit(0) para continuar verificando outras soluções
            // exit(0);
            return 1;  // Adicionamos um retorno para indicar que encontramos uma solução
        }

        return -1;
    }

    int resposta = -1;

    for (int numero = 0; numero <= 9; numero++) {
        int atribuido = 0;

        for (int i = 0; i < 26; i++) {
            if (transacao->correspondencia[i] == numero) {
                atribuido = 1;
                break;
            }
        }

        if (atribuido) {
            continue;
        }

        transacao->correspondencia[letras[letraAtualIdx] - 'A'] = numero;

        int retorno = decifrarRelatorio(transacao, letras, letraAtualIdx + 1, arquivoSaida);

        if (retorno > resposta) {
            resposta = retorno;
        }

        transacao->correspondencia[letras[letraAtualIdx] - 'A'] = -1;
    }

    return resposta;
}

