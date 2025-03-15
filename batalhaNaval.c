#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro zerado
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 significa água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1); // Exibe o número da linha (1 a 10)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == 5) {
                printf("5 "); // Representa a habilidade aplicada (cruz, triângulo, octaedro)
            }
        }
        printf("\n");
    }
}

// Função para criar a cruz
void criarCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // A cruz será formada pelas coordenadas: d1, d2, b3, c3, d3, e3, d4, d5, f3
    tabuleiro[0][3] = 5; // d1
    tabuleiro[1][3] = 5; // d2
    tabuleiro[2][1] = 5; // b3
    tabuleiro[2][2] = 5; // c3
    tabuleiro[2][3] = 5; // d3
    tabuleiro[2][4] = 5; // e3
    tabuleiro[3][3] = 5; // d4
    tabuleiro[4][3] = 5; // d5
    tabuleiro[2][5] = 5; // f3
}

// Função para criar o triângulo
void criarTriangulo(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // O triângulo vai ser formado pelas coordenadas: d6, c7, d7, e7, b8, c8, d8, e8, f8
    tabuleiro[5][3] = 5; // d6
    tabuleiro[6][2] = 5; // c7
    tabuleiro[6][3] = 5; // d7
    tabuleiro[6][4] = 5; // e7
    tabuleiro[7][1] = 5; // b8
    tabuleiro[7][2] = 5; // c8
    tabuleiro[7][3] = 5; // d8
    tabuleiro[7][4] = 5; // e8
    tabuleiro[7][5] = 5; // f8
}

// Função para criar o octaedro
void criarOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // O octaedro vai ser formado pelas coordenadas: h3, g4, h4, i4, g5, h5, i5, g6, h6, i6, h7
    tabuleiro[2][7] = 5;  // h3
    tabuleiro[3][6] = 5;  // g4
    tabuleiro[3][7] = 5;  // h4
    tabuleiro[3][8] = 5;  // i4
    tabuleiro[4][6] = 5;  // g5
    tabuleiro[4][7] = 5;  // h5
    tabuleiro[4][8] = 5;  // i5
    tabuleiro[5][6] = 5;  // g6
    tabuleiro[5][7] = 5;  // h6
    tabuleiro[5][8] = 5;  // i6
    tabuleiro[6][7] = 5;  // h7
}

// Função para aplicar todas as habilidades (cruz, triângulo e octaedro)
void aplicarTodasHabilidades(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Criando a cruz
    criarCruz(tabuleiro);

    // Criando o triângulo
    criarTriangulo(tabuleiro);

    // Criando o octaedro
    criarOctaedro(tabuleiro);

    // Linha 9 não deve conter nada, então garantimos que ela está zerada
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        tabuleiro[8][i] = 0; // Linha 9
    }
}

int main() {
    int opcao;
    
    // Laço para exibir as opções até o usuário escolher uma opção válida
    do {
        printf("~~~~ Batalha Naval ~~~~\n");
        printf("Selecione a opção desejada\n");
        printf("1. Iniciar tabuleiro já montado\n");
        printf("2. Sair do jogo\n");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
        
        // Verifica a opção escolhida
        if(opcao == 1) {
            printf("Iniciando tabuleiro...\n");

            // Declara um tabuleiro de 10x10 para o jogo
            int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

            // Inicializa o tabuleiro
            inicializarTabuleiro(tabuleiro);

            // Aplica todas as habilidades no tabuleiro (cruz, triângulo e octaedro)
            aplicarTodasHabilidades(tabuleiro);

            // Exibe o tabuleiro
            exibirTabuleiro(tabuleiro);
            break;  // Sai do loop quando a opção 1 é escolhida
        } 
        else if(opcao == 2) {
            printf("Saindo do jogo....\n");
            break;  // Sai do loop quando a opção 2 é escolhida
        } 
        else {
            printf("Opção inválida. Tente novamente!\n");
        }

    } while(opcao != 1 && opcao != 2);  // O loop continua até que a opção seja 1 ou 2

    return 0;
}
