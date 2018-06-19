#include <stdio.h>

#define MAXSIZE 64

int main(void){
    char text[MAXSIZE] = "It is good to see you. Thank you for Coming.";
    char nextChar;
    int i;
    
    i = 0;
    while(text[i] != '\0'){
        if(!i) printf("[\"");
        if(text[i] == ' ' || text[i] == '.'){
            if(text[i-1] != '.') printf("\"]");
            if(text[i+1] != '\0' && text[i+1] != ' ') printf("[\"");
        } else {
            printf("\x1b[36m%c\x1b[39m", text[i]);
        }
        i++;
    }
    printf("\n");
    return 0;
}
