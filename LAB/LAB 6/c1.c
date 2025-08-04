
#include <stdio.h>
#include <string.h>

#define MAX 100


int isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}


void reverse(char *str, int j) {
    int i = 0;
    char temp;
    while (i < j) {
        temp = str[i];
        str[j] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}


void processString(int n, char *s) {
    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            reverse(s, i - 1);
        }
    }
    printf("%s\n", s);
}

int main() {
    int T, N;
    char S[MAX];

    scanf("%d", &T); 
    while (T--) {
        scanf("%d", &N);   
        scanf("%s", S);    
        processString(N, S);
    }

    return 0;
}
