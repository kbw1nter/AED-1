#include <stdio.h>
#include <string.h>
#include <limits.h>

//dado pelo leetcode
char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int req[26] = {0};
    char* resultado = NULL;
    int larMin = INT_MAX;

    // contar as letras no licensePlate.
    for (int i = 0; licensePlate[i]; i++) {
        char c = licensePlate[i];

        if (c >= 'A' && c <= 'Z') {
            req[c - 'A']++;
        } else if (c >= 'a' && c <= 'z') {
            req[c - 'a']++;
        }
    }

    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        int contador[26] = {0};

        // contar as letras das palavras
        for (int j = 0; word[j]; j++) {
            contador[word[j] - 'a']++;
        }

        // verificar se a palavra tem todas as letras que precisa
        int validade = 1;
        for (int k = 0; k < 26; k++) {
            if (contador[k] < req[k]) {
                validade = 0;
                break;
            }
        }

        // se for valida atualiza o resultado
        if (validade && strlen(word) < larMin) {
            resultado = word;
            larMin = strlen(word);
        }
    }

    return resultado;
}

// teste das palavras
int main(){

    char* licensePlate1 = "1s3 PSt";
    char* vocab1[] = {"step", "steps", "stripe", "stepple"};
    int teste1 = sizeof(vocab1) / sizeof(vocab1[0]);
    printf("Resultado 1: %s\n", shortestCompletingWord(licensePlate1, vocab1, teste1));

    char* licensePlate2 = "1s3 456";
    char* vocab2[] = {"looks", "pest", "stew", "show"};
    int teste2 = sizeof(vocab2) / sizeof(vocab2[0]);
    printf("Resultado 2: %s\n", shortestCompletingWord(licensePlate2, vocab2, teste2));

    return 0;
}
