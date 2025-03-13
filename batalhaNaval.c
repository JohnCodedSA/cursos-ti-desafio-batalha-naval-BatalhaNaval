#include <stdio.h>

int tamanhoTabuleiro = 10;
int tamanhoNavio = 3;

// Função para inicializar o tabuleiro zerado
void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0; // Setando o tabuleiro em 0 (água)
        }
    }
}

// Função para checar se o navio pode ser posicionado sem sobrepor
int checarSobreposicao(int tabuleiro[10][10], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha][coluna + i] != 0) {
                return 1; // Sobreposição
            }
        }
    } else if (orientacao == 1) { // Vertical
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha + i][coluna] != 0) {
                return 1; // Sobreposição
            }
        }
    } else if (orientacao == 2) { // Diagonal Crescente
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha + i][coluna + i] != 0) {
                return 1; // Sobreposição
            }
        }
    } else if (orientacao == 3) { // Diagonal Decrescente
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha + i][coluna - i] != 0) {
                return 1; // Sobreposição
            }
        }
    }
    return 0; // Nenhuma sobreposição
}

// Função para posicionar o navio na posição horizontal
void posicionarNavioHorizontal(int tabuleiro[10][10], int linha, int coluna) {
    if (!checarSobreposicao(tabuleiro, linha, coluna, 0)) { // Código a ser executado se não houver sobreposição
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linha][coluna + i] = 3; // 3 representa o navio
        }
    }
}

// Função para posicionar o navio na posição vertical
void posicionarNavioVertical(int tabuleiro[10][10], int linha, int coluna) {
    if (!checarSobreposicao(tabuleiro, linha, coluna, 1)) { // Código a ser executado se não houver sobreposição
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linha + i][coluna] = 3; // 3 representa o navio
        }
    }
}

// Função para posicionar o navio na diagonal crescente (linha e coluna aumentam)
void posicionarNavioDiagonalCrescente(int tabuleiro[10][10], int linha, int coluna) {
    if (!checarSobreposicao(tabuleiro, linha, coluna, 2)) { // Código a ser executado se não houver sobreposição
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linha + i][coluna + i] = 3; // 3 representa o navio
        }
    }
}

// Função para posicionar o navio na diagonal decrescente (linha aumenta, coluna diminui)
void posicionarNavioDiagonalDecrescente(int tabuleiro[10][10], int linha, int coluna) {
    if (!checarSobreposicao(tabuleiro, linha, coluna, 3)) { // Código a ser executado se não houver sobreposição
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linha + i][coluna - i] = 3; // 3 representa o navio
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]) {
    // Exibe as letras das colunas
    printf("   A B C D E F G H I J\n");

    for (int i = 0; i < tamanhoTabuleiro; i++) {
        printf("%2d ", i + 1); // Exibe o número da linha de 1 a 10. %2d para garantir que cada número ocupe 2 espaços
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declara um tabuleiro de 10x10 para o jogo
    int tabuleiro[10][10];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Define as coordenadas para os navios
    int linhaNavioHorizontal = 2; // Linha 3 
    int colunaNavioHorizontal = 1; // Coluna B 

    int linhaNavioVertical = 5; // Linha 6 
    int colunaNavioVertical = 3; // Coluna D 

    // Posiciona os navios
    posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
    posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);

    // Posiciona os navios diagonais
    posicionarNavioDiagonalCrescente(tabuleiro, 3, 3); // linha 4 até coluna F6
    posicionarNavioDiagonalDecrescente(tabuleiro, 6, 6); // linha 7 até coluna E9

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
