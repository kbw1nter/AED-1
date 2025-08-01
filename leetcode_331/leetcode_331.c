#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidSerialization(char* preorder) {
    int len = strlen(preorder);
    if (len == 0) return false;
    
    int slots = 1;
    int i = 0;
    
    while (i < len) {
        // Se não temos slots disponíveis, é inválido
        if (slots == 0) {
            return false;
        }
        
        // processa um
        if (preorder[i] == '#') {
            // Nó nulo: consome 1 slot, não adiciona novos slots
            slots--;
            i++; // pula o '#'
        } else {
            // Nó não-nulo: consome 1 slot, adiciona 2 novos slots
            slots--;
            slots += 2;
            
            // pula todos os dígitos do número
            while (i < len && preorder[i] != ',') {
                i++;
            }
        }
        
        // Pula a vírgula se existir
        if (i < len && preorder[i] == ',') {
            i++;
        }
    }
    
    // deve terminar com exatamente 0 slots
    return slots == 0;
}

//teste
int main() {
    // Exemplo 1: "9,3,4,#,#,1,#,#,2,#,6,#,#" -> true
    char* test1 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    printf("Exemplo 1: \"%s\" -> %s\n", test1, isValidSerialization(test1) ? "true" : "false");
    
    // Exemplo 2: "1,#" -> false
    char* test2 = "1,#";
    printf("Exemplo 2: \"%s\" -> %s\n", test2, isValidSerialization(test2) ? "true" : "false");
    
    // Exemplo 3: "9,#,#,1" -> false
    char* test3 = "9,#,#,1";
    printf("Exemplo 3: \"%s\" -> %s\n", test3, isValidSerialization(test3) ? "true" : "false");
    
    // testes adicionais
    char* test4 = "#";
    printf("Teste 4: \"%s\" -> %s\n", test4, isValidSerialization(test4) ? "true" : "false");
    
    char* test5 = "1,2,#,#,3,#,#";
    printf("Teste 5: \"%s\" -> %s\n", test5, isValidSerialization(test5) ? "true" : "false");
    
    return 0;
}