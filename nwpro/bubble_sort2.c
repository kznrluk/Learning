#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 列数
#define COLUMN 10
// データ量倍数の指定 COLUMN * NUMBER_OF_MULTIPLIERが最大データ数
#define NUMBER_OF_MULTIPLIER 1000
// 試行回数
#define NUMBER_OF_TRIALS 10

void exec_bubble_sort(int data[], int size);
void outputResultArrayAsCSV(int resultArray[COLUMN][NUMBER_OF_TRIALS + 1]);

int main(void){
    int resultArray[COLUMN][NUMBER_OF_TRIALS + 1];
    int amountDataIndex = 0;
    printf("CLOCKS_PER_SEC = %d\n", CLOCKS_PER_SEC);
    for(amountDataIndex = 0; amountDataIndex < COLUMN; amountDataIndex++){
        int i;

        // 時間関係の初期化
        unsigned long int startTime;
        unsigned long int elapsedTime;

        // [amountDataIndex]回目の計測開始
        int trialsCount;
        int result[NUMBER_OF_TRIALS + 1];

        // 挿入するデータ量の計算
        int dataSize = (amountDataIndex + 1) * NUMBER_OF_MULTIPLIER;
        printf("Checking sort time with %d...\n", dataSize);
        // [NUMBER_OF_TRIALS]回計算を実行する
        for(i = 0; i < NUMBER_OF_TRIALS; i++){
            int j;

            // 計算するデータの初期化
            int arrayData[dataSize];
            for(j = 0; j < dataSize; j++){
                arrayData[j] = rand() % 10000 + 1;
            }

            // 計算開始
            startTime = clock();
            exec_bubble_sort(arrayData, dataSize);
            elapsedTime = clock() - startTime;
            
            // 計算時間の出力
            resultArray[amountDataIndex][i] = elapsedTime;
            printf("%8d", elapsedTime);
        }
        printf("\n");
        // 平均計算時間を算出
        int sumAll = 0;
        int k;
        for(k = 0; k < NUMBER_OF_TRIALS; k++){
            sumAll += resultArray[amountDataIndex][k];
        }
        int average = (float)sumAll / (float)NUMBER_OF_TRIALS + 0.5;
        resultArray[amountDataIndex][NUMBER_OF_TRIALS] = average;
        printf("AverageTime : %d \n\n", average);
    }

    outputResultArrayAsCSV(resultArray);

    return 0;
}

void exec_bubble_sort(int data[], int size){
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

void outputResultArrayAsCSV(int resultArray[COLUMN][NUMBER_OF_TRIALS + 1]){
    int i, j;
    printf("<=============== CSV START ===============>\n");
    // タイトルを含むため-1から開始
    for(i = -1; i < NUMBER_OF_TRIALS + 1; i++){
        for(j = -1; j < COLUMN; j++){
            // タイトル出力
            if(i == -1){
                if(j != -1){
                    printf("%d", (j + 1) * NUMBER_OF_MULTIPLIER);
                } else {
                    printf("BUBBLE CSV");
                }
            } else if(j == -1){
                if(i != NUMBER_OF_TRIALS){
                    printf("%d", i + 1);
                } else {
                    printf("AVERAGE");
                }
            } else {
                 printf("%d", resultArray[j][i]);
            }
            if(j + 1 < NUMBER_OF_TRIALS){
                printf(",");
            }
        }
        printf("\n");
    }
    printf("<================ CSV END ================>\n");
}