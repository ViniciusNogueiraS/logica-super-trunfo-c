#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

typedef struct {
    int numCarta;
    char estado[50];
    char codigo[3];
    char nomeCidade[50];
    int populacao;
    int area;
    int pib;
    int numPontosTuristicos;
    double densidadePopulacional;
    double pibPerCapita;
} Carta;

int escolherCarta() {

    int cartaEscolhida = 0;

    printf("Escolha a sua Carta:\n");
    printf("1. CARTA 1\n");
    printf("2. CARTA 2\n");
    scanf("%d", &cartaEscolhida);

    if (cartaEscolhida < 1 || cartaEscolhida > 2) {
        printf("Opção inválida. Tente novamente.\n");
        return escolherCarta();
    }

    printf("Você escolheu a CARTA %d!\n", cartaEscolhida);
    return cartaEscolhida;
}

int escolherAtributo(int atributo1Escolhido) {

    int attr = 0;

    printf("▲▼\n");
    printf("Escolha um atributo da SUA CARTA para comparar com o mesmo atributo da CARTA ADVERSÁRIA:\n");
    printf("1. População da Cidade\n");
    printf("2. Área da Cidade\n");
    printf("3. PIB da Cidade\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB Per Capita\n");
    printf("Escolha um atributo pelo n.: \n");
    scanf("%d", &attr);

    switch (attr) {

        case 1:
            if (atributo1Escolhido == 1) {
                printf("Você já escolheu esse atributo. Escolha outro.\n");
                return escolherAtributo(atributo1Escolhido);
            }
            printf("Você escolheu o atributo |População da Cidade|\n");
            return attr;
        case 2:
            if (atributo1Escolhido == 2) {
                printf("Você já escolheu esse atributo. Escolha outro.\n");
                return escolherAtributo(atributo1Escolhido);
            }
            printf("Você escolheu o atributo |Área da Cidade|\n");
            return attr;
        case 3:
            if (atributo1Escolhido == 3) {
                printf("Você já escolheu esse atributo. Escolha outro.\n");
                return escolherAtributo(atributo1Escolhido);
            }
            printf("Você escolheu o atributo |PIB da Cidade|\n");
            return attr;
        case 4:
            if (atributo1Escolhido == 4) {
                printf("Você já escolheu esse atributo. Escolha outro.\n");
                return escolherAtributo(atributo1Escolhido);
            }
            printf("Você escolheu o atributo |Número de Pontos Turísticos|\n");
            return attr;
        case 5:
            if (atributo1Escolhido == 5) {
                printf("Você já escolheu esse atributo. Escolha outro.\n");
                return escolherAtributo(atributo1Escolhido);
            }
            printf("Você escolheu o atributo |Densidade Populacional|\n");
            return attr;
        case 6:
            if (atributo1Escolhido == 6) {
                printf("Você já escolheu esse atributo. Escolha outro.\n");
                return escolherAtributo(atributo1Escolhido);
            }
            printf("Você escolheu o atributo |PIB Per Capita|\n");
            return attr;
        
        default:
            printf("Opção inválida. Tente novamente.\n");
            return escolherAtributo(atributo1Escolhido);
    }
}

int compararCartas(Carta deck[], int cartaEscolhida, int attr) {

    int minhaCarta = cartaEscolhida == 1 ? 0 : 1;
    int outraCarta = minhaCarta == 0 ? 1 : 0;
    int ponto = 0;

    switch (attr) {
        double attrMinhaCarta;
        double attrOutraCarta;

        case 1:
            attrMinhaCarta = deck[minhaCarta].populacao;
            attrOutraCarta = deck[outraCarta].populacao;
            ponto = attrMinhaCarta > attrOutraCarta ? 1 : 0;
            break;
        case 2:
            attrMinhaCarta = deck[minhaCarta].area;
            attrOutraCarta = deck[outraCarta].area;
            ponto = attrMinhaCarta > attrOutraCarta ? 1 : 0;
            break;
        case 3:
            attrMinhaCarta = deck[minhaCarta].pib;
            attrOutraCarta = deck[outraCarta].pib;
            ponto = attrMinhaCarta > attrOutraCarta ? 1 : 0;
            break;
        case 4:
            attrMinhaCarta = deck[minhaCarta].numPontosTuristicos;
            attrOutraCarta = deck[outraCarta].numPontosTuristicos;
            ponto = attrMinhaCarta > attrOutraCarta ? 1 : 0;
            break;
        case 5:
            attrMinhaCarta = deck[minhaCarta].densidadePopulacional;
            attrOutraCarta = deck[outraCarta].densidadePopulacional;
            ponto = attrMinhaCarta < attrOutraCarta ? 1 : 0;
            break;
        case 6:
            attrMinhaCarta = deck[minhaCarta].pibPerCapita;
            attrOutraCarta = deck[outraCarta].pibPerCapita;
            ponto = attrMinhaCarta > attrOutraCarta ? 1 : 0;
            break;
        
        default:
            return 0;
    }

    return ponto;
}


int main() {

    Carta deck[2];
    int q = sizeof(deck) / sizeof(deck[0]);
 
    for(int i = 0; i < q; i++) {
        printf("\n▲▼ ▲▼ ▲▼ CARTA %d ▲▼ ▲▼ ▲▼ \n", i + 1);
        printf("Digite o Estado: ");
        scanf(" %[^\n]", deck[i].estado);
        printf("Digite o Código do Estado: ");
        scanf(" %[^\n]", deck[i].codigo);
        printf("Digite o Nome da Cidade: ");
        scanf(" %[^\n]", deck[i].nomeCidade);
        printf("Digite a População da Cidade: ");
        scanf("%d%*c", &deck[i].populacao);
        printf("Digite a Área da Cidade em km²: ");
        scanf("%d%*c", &deck[i].area);
        printf("Digite o PIB da Cidade em bilhões de reais: ");
        scanf("%d%*c", &deck[i].pib);
        printf("Digite o número de pontos Turísticos: ");
        scanf("%d%*c", &deck[i].numPontosTuristicos);

        deck[i].numCarta = i + 1;
        deck[i].densidadePopulacional = deck[i].populacao / deck[i].area;
        deck[i].pibPerCapita = (deck[i].pib * 1000000) / deck[i].populacao;
    }

    printf("\n");
    printf("\n");
    printf("\n");
    
    for(int i = 0; i < q; i++) {
        printf("\n================== CARTA %d - %s ==================", deck[i].numCarta, deck[i].nomeCidade);
        printf("\nEstado: %s", deck[i].estado);
        printf("\nCódigo do Estado: %s", deck[i].codigo);
        printf("\nNome da Cidade: %s", deck[i].nomeCidade);
        printf("\nPopulação da Cidade: %d", deck[i].populacao);
        printf("\nÁrea da Cidade: %d km²", deck[i].area);
        printf("\nPIB da Cidade: R$ %d bilhões", deck[i].pib);
        printf("\nNúmero de Pontos Turísticos: %d", deck[i].numPontosTuristicos);
        printf("\nDensidade Populacional: %.2lf hab/km²", deck[i].densidadePopulacional);
        printf("\nPIB Per Capita: R$ %.2lf", deck[i].pibPerCapita);
        printf("\n");
    }
    
    printf("\n");
    printf("\n");
    printf("\n");
    
    printf("▲▼\n");
    int cartaEscolhida = escolherCarta();
    printf("▲▼ ATRIBUTO 1\n");
    int attr1 = escolherAtributo(0);
    printf("▲▼ ATRIBUTO 2\n");
    int attr2 = escolherAtributo(attr1);
    printf("▲▼\n");
    int comparacao1 = compararCartas(deck, cartaEscolhida, attr1);
    int comparacao2 = compararCartas(deck, cartaEscolhida, attr2);

    int soma = comparacao1 + comparacao2;

    switch (soma) {
        case 0:
            printf("Perdeste! A vitória é da CARTA %d!\n", cartaEscolhida == 1 ? 2 : 1);
            break;

        case 1:
            printf("Empate! Um ponto para cada carta!\n");
            break;

        case 2:
            printf("Venceste! A vitória é da CARTA %d!\n", cartaEscolhida);
            break;
        
        default:
            break;
    }

    printf("\n");
    printf("\n");
    printf("\n");
    
    system("pause");
    return 0;
}
