#include "../include/decifrar_relatorio.h"
#include "../include/leitura.h"
#include "../include/saida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo_entrada> <arquivo_saida>\n", argv[0]);
        return 1;
    }
    argv[1] = "../text/codigos.txt";
    argv[2] = "../text/resultados.txt";


    Transacao transacao;
    char letras[26];

    if (!lerArquivoEntrada(argv[1], &transacao)) {
        return 1;
    }

    determinarLetras(&transacao, letras);
    memset(transacao.correspondencia, -1, sizeof(transacao.correspondencia));

    FILE *arquivoSaida = fopen(argv[2], "w");
    if (!arquivoSaida) {
        fprintf(stderr, "Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    int resultado = decifrarRelatorio(&transacao, letras, 0, arquivoSaida);

    fclose(arquivoSaida);

    return 0;
}

