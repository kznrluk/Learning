#include <stdio.h>

#define MAXSIZE 64
#define MAXWORDS 32
#define MAXCHARS 6

int main(void){
    char text[MAXSIZE] = "It is good to see you. Thank you for Coming.";
    char result[MAXWORDS][MAXCHARS];
    int i, charCount, wordCount;
    
    i = 0, wordCount = 0, charCount = 0;
    while(text[i] != '\0'){
        if(!i) printf("[\"");
        if(text[i] == ' ' || text[i] == '.'){
            printf("\"]");
            result[wordCount][charCount] = '\0';
            charCount = 0;
            wordCount++;
            if(text[i+1] != '\0') printf("[\"");
        } else {
            printf("\x1b[36m%c\x1b[39m", text[i]);
            result[wordCount][charCount] = text[i];
            charCount++;
        }
        i++;
    }
    printf("\n");
    return 0;
}