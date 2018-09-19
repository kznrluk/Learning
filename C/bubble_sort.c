#include <stdio.h>
#include <stdlib.h>

void insert_sort(int data[], int size);
void arrayOutput(int data[], int size);

int main(void){
    int data[20];
    int size = sizeof(data) / sizeof(int);
    int i;

    // 乱数の生成
    for(i = 0; i< 20; i++){
        data[i] = rand() % 100 + 1;
    }

    arrayOutput(data, size);
    insert_sort(data, size);
    arrayOutput(data, size);

    return 0;
}

void insert_sort(int data[], int size){
    int i, j, min, temp;
    
    for(i = 0; i < size - 1; i++){
        for(j = size - 1; j > i; j--){
            if(data[j] < data[j-1]){
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            }
        }
}
}

void arrayOutput(int data[], int size){
    int i;
    printf("arrayOutput : ");
    for(i = 0; i < size; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
}