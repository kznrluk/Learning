#include <stdio.h>
#include <math.h>

int binary(int data[], int size, int n);
void output(int n, int ans);

int main(void) {
    int data[] = {1,2,3,4,5,6,7,8}; 
    int size = sizeof(data) / sizeof(int);
    int n = 8;
    int i, ans;

    ans = binary(data, size, n);
    output(n, ans);

    return 0;
}

int binary(int data[], int size, int n){
    int ans = -1;
    int m = 0;
    int left = 0, right = size;

    while(1){
        m = (right + left) / 2;
        if(data[m] == n){
            ans = m;
            break;
        } else if (data[m] < n) {
            left = m;
        } else {
            right = m;
        }
        if(count > size){
            ans = -1;
            break;
        }
        count++;
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