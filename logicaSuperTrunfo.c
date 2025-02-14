#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 

#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
void perguntarDadosDaCidade(char* codigoDaCidade, char* nome, int& populacao, int& area, int& pib, int& pontosTuristicos, float& densidadePopulacional, float& pibPerCapita, float& superPoder) {
    // Solicita ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    printf("Insira o código da cidade:\n");
    scanf("%s", codigoDaCidade);

    printf("Insira o nome da cidade:\n");
    scanf("%s", nome);

    printf("Insira o tamanho da população da cidade:\n");
    scanf("%d", &populacao);

    printf("Insira o tamanho da área da cidade:\n");
    scanf("%d", &area);

    printf("Insira o PIB da cidade:\n");
    scanf("%d", &pib);

    printf("Insira o número de pontos turísticos da cidade:\n");
    scanf("%d", &pontosTuristicos);

    // Define as propriedades que precisam ser calculadas após termos todas as informações da cidade
    densidadePopulacional = ((float)populacao / (float)area);
    pibPerCapita = ((float)pib / (float)populacao);
    superPoder = densidadePopulacional + pibPerCapita + (float)pontosTuristicos + (float)area + (float)populacao + (float)pib;
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

//Função válida para todas as propriedades, MENOS Densidade Populacional.
void compararPropriedadeGeralEInformarCidadeGanhadora(const char* propriedadeNome, float carta1Valor, float carta2Valor, char* carta1NomeDaCidade, char* carta2NomeDaCidade) {
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

    char* carta1Codigo = new char[5];
    char* carta1Nome = new char[32];
    int carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos;
    float carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder;
    printf("- Primeira cidade\n");
    perguntarDadosDaCidade(carta1Codigo, carta1Nome, carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos, carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder);

    printf("\n");

    char* carta2Codigo = new char[5];
    char* carta2Nome = new char[32];
    int carta2Populacao, carta2Area, carta2Pib, carta2PontosTuristicos;
    float carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder;
    printf("- Segunda cidade\n");
    perguntarDadosDaCidade(carta2Codigo, carta2Nome, carta2Populacao, carta2Area, carta2Pib, carta2PontosTuristicos, carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder);

    printf("\n");

    imprimirDadosDaCidade(carta1Codigo, carta1Nome, carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos, carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder);
    printf("\n");
    imprimirDadosDaCidade(carta2Codigo, carta2Nome, carta2Populacao, carta2Area, carta2Pib, carta2PontosTuristicos, carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder);

    printf("\n");

    // Exibe os valores inseridos para cada atributo da cidade, um por linha.
    printf("Resultado da comparação entre as cidades '%s' e '%s':\n", carta1Nome, carta2Nome);
    compararPropriedadeGeralEInformarCidadeGanhadora("Tamanho da população", carta1Populacao, carta2Populacao, carta1Nome, carta2Nome);
    /*compararPropriedadeGeralEInformarCidadeGanhadora("Tamanho da área", carta1Area, carta2Area, carta1Nome, carta2Nome);
    compararPropriedadeGeralEInformarCidadeGanhadora("Total de pontos turísticos", carta1PontosTuristicos, carta2PontosTuristicos, carta1Nome, carta2Nome);
    compararDensidadePopulacionalEInformarCidadeGanhadora("Densidade populacional", carta1DensidadePopulacional, carta2DensidadePopulacional, carta1Nome, carta2Nome);
    compararPropriedadeGeralEInformarCidadeGanhadora("PIB per Capita", carta1PibPerCapita, carta2PibPerCapita, carta1Nome, carta2Nome);
    compararPropriedadeGeralEInformarCidadeGanhadora("PIB total", carta1Pib, carta2Pib, carta1Nome, carta2Nome);
    compararPropriedadeGeralEInformarCidadeGanhadora("Superpoder", carta1SuperPoder, carta2SuperPoder, carta1Nome, carta2Nome);*/
}






//Função válida para todas as propriedades, MENOS Densidade Populacional.
void compararPropriedadeGeralEInformarCidadeGanhadora_Aventureiro(const char* propriedadeNome, float carta1Valor, float carta2Valor, char* carta1NomeDaCidade, char* carta2NomeDaCidade) {
    printf("Resultado da comparação de %s entre as cidades '%s' e '%s':\n", propriedadeNome, carta1NomeDaCidade, carta2NomeDaCidade);

    if (carta1Valor > carta2Valor) {
        printf("Vencedor: '%s' devido a %f ser maior do que %f.\n", carta1NomeDaCidade, carta1Valor, carta2Valor);
    }
    else if (carta2Valor > carta1Valor) {
        printf("Vencedor: '%s' devido a %f ser maior do que %f.\n", carta2NomeDaCidade, carta2Valor, carta1Valor);
    }
    else {
        printf("Vencedor: Empate devido a %f ser igual a %f.\n", carta1Valor, carta2Valor);
    }
}

//Função válida SOMENTE para a propriedade Densidade Populacional.
void compararDensidadePopulacionalEInformarCidadeGanhadora_Aventureiro(const char* propriedadeNome, float carta1Valor, float carta2Valor, char* carta1NomeDaCidade, char* carta2NomeDaCidade) {
    printf("Resultado da comparação de %s entre as cidades '%s' e '%s':\n", propriedadeNome, carta1NomeDaCidade, carta2NomeDaCidade);

    if (carta1Valor > carta2Valor) {
        printf("Vencedor: '%s' devido a %f ser menor do que %f.\n", carta2NomeDaCidade, carta2Valor, carta1Valor);
    }
    else if (carta2Valor > carta1Valor) {
        printf("Vencedor: '%s' devido a %f ser menor do que %f.\n", carta1NomeDaCidade, carta1Valor, carta2Valor);
    }
    else {
        printf("Vencedor: Empate devido a %f ser igual a %f.\n", carta1Valor, carta2Valor);
    }
}

/*
    Será perguntado ao usuário qual propriedade ele quer comparar. Caso uma opção inválida seja escolhida,
    a função se chamará novamente para garantir que uma opção válida seja retornada.
*/
int perguntarPropriedadeASerComparada() {
    printf("Informe qual o número da propriedade que deseja comparar entre as cartas, conforme as opções a seguir:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. Pontos turísticos\n");
    printf("4. Densidade populacional\n");
    printf("5. PIB\n");
    printf("6. PIB Per Capita\n");
    printf("7. Superpoder\n");

    int propriedadeEscolhida;
    int result = scanf("%d", &propriedadeEscolhida);
    if (result != 1) {
        printf("Você não informou um número válido. Por favor, tente novamente!\n");
        return perguntarPropriedadeASerComparada();
    }
    else if (propriedadeEscolhida <= 0 || propriedadeEscolhida >= 8) {
        printf("Você não informou uma opção válida. Por favor, tente novamente!\n");
        return perguntarPropriedadeASerComparada();
    }

    return propriedadeEscolhida;
}

/*
    Duas cartas serão construídas pelo usuário e suas informações serão imprimidas após a construção de ambas.
    Então, o usuário deverá selecionar qual propriedade ele deseja comparar entre as cartas para determinar a carta vencedora.
*/
void desafioAventureiro() {
    printf("Para começarmos, informe os dados das cidades conforme será solicitado a seguir:\n");

    char* carta1Codigo = new char[5];
    char* carta1Nome = new char[32];
    int carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos;
    float carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder;
    printf("- Primeira cidade\n");
    perguntarDadosDaCidade(carta1Codigo, carta1Nome, carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos, carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder);

    printf("\n");

    char* carta2Codigo = new char[5];
    char* carta2Nome = new char[32];
    int carta2Populacao, carta2Area, carta2Pib, carta2PontosTuristicos;
    float carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder;
    printf("- Segunda cidade\n");
    perguntarDadosDaCidade(carta2Codigo, carta2Nome, carta2Populacao, carta2Area, carta2Pib, carta2PontosTuristicos, carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder);

    printf("\n");

    imprimirDadosDaCidade(carta1Codigo, carta1Nome, carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos, carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder);
    printf("\n");
    imprimirDadosDaCidade(carta2Codigo, carta2Nome, carta2Populacao, carta2Area, carta2Pib, carta2PontosTuristicos, carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder);

    printf("\n");

    // Pergunta ao usuário qual a propriedade ele deseja usar para a comparação das cartas.
    int propriedadeParaComparar = perguntarPropriedadeASerComparada();

    // Exibe o resultado final da comparação escolhida:
    switch (propriedadeParaComparar) {
        case 1: //População
            compararPropriedadeGeralEInformarCidadeGanhadora_Aventureiro("Tamanho da população", carta1Populacao, carta2Populacao, carta1Nome, carta2Nome);
            break;
        case 2: //Área
            compararPropriedadeGeralEInformarCidadeGanhadora_Aventureiro("Tamanho da área", carta1Area, carta2Area, carta1Nome, carta2Nome);
            break;
        case 3: //Pontos turísticos
            compararPropriedadeGeralEInformarCidadeGanhadora_Aventureiro("Total de pontos turísticos", carta1PontosTuristicos, carta2PontosTuristicos, carta1Nome, carta2Nome);
            break;
        case 4: //Densidade populacional
            compararDensidadePopulacionalEInformarCidadeGanhadora_Aventureiro("Densidade populacional", carta1DensidadePopulacional, carta2DensidadePopulacional, carta1Nome, carta2Nome);
            break;
        case 5: //PIB
            compararPropriedadeGeralEInformarCidadeGanhadora_Aventureiro("PIB total", carta1Pib, carta2Pib, carta1Nome, carta2Nome);
            break;
        case 6: //PIB per Capita
            compararPropriedadeGeralEInformarCidadeGanhadora_Aventureiro("PIB per Capita", carta1PibPerCapita, carta2PibPerCapita, carta1Nome, carta2Nome);
            break;
        case 7: //Superpoder
            compararPropriedadeGeralEInformarCidadeGanhadora_Aventureiro("Superpoder", carta1SuperPoder, carta2SuperPoder, carta1Nome, carta2Nome);
            break;
    }
}

int main() {
    //desafioNovato();
    desafioAventureiro();
    //desafioMestre();

    return 0;
}