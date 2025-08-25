#include <stdio.h>
#include <ctype.h>

char* pangrams(char* s) {
    int seen[26] = {0};
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            char c = tolower(s[i]);
            int idx = c - 'a';
            if (!seen[idx]) {
                seen[idx] = 1;
                count++;
            }
        }
    }

    if (count == 26)
        return "pangram";
    else
        return "not pangram";
}

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);

    printf("%s\n", pangrams(s));
    return 0;
}
