#include <stdio.h>
#include <stdlib.h>

// Tamanho do tabuleiro
#define TAM 10

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM], const char* titulo) {
    printf("\n%s:\n", titulo);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int x, int y, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') { // Horizontal
            if (y + i < TAM) tabuleiro[x][y + i] = 3;
        } else if (direcao == 'V') { // Vertical
            if (x + i < TAM) tabuleiro[x + i][y] = 3;
        } else if (direcao == 'D') { // Diagonal
            if (x + i < TAM && y + i < TAM) tabuleiro[x + i][y + i] = 3;
        }
    }
}

// Função para aplicar habilidade em cone (3x5)
void aplicarHabilidadeCone(int habilidade[3][5]) {
    // Inicializa a matriz da habilidade
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            habilidade[i][j] = 0;
        }
    }
    // Preenche o padrão em cone
    habilidade[0][2] = 1; // Linha 1: apenas o centro
    habilidade[1][1] = 1; habilidade[1][2] = 1; habilidade[1][3] = 1; // Linha 2: três posições
    for (int j = 0; j < 5; j++) habilidade[2][j] = 1; // Linha 3: todas as posições
}

// Função para aplicar habilidade em cruz (3x5)
void aplicarHabilidadeCruz(int habilidade[3][5]) {
    // Inicializa a matriz da habilidade
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            habilidade[i][j] = 0;
        }
    }
    // Preenche o padrão em cruz
    for (int j = 0; j < 5; j++) habilidade[1][j] = 1; // Linha central horizontal
    habilidade[0][2] = 1; // Centro da linha superior
    habilidade[2][2] = 1; // Centro da linha inferior
}

// Função para aplicar habilidade em octaedro (3x5)
void aplicarHabilidadeOctaedro(int habilidade[3][5]) {
    // Inicializa a matriz da habilidade
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            habilidade[i][j] = 0;
        }
    }
    // Preenche o padrão em octaedro
    habilidade[0][2] = 1; // Centro da linha superior
    habilidade[1][1] = 1; habilidade[1][2] = 1; habilidade[1][3] = 1; // Linha central
    habilidade[2][2] = 1; // Centro da linha inferior
}

// Função para exibir matriz de habilidade
void exibirHabilidade(int habilidade[3][5], const char* nomeHabilidade) {
    printf("\nHabilidade %s:\n", nomeHabilidade);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Tabuleiro principal
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionamento de quatro navios
    posicionarNavio(tabuleiro, 2, 3, 3, 'H'); // Navio horizontal
    posicionarNavio(tabuleiro, 5, 1, 4, 'V'); // Navio vertical
    posicionarNavio(tabuleiro, 0, 0, 3, 'D'); // Navio diagonal
    posicionarNavio(tabuleiro, 7, 7, 2, 'D'); // Outro navio diagonal

    // Exibir tabuleiro com navios
    exibirTabuleiro(tabuleiro, "Tabuleiro com Navios");

    // Matrizes para habilidades
    int habilidadeCone[3][5];
    int habilidadeCruz[3][5];
    int habilidadeOctaedro[3][5];

    // Aplicar e exibir habilidades
    aplicarHabilidadeCone(habilidadeCone);
    exibirHabilidade(habilidadeCone, "Cone");

    aplicarHabilidadeCruz(habilidadeCruz);
    exibirHabilidade(habilidadeCruz, "Cruz");

    aplicarHabilidadeOctaedro(habilidadeOctaedro);
    exibirHabilidade(habilidadeOctaedro, "Octaedro");

    return 0;
}