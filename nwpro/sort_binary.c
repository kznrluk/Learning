#include <stdio.h>
#include <stdlib.h>

void insert_sort(int data[], int size);
int binary(int data[], int size, int n);
void resultOutput(int n, int ans);
void arrayOutput(int data[], int size);

int main(void){
    int data[20];
    int size = sizeof(data) / sizeof (int);
    int n, i, ans;

    for(i = 0; i < 20; i++){
        data[i] = rand() % 100 + 1;
    }
    
    printf("初期状態のデータの表示:\n");
    arrayOutput(data, size);
    // ソートの実行
    insert_sort(data, size);
    printf("ソート後のデータの表示");
    arrayOutput(data, size);
    
    printf("検索する数字を入力して下さい:");
    scanf("%d", &n);
    
    ans = binary(data, size, n);
    resultOutput(n, ans);

    return 0;
}

void arrayOutput(int data[], int size){
    int i;
    printf("arrayOutput : ");
    for(i = 0; i < size; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
}

        
int binary(int data[], int size, int n){
    int ans = -1;
    int m = 0;
    int left = 0;
    int right = size - 1;

    while(left <= right){
        m = (right + left) / 2;
        if(data[m] == n){
            ans = m;
            break;
        } else if (data[m] <= n) {
            left = m + 1;
        } else {
            right = m - 1;
        }
    }

    return ans;
}

void resultOutput(int n, int ans){
    if(ans == -1){
        printf("output: %d is not found. \n", n);
    } else {
        printf("output: %d is found in data[%d]\n", n, ans);
    }
}

void insert_sort(int data[], int size){
    int i, j, temp;
    
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

