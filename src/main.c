// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/leitura.h"
#include "../include/processamento.h"
#include "../include/saida.h"

int main(int argc, char *argv[]) {
    // Verifica se foram fornecidos argumentos suficientes
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo_entrada> <arquivo_saida>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Transacao transacao;

    // Leitura dos relatórios do arquivo de entrada
    lerRelatorios(argv[1], &transacao);

    // Processamento
    decifrarRelatorio(&transacao, 'A', 0);  // Adicione os valores iniciais

    // Obtém a letra máxima da transação
    char letraMaxima = 'A';
    for (int i = 0; i < strlen(transacao.C); i++) {
        if (transacao.C[i] > letraMaxima) {
            letraMaxima = transacao.C[i];
        }
    }

    // Impressão dos resultados no arquivo de saída
    imprimirResultados(argv[2], &transacao, letraMaxima);

    return 0;
}
