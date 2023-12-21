#include "../include/decifrar_relatorio.h"
#include "../include/saida.h"
#include "../include/leitura.h"
#include "../include/erros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decifrarTransacao(Transacao *transacao, char *letras, FILE *arquivoSaida) {
    // Chame a função de decifração aqui
    int resultado = decifrarRelatorio(transacao, letras, 0, arquivoSaida);

    // Escreva os resultados no arquivo de saída
    escreverArquivoSaida(resultado, transacao, letras);

    return resultado;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        reportError("Uso: %s <codigos.txt> <resultados.txt>\n");
        return 1;
    }

    Transacao transacao;
    char letras[26];

    if (!lerArquivoEntrada(argv[1], &transacao)) {
        return 1;
    }

    determinarLetras(&transacao, letras);
    memset(transacao.correspondencia, -1, sizeof(transacao.correspondencia));

    FILE *arquivoSaida = fopen(argv[2], "w");
    if (!arquivoSaida) {
        reportError("Erro ao abrir o arquivo de saída %s.\n");
        return 1;
    }

    // Chame a função decifrarTransacao diretamente aqui
    decifrarTransacao(&transacao, letras, arquivoSaida);

    fclose(arquivoSaida);

    return 0;
}
