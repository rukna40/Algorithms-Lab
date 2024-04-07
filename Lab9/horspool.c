#include <stdio.h>
#include <string.h>

int horspool(char text[], char pattern[]) {
    int bs[128];
    int n = strlen(text);
    int m = strlen(pattern);

    for(int i = 0; i < 128; i++){
        bs[i] = m;
    }
    for(int i = 0; i < m - 1; i++){
        bs[pattern[i]] = m - i - 1;       
    }

    for(int i = 0; i < n - m + 1;) {
        int j = m - 1;
        int k = j;
        while(k >= 0 && pattern[k] == text[i + k]) {
            k--;    
        }
        if (k == -1){
            return i;
        }
        else{
            i += bs[text[i + j]];
        }
    }
    return -1;
} 

int main(){
    char text[] = "ABCDEF";
    char pattern[] = "BCD";
    int result = horspool(text, pattern);
    printf("%d\n", result);
    return 0;
}
