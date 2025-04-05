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

    // Para o cálculo do Super-poder, devemos considerar a Densidade populacional *invertida* ao fazer a soma de todos os atributos.
    float densidadePopulacionalInvertida = (1.0f / novoDensidadePopulacional);
    float novoSuperPoder = (densidadePopulacionalInvertida + novoPibPerCapita + (float)*pontosTuristicos + (float)*area + (float)*populacao + (float)*pib);

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




/*
    Função válida para todas as propriedades Int32, MENOS Densidade Populacional.
    Retornará um número indicando qual carta foi a vencedora (1 - Carta 1; 2 - Carta 2; 0 - Empate).
*/
int compararPropriedadeGeralERetornarCidadeGanhadora_Int32(int carta1Valor, int carta2Valor) {
    return (carta1Valor > carta2Valor ? 1 : (carta2Valor > carta1Valor ? 2 : 0));
}

/*
    Função válida para todas as propriedades Single32, MENOS Densidade Populacional.
    Retornará um número indicando qual carta foi a vencedora (1 - Carta 1; 2 - Carta 2; 0 - Empate).
*/
int compararPropriedadeGeralERetornarCidadeGanhadora_Single32(float carta1Valor, float carta2Valor) {
    return (carta1Valor > carta2Valor ? 1 : (carta2Valor > carta1Valor ? 2 : 0));
}

/*
    Função válida SOMENTE para a propriedade Densidade Populacional.
    Retornará um número indicando qual carta foi a vencedora (1 - Carta 1; 2 - Carta 2; 0 - Empate).
*/
int compararDensidadePopulacionalERetornarCidadeGanhadora(float carta1Valor, float carta2Valor) {
    return (carta1Valor > carta2Valor ? 2 : (carta2Valor > carta1Valor ? 1 : 0));
}

/*
    Será perguntado ao usuário qual propriedade ele quer comparar. Caso uma opção inválida seja escolhida,
    a função se chamará novamente para garantir que uma opção válida seja retornada.
*/
int perguntarPropriedadeASerComparada(const char* pergunta) {
    printf("%s\n", pergunta);
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
        return perguntarPropriedadeASerComparada(pergunta);
    }
    else if (propriedadeEscolhida <= 0 || propriedadeEscolhida >= 8) {
        printf("Você não informou uma opção válida. Por favor, tente novamente!\n");
        return perguntarPropriedadeASerComparada(pergunta);
    }

    return propriedadeEscolhida;
}

int identificarVencedorEmComparacaoDeUmaPropriedade_Single32(int propriedade, float carta1Propriedade, float carta2Propriedade) {
    switch (propriedade) {
        case 1: //População
        case 2: //Área
        case 3: //Pontos turísticos
        case 5: //PIB
        case 6: //PIB per Capita
        case 7: //Superpoder
            return compararPropriedadeGeralERetornarCidadeGanhadora_Single32(carta1Propriedade, carta2Propriedade);
        case 4: //Densidade populacional
            return compararDensidadePopulacionalERetornarCidadeGanhadora(carta1Propriedade, carta2Propriedade);

        default:
            return 0;
    }
}

float retornarValorSingle32DePropriedadePeloId(int propriedade, int populacao, int area, int pib, int pontosTuristicos, float densidadePopulacional, float pibPerCapita, float superPoder) {
    switch (propriedade) {
        case 1: //População
            return populacao;
        case 2: //Área
            return area;
        case 3: //Pontos turísticos
            return pontosTuristicos;
        case 4: //Densidade populacional
            return densidadePopulacional;
        case 5: //PIB
            return pib;
        case 6: //PIB per Capita
            return pibPerCapita;
        case 7: //Superpoder
            return superPoder;

        default:
            return 0;
    }
}

const char* retornarNomeDaPropriedadePeloId(int propriedade) {
    switch (propriedade) {
        case 1:
            return "População";
        case 2:
            return "Área";
        case 3:
            return "Pontos turísticos";
        case 4:
            return "Densidade populacional";
        case 5:
            return "PIB";
        case 6:
            return "PIB per Capita";
        case 7:
            return "Superpoder";

        default:
            return "Desconhecido";
    }
}

/*
    Duas cartas serão construídas pelo usuário e suas informações serão imprimidas após a construção de ambas.
    Então, o usuário deverá selecionar 2 propriedades a serem comparadas entre as cartas para determinar a carta vencedora.
*/
void desafioMestre() {
    printf("Para começarmos, informe os dados das cidades conforme será solicitado a seguir:\n");

    char* carta1Codigo = malloc(5);
    char* carta1Nome = malloc(32);
    int carta1Populacao = 0, carta1Area = 0, carta1Pib = 0, carta1PontosTuristicos = 0;
    float carta1DensidadePopulacional = 0, carta1PibPerCapita = 0, carta1SuperPoder = 0;
    printf("- Primeira cidade\n");
    perguntarDadosDaCidade(carta1Codigo, carta1Nome, &carta1Populacao, &carta1Area, &carta1Pib, &carta1PontosTuristicos, &carta1DensidadePopulacional, &carta1PibPerCapita, &carta1SuperPoder);

    printf("\n");

    char* carta2Codigo = malloc(5);
    char* carta2Nome = malloc(32);
    int carta2Populacao = 0, carta2Area = 0, carta2Pib = 0, carta2PontosTuristicos = 0;
    float carta2DensidadePopulacional = 0, carta2PibPerCapita = 0, carta2SuperPoder = 0;
    printf("- Segunda cidade\n");
    perguntarDadosDaCidade(carta2Codigo, carta2Nome, &carta2Populacao, &carta2Area, &carta2Pib, &carta2PontosTuristicos, &carta2DensidadePopulacional, &carta2PibPerCapita, &carta2SuperPoder);

    printf("\n");

    imprimirDadosDaCidade(carta1Codigo, carta1Nome, carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos, carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder);
    printf("\n");
    imprimirDadosDaCidade(carta2Codigo, carta2Nome, carta2Populacao, carta2Area, carta2Pib, carta2PontosTuristicos, carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder);

    printf("\n");

    // Pergunta ao usuário qual a propriedade ele deseja usar para a comparação das cartas.
    int propriedade1ParaComparar = perguntarPropriedadeASerComparada("Escolha uma das opções abaixo para ser a primeira propriedade a ser usada na comparação das cartas:");
    int propriedade2ParaComparar = perguntarPropriedadeASerComparada("Escolha uma das opções abaixo para ser a segunda propriedade a ser usada na comparação das cartas:");

    float carta1Propriedade1 = retornarValorSingle32DePropriedadePeloId(propriedade1ParaComparar, carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos, carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder);
    float carta1Propriedade2 = retornarValorSingle32DePropriedadePeloId(propriedade2ParaComparar, carta1Populacao, carta1Area, carta1Pib, carta1PontosTuristicos, carta1DensidadePopulacional, carta1PibPerCapita, carta1SuperPoder);
    float carta2Propriedade1 = retornarValorSingle32DePropriedadePeloId(propriedade1ParaComparar, carta1Populacao, carta2Area, carta2Pib, carta2PontosTuristicos, carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder);
    float carta2Propriedade2 = retornarValorSingle32DePropriedadePeloId(propriedade2ParaComparar, carta1Populacao, carta2Area, carta2Pib, carta2PontosTuristicos, carta2DensidadePopulacional, carta2PibPerCapita, carta2SuperPoder);

    int vencedorPropriedade1 = identificarVencedorEmComparacaoDeUmaPropriedade_Single32(propriedade1ParaComparar, carta1Propriedade1, carta2Propriedade1);
    int vencedorPropriedade2 = identificarVencedorEmComparacaoDeUmaPropriedade_Single32(propriedade2ParaComparar, carta1Propriedade2, carta2Propriedade2);

    int cartaVencedora;
    if (vencedorPropriedade1 == 0 && vencedorPropriedade2 == 0) {
        //Empate claro
        cartaVencedora = 0;
    }
    else if (vencedorPropriedade1 == vencedorPropriedade2) {
        //Vencedor claro
        cartaVencedora = vencedorPropriedade1;
    }
    else if (vencedorPropriedade1 == 0 || vencedorPropriedade2 == 0) {
        //Uma propriedade empatou, mas na outra houve um vencedor
        cartaVencedora = (vencedorPropriedade1 == 0 ? vencedorPropriedade2 : vencedorPropriedade1);
    }
    else {
        //Ambas cartas venceram em 1 propriedade e perderam na outra
        cartaVencedora = 0;
    }

    char* nomeDaCartaVencedora = (char*)"Empate";
    if (cartaVencedora != 0) {
        nomeDaCartaVencedora = (cartaVencedora == 1 ? carta1Nome : carta2Nome);
    }

    const char* nomeDaPropriedade1 = retornarNomeDaPropriedadePeloId(propriedade1ParaComparar);
    const char* nomeDaPropriedade2 = retornarNomeDaPropriedadePeloId(propriedade2ParaComparar);

    printf("Resultado da comparação das 2 propriedades entre as cartas '%s' e '%s':\n", carta1Nome, carta2Nome);
    printf("Carta vencedora: %s!\n\n", nomeDaCartaVencedora);

    printf("Dados que levaram a definir o vencedor:\n");
    printf("[Carta '%s'] Valor da propriedade %s: %f\n", carta1Nome, nomeDaPropriedade1, carta1Propriedade1);
    printf("[Carta '%s'] Valor da propriedade %s: %f\n", carta1Nome, nomeDaPropriedade2, carta1Propriedade2);
    printf("[Carta '%s'] Valor da propriedade %s: %f\n", carta2Nome, nomeDaPropriedade1, carta2Propriedade1);
    printf("[Carta '%s'] Valor da propriedade %s: %f\n", carta2Nome, nomeDaPropriedade2, carta2Propriedade2);
}




int main() {
    desafioMestre();

    return 0;
}