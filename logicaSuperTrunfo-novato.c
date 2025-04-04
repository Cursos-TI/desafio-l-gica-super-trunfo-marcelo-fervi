#include <stdio.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
void perguntarDadosDaCidade(char* codigoDaCidade, char* nome, int* populacao, int* area, int* pib, int* pontosTuristicos, float* densidadePopulacional, float* pibPerCapita, float* superPoder) {
    // Solicita ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    printf("Insira o código da cidade:\n");
    scanf("%s", codigoDaCidade);

    printf("Insira o nome da cidade:\n");
    scanf("%s", nome);

    printf("Insira o tamanho da população da cidade:\n");
    scanf("%d", populacao);

    printf("Insira o tamanho da área da cidade:\n");
    scanf("%d", area);

    printf("Insira o PIB da cidade:\n");
    scanf("%d", pib);

    printf("Insira o número de pontos turísticos da cidade:\n");
    scanf("%d", pontosTuristicos);

    // Define as propriedades que precisam ser calculadas após termos todas as informações da cidade
    float novoDensidadePopulacional = ((float)*populacao / (float)*area);
    float novoPibPerCapita = ((float)*pib / (float)*populacao);
    float novoSuperPoder = (*densidadePopulacional + *pibPerCapita + (float)*pontosTuristicos + (float)*area + (float)*populacao + (float)*pib);

    *densidadePopulacional = novoDensidadePopulacional;
    *pibPerCapita = novoPibPerCapita;
    *superPoder = novoSuperPoder;
}

void imprimirDadosDaCidade(char* codigoDaCidade, char* nome, int populacao, int area, int pib, int pontosTuristicos, float densidadePopulacional, float pibPerCapita, float superPoder) {
    printf("- Dados da cidade '%s':\n", nome);
    printf("Código: %s\n", codigoDaCidade);
    printf("População: %d\n", populacao);
    printf("Área: %d\n", area);
    printf("Pontos turísticos: %d\n", pontosTuristicos);
    printf("Densidade populacional: %f\n", densidadePopulacional);
    printf("PIB: %d\n", pib);
    printf("PIB Per Capita: %f\n", pibPerCapita);
    printf("Superpoder: %f\n", superPoder);
}

//Função válida para comparar todas as propriedades, MENOS Densidade Populacional.
//Esta variante deve ser usada SOMENTE para variáveis do tipo INT32 (int).
void compararPropriedadeGeralEInformarCidadeGanhadora_Int32(const char* propriedadeNome, int carta1Valor, int carta2Valor, char* carta1NomeDaCidade, char* carta2NomeDaCidade) {
    if (carta1Valor > carta2Valor) {
        printf("%s: %d e %d (Vencedor: '%s'; Valor: %f)\n", propriedadeNome, carta1Valor, carta2Valor, carta1NomeDaCidade, carta1Valor);
    }
    else if (carta2Valor > carta1Valor) {
        printf("%s: %d e %d (Vencedor: '%s'; Valor: %f)\n", propriedadeNome, carta1Valor, carta2Valor, carta2NomeDaCidade, carta2Valor);
    }
    else {
        printf("%s: %d e %d (Vencedor: Empate; Valor: %f)\n", propriedadeNome, carta1Valor, carta2Valor, carta1Valor);
    }
}

//Função válida para comparar todas as propriedades, MENOS Densidade Populacional.
//Esta variante deve ser usada SOMENTE para variáveis do tipo SINGLE32 (float).
void compararPropriedadeGeralEInformarCidadeGanhadora_Single32(const char* propriedadeNome, float carta1Valor, float carta2Valor, char* carta1NomeDaCidade, char* carta2NomeDaCidade) {
    if (carta1Valor > carta2Valor) {
        printf("%s: %f e %f (Vencedor: '%s'; Valor: %f)\n", propriedadeNome, carta1Valor, carta2Valor, carta1NomeDaCidade, carta1Valor);
    }
    else if (carta2Valor > carta1Valor) {
        printf("%s: %f e %f (Vencedor: '%s'; Valor: %f)\n", propriedadeNome, carta1Valor, carta2Valor, carta2NomeDaCidade, carta2Valor);
    }
    else {
        printf("%s: %f e %f (Vencedor: Empate; Valor: %f)\n", propriedadeNome, carta1Valor, carta2Valor, carta1Valor);
    }
}

//Função válida SOMENTE para a propriedade Densidade Populacional.
void compararDensidadePopulacionalEInformarCidadeGanhadora(const char* propriedadeNome, float carta1Valor, float carta2Valor, char* carta1NomeDaCidade, char* carta2NomeDaCidade) {
    if (carta1Valor > carta2Valor) {
        printf("%s: %f e %f (Vencedor: '%s'; Valor: %f)\n", propriedadeNome, carta1Valor, carta2Valor, carta2NomeDaCidade, carta2Valor);
    }
    else if (carta2Valor > carta1Valor) {
        printf("%s: %f e %f (Vencedor: '%s'; Valor: %f)\n", propriedadeNome, carta1Valor, carta2Valor, carta1NomeDaCidade, carta1Valor);
    }
    else {
        printf("%s: %f e %f (Vencedor: Empate; Valor: %f)\n", propriedadeNome, carta1Valor, carta2Valor, carta1Valor);
    }
}

/*
    Duas cartas serão construídas pelo usuário, suas informações serão imprimidas após a construção de ambas,
    e será comparada a propriedade "Tamanho da população" para determinar a carta vencedora.
*/
void desafioNovato() {
    printf("Para começarmos, informe os dados das cidades conforme será solicitado a seguir:\n");

    char* carta1Codigo = malloc(5);
    char* carta1Nome = malloc(32);
    int carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos;
    float carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder;
    printf("- Primeira cidade\n");
    perguntarDadosDaCidade(carta1Codigo, carta1Nome, &carta1Populacao, &carta1Area, &carta1Pib, &carta1PontosTuristicos, &carta1DensidadePopulacional, &carta1PibPerCapita, &carta1SuperPoder);

    printf("\n");

    char* carta2Codigo = malloc(5);
    char* carta2Nome = malloc(32);
    int carta2Populacao, carta2Area, carta2Pib, carta2PontosTuristicos;
    float carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder;
    printf("- Segunda cidade\n");
    perguntarDadosDaCidade(carta2Codigo, carta2Nome, &carta2Populacao, &carta2Area, &carta2Pib, &carta2PontosTuristicos, &carta2DensidadePopulacional, &carta2PibPerCapita, &carta2SuperPoder);

    printf("\n");

    imprimirDadosDaCidade(carta1Codigo, carta1Nome, carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos, carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder);
    printf("\n");
    imprimirDadosDaCidade(carta2Codigo, carta2Nome, carta2Populacao, carta2Area, carta2Pib, carta2PontosTuristicos, carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder);

    printf("\n");

    // Exibe os valores inseridos para cada atributo da cidade, um por linha.
    printf("Resultado da comparação entre as cidades '%s' e '%s':\n", carta1Nome, carta2Nome);

    //Somente a propriedade 'população' será considerada para determinar a carta vencedora.
    compararPropriedadeGeralEInformarCidadeGanhadora_Int32("Tamanho da população", carta1Populacao, carta2Populacao, carta1Nome, carta2Nome);
    /*compararPropriedadeGeralEInformarCidadeGanhadora_Int32("Tamanho da área", carta1Area, carta2Area, carta1Nome, carta2Nome);
    compararPropriedadeGeralEInformarCidadeGanhadora_Int32("Total de pontos turísticos", carta1PontosTuristicos, carta2PontosTuristicos, carta1Nome, carta2Nome);
    compararDensidadePopulacionalEInformarCidadeGanhadora("Densidade populacional", carta1DensidadePopulacional, carta2DensidadePopulacional, carta1Nome, carta2Nome);
    compararPropriedadeGeralEInformarCidadeGanhadora_Single32("PIB per Capita", carta1PibPerCapita, carta2PibPerCapita, carta1Nome, carta2Nome);
    compararPropriedadeGeralEInformarCidadeGanhadora_Int32("PIB total", carta1Pib, carta2Pib, carta1Nome, carta2Nome);
    compararPropriedadeGeralEInformarCidadeGanhadora_Single32("Superpoder", carta1SuperPoder, carta2SuperPoder, carta1Nome, carta2Nome);*/
}

int main() {
    desafioNovato();

    return 0;
}