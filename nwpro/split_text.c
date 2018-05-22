#include <stdio.h>

#define MAXSIZE 64
#define MAXWORDS 32
#define MAXCHARS 6

char *charSpritter(char *text){
    int i, charCount, wordCount;
    char result[MAXWORDS][MAXCHARS];
    printf("%c\n", text[42]);
    
    i = 0, wordCount = 0, charCount = 0;
    while(text[i] != '\0'){
        if(text[i] != ' ' || text[i] != '.'){
            result[wordCount][charCount] = text[i];
            charCount++;
        } else {
            // TODO: NULL代入
            charCount = 0;
            wordCount++;
        }
        i++;
    }
    printf("%c\n", result[0][2]);

    return text;
}

int main(void){
    char text[MAXSIZE] = "It is good to see you. Thank you for Coming.";
    charSpritter(text);
    return 0;
}