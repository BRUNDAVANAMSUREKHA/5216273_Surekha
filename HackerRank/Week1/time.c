#include <stdio.h>
void convertTime(char s[]) {
    int hour, minute, second;
    char ampm;
    hour   = (s[0] - '0') * 10 + (s[1] - '0');
    minute = (s[3] - '0') * 10 + (s[4] - '0');
    second = (s[6] - '0') * 10 + (s[7] - '0');
    ampm   = s[8];
    if (ampm == 'A' && hour == 12) {
        hour = 0;
    } else if (ampm == 'P' && hour != 12) {
        hour += 12;
    }
    printf("%02d:%02d:%02d\n", hour, minute, second);
}
int main() {
    char s[11];
    scanf("%s", s);
    convertTime(s);
    return 0;
}
