#include <stdio.h>

int linear(int data[], int size, int n);
void output(int n, int ans);

int main(void) {
    int data[] = {3, 9, 8, 2, 1, 4, 6, 5, 7}; 
    int size = sizeof(data) / sizeof(int);
    int n = 7;
    int i, ans;

    printf("%d", size);
    ans = linear(data, size, n);
    output(n, ans);

    return 0;
}

int linear(int data[], int size, int n){
    int ans;
    int i = 0;

    while(1){
        if(data[i] == n){
            ans = i;
            break;
        } else if(i > size) {
            ans = -1;
            break;
        }
        i++;
    }
    printf("ANSWER %d", ans);
    return ans;
}

void output(int n, int ans){
    if(ans > 0){
        printf("output: %dの値はdata[%d]に格納されています。\n", n, ans);
    } else {
        printf("output: %dの値は見つかりませんでした。\n", n);
    }
}