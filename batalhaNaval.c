#include <stdio.h>

int tamanhoTabuleiro = 10;
int tamanhoNavio = 3;

// Função para inicializar o tabuleiro zerado
void inicializarTabuleiro(int tabuleiro [10][10]){
    for(int i = 0; i < tamanhoTabuleiro; i++){
        for(int j = 0; j < tamanhoTabuleiro; j++){
            tabuleiro[i][j] = 0; //setando o tabuleiro em 0 (água)
        }
    }
}
// Função para posicionar o navio na posição horizontal
void posicionarNavioHorizontal(int tabuleiro [10][10], int linha, int coluna){
    for(int i = 0; i < tamanhoNavio; i++){
        tabuleiro[linha][coluna + i] = 3; // 3 representa o navio
    }
}

// Função para posicionar o navio na posição vertical
void posicionarNavioVertical(int tabuleiro [10][10], int linha, int coluna){
    for(int i = 0; i < tamanhoNavio; i++){
        tabuleiro[linha + i][coluna] = 3; // 3 representa o navio
    }
}

//Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]){
    // Exibe as letras das colunas
    printf("  A B C D E F G H I J\n");

    for(int i = 0; i < tamanhoTabuleiro; i++){
        printf("%2d ", i + 1); // Exibe o numero da linha de 1 a 10. %2d para garantir que cada número ocupe 2 espaços
        for(int j = 0; j < tamanhoTabuleiro; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int tabuleiro[10][10];

    // Inicializa tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Define as coordenadas para os navios
    int linhaNavioHorizontal = 2; // Linha 3 
    int colunaNavioHorizontal = 1; // Coluna B 

    int linhaNavioVertical = 5; // Linha 6 
    int colunaNavioVertical = 3; // Coluna D 

    // Posiciona navios
    posicionarNavioHorizontal(tabuleiro,linhaNavioHorizontal,colunaNavioHorizontal);
    posicionarNavioVertical(tabuleiro,linhaNavioVertical,colunaNavioVertical);

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);



return 0;
}