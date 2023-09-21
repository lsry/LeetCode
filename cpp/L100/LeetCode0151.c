#include <locale.h>
#include <stdlib.h>
#include <string.h>

void reverseWord(char *s, int low, int high) {
    while (low < high) {
        char c = s[low];
        s[low] = s[high];
        s[high] = c;
        ++low;
        --high;
    }
}

char * reverseWords(char * s){
    int sz = strlen(s);
    char *str = (char *)malloc(sizeof(char) * sz);
    memset(str, '\0', sizeof(char) * sz);
    int p = 0;
    int i = 0;
    while (s[p] != '\0') {
        if (s[p] != ' ') {
            str[i] = s[p];
            ++i;
        } else if (i > 0 && str[i - 1] != ' ') {
            str[i] = ' ';
            ++i;
        }
        p++;
    }
    if (i >= 1 && str[i - 1] == ' ') {
        --i;
    }
    sz = i;
    str[sz] = '\0';
    reverseWord(str, 0, sz - 1);
    for (int i = 0, j = 0;i < sz;) {
        while (j < sz && str[j] != ' ') {
            ++j;
        }
        reverseWord(str, i, j - 1);
        i = j + 1;
        j = i;
    }
    return str;
}

int main() {
    char *s = "the sky is blue";
    reverseWords(s);
}