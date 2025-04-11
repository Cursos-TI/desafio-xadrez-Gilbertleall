#include <stdio.h>

// Função recursiva para mover a Torre para a direita
void movertorre(int casas) {
    if (casas > 0) {
        printf("Direita\n\n");
        movertorre(casas - 1);
    }
}

// Função recursiva para mover a Rainha para a esquerda
void moverainha(int casas) {
    if (casas > 0) {
        printf("Esquerda\n\n");
        moverainha(casas - 1);
    }
}

// Função recursiva para mover o Bispo com loops aninhados
void moverbispo(int vertical, int horizontal) {
    if (vertical > 0) {
        for (int i = 0; i < horizontal; i++) {
            printf("Diagonal cima/direita\n");
        }
        printf("\n");
        moverbispo(vertical - 1, horizontal);
    }
}

// Função para movimentar o Cavalo com loops complexos
void movercavalo() {
    int movimentos = 3;
    int x = 7, y = 0; // Posição inicial do cavalo (parte inferior esquerda)

    for (int m = 0; m < movimentos; m++) {
        for (int i = 0, j = 2; i <= j; i++, j--) {
            if (i == j) {
                continue; // Ignora a iteração onde i == j
            }

            x -= 2;
            y += 1;

            // Verifica se ainda está dentro do tabuleiro
            if (x < 0 || y > 7) {
                printf("Movimento inválido! Cavalo saiu do tabuleiro.\n\n");
                break;
            }

            printf("Cima\n");
            printf("Cima\n");
            printf("Direita\n\n");

            if (x == 1 && y == 3) {
                printf("Cavalo atingiu a posição alvo. Encerrando movimentos.\n\n");
                break;
            }
        }
    }

    printf("O cavalo se moveu em L (2 para cima, 1 para a direita), 3 vezes.\n\n");
}

int main() {
    int peca;
    const int casasTorre = 5;
    const int casasRainha = 8;
    const int movVerticalBispo = 3;
    const int movHorizontalBispo = 1;

    printf("Escolha a peça que deseja mover:\n");
    printf("[1] Torre\n");
    printf("[2] Bispo\n");
    printf("[3] Rainha\n");
    printf("[4] Cavalo\n");
    scanf("%d", &peca);

    printf("\n");

    switch (peca) {
        case 1:
            printf("Torre:\n\n");
            movertorre(casasTorre);
            printf("A torre moveu-se %d vezes para a direita.\n", casasTorre);
            break;

        case 2:
            printf("Bispo:\n\n");
            moverbispo(movVerticalBispo, movHorizontalBispo);
            printf("O bispo moveu-se na diagonal %d vezes verticalmente e %d vezes horizontalmente por chamada.\n\n",
                   movVerticalBispo, movHorizontalBispo);
            break;

        case 3:
            printf("Rainha:\n\n");
            moverainha(casasRainha);
            printf("A rainha moveu-se %d vezes para a esquerda.\n", casasRainha);
            break;

        case 4:
            printf("Cavalo:\n\n");
            movercavalo();
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }

    return 0;
}
