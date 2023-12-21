#include "../include/decifrar_relatorio.h"
#include "../include/saida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escreverArquivoSaida(const char *resultados, int resultado, Transacao *transacao, char *letras) 
{
    // Abra o arquivo no diretório desejado (../text/)
    FILE *arquivoSaida = fopen("../text/resultados.txt", "w");
    if (!arquivoSaida) {
        fprintf(stderr, "Erro ao abrir o arquivo de saída.\n");
        return;
    }

    fprintf(arquivoSaida, "Saída:\n");

    for (int i = 0; i < strlen(letras); i++) {
        char letra = letras[i];
        fprintf(arquivoSaida, "%c:%d\n", letra, transacao->correspondencia[letra - 'A']);
    }

    fprintf(arquivoSaida, "Resultado da decifração: %d\n", resultado);
    imprimirResultado(arquivoSaida, transacao, letras);

    fclose(arquivoSaida);
}
void imprimirResultado(FILE *saida, Transacao *transacao, char *letras) {
    fprintf(saida, "Saída:\n");

    for (int i = 0; i < strlen(letras); i++) {
        char letra = letras[i];
        fprintf(saida, "%c:%d\n", letra, transacao->correspondencia[letra - 'A']);
    }
}