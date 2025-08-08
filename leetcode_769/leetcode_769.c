#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxChunksToSorted_comMain(int* arr, int arrSize) {
    int pedacos = 0;
    int maximoAteAgora = 0;
    
    for (int i = 0; i < arrSize; i++) {
        // Atualiza o valor máximo visto até agora
        if (arr[i] > maximoAteAgora) {
            maximoAteAgora = arr[i];
        }
        
        // Se o valor máximo igual ao índice atual, podemos criar um pedaço
        if (maximoAteAgora == i) {
            pedacos++;
        }
    }
    
    return pedacos;
}

// Função auxiliar para imprimir array
void imprimirArray(int* arr, int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", arr[i]);
        if (i < tamanho - 1) printf(", ");
    }
    printf("]");
}

// Função para testar um caso
void testarCaso(int* arr, int tamanho, int esperado, const char* descricao) {
    printf("\n=== %s ===\n", descricao);
    printf("Entrada: ");
    imprimirArray(arr, tamanho);
    
    int resultado = maxChunksToSorted_comMain(arr, tamanho);
    
    printf("\nEsperado: %d\n", esperado);
    printf("Obtido: %d\n", resultado);
    
    if (resultado == esperado) {
        printf("APROVADO\n");
    } else {
        printf("FALHOU\n");
    }
}

// Função para demonstrar o processo passo a passo
void demonstrarProcesso(int* arr, int tamanho, const char* descricao) {
    printf("\n=== %s - Passo a passo ===\n", descricao);
    printf("Array: ");
    imprimirArray(arr, tamanho);
    printf("\n");
    
    int maximoAteAgora = 0;
    int pedacos = 0;
    
    printf("\nAnálise passo a passo:\n");
    printf("Índice | Valor | Máx até aqui | Pode dividir? | Total pedaços\n");
    printf("-------|-------|--------------|---------------|---------------\n");
    
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] > maximoAteAgora) {
            maximoAteAgora = arr[i];
        }
        
        bool podeDividir = (maximoAteAgora == i);
        if (podeDividir) {
            pedacos++;
        }
        
        printf("  %d    |   %d   |      %d       |      %s      |       %d\n", 
               i, arr[i], maximoAteAgora, podeDividir ? "SIM" : "NÃO", pedacos);
    }
    
    printf("\nResposta final: %d pedaços\n", pedacos);
}

int main() {
    // Caso de teste 1: Exemplo 1 do problema
    int teste1[] = {4, 3, 2, 1, 0};
    int tamanho1 = sizeof(teste1) / sizeof(teste1[0]);
    testarCaso(teste1, tamanho1, 1, "Teste 1: Todos elementos em ordem reversa");
    
    // Caso de teste 2: Exemplo 2 do problema
    int teste2[] = {1, 0, 2, 3, 4};
    int tamanho2 = sizeof(teste2) / sizeof(teste2[0]);
    testarCaso(teste2, tamanho2, 4, "Teste 2: Ordem mista com múltiplos pedaços possíveis");
    
    // Caso de teste 3: Já ordenado
    int teste3[] = {0, 1, 2, 3, 4};
    int tamanho3 = sizeof(teste3) / sizeof(teste3[0]);
    testarCaso(teste3, tamanho3, 5, "Teste 3: Array já ordenado");
    
    // Caso de teste 4: Elemento único
    int teste4[] = {0};
    int tamanho4 = sizeof(teste4) / sizeof(teste4[0]);
    testarCaso(teste4, tamanho4, 1, "Teste 4: Elemento único");
    
    // Caso de teste 5: Dois elementos trocados
    int teste5[] = {1, 0};
    int tamanho5 = sizeof(teste5) / sizeof(teste5[0]);
    testarCaso(teste5, tamanho5, 1, "Teste 5: Dois elementos trocados");
    
    // Caso de teste 6: Outro caso complexo
    int teste6[] = {2, 0, 1, 3};
    int tamanho6 = sizeof(teste6) / sizeof(teste6[0]);
    testarCaso(teste6, tamanho6, 2, "Teste 6: Caso complexo");
    
    printf("\n ANÁLISE DETALHADA\n");
    printf("====================\n");
    
    // Demonstrar o algoritmo passo a passo para exemplos principais
    demonstrarProcesso(teste1, tamanho1, "Exemplo 1");
    demonstrarProcesso(teste2, tamanho2, "Exemplo 2");
    
    return 0;
}