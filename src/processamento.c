#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/processamento.h"

void decifrarRelatorio(Transacao *transacao, char letraAtual, int numeroAtual) {
    if (letraAtual > 'Z') {
        // Todas as letras foram processadas, verifica se a transação é válida
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
            // Transação válida, você pode realizar alguma ação aqui se necessário
            return;
        }
    } else {
        // Tenta atribuir um número para a letra atual e chama recursivamente para a próxima letra
        for (int numero = 0; numero <= 9; numero++) {
            if (transacao->correspondencia[letraAtual - 'A'] == -1) {
                // Atribui o número para a letra
                transacao->correspondencia[letraAtual - 'A'] = numero;

                // Chama recursivamente para a próxima letra
                decifrarRelatorio(transacao, letraAtual + 1, numero);

                // Desfaz a atribuição para tentar com outro número
                transacao->correspondencia[letraAtual - 'A'] = -1;
            }
        }
    }
}
