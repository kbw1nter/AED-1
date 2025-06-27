int maximumGain(char* s, int x, int y) {
    int len = strlen(s);
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;
    int points = 0;
    
    if (x >= y) { // se x >= y, remove "ab" primeiro, se x <= y remove "ba" primeiro
        for (int i = 0; i < len; i++) { // percorre a string e remove "ab"
            if (top >= 0 && stack[top] == 'a' && s[i] == 'b') {
                top--;
                points = points + x;
            } else {
                stack[++top] = s[i];
            }
        }
        int newTop = -1;  // percorre o que sobrou na pilha depois de percorrer a string e remove "ba"
        for (int i = 0; i <= top; i++) {
            if (newTop >= 0 && stack[newTop] == 'b' && stack[i] == 'a') {
                newTop--;
                points = points + y;
            } else {
                stack[++newTop] = stack[i];
            }
        }
    } else {
        // percorre a string novamente mas para remover "ba"
        for (int i = 0; i < len; i++) {
            if (top >= 0 && stack[top] == 'b' && s[i] == 'a') {
                top--;
                points = points + y;
            } else {
                stack[++top] = s[i];
            }
        }
        // tbm percorrendo oque sobrou da pilha depois de percorrer a string mas para remover "ab"
        int newTop = -1;
        for (int i = 0; i <= top; i++) {
            if (newTop >= 0 && stack[newTop] == 'a' && stack[i] == 'b') {
                newTop--;
                points = points + x;
            } else {
                stack[++newTop] = stack[i];
            }
        }
    }
    
    free(stack);
    return points;
}