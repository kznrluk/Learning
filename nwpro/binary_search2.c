#include <stdio.h>
#include <math.h>

int binary(int data[], int size, int n);
void output(int n, int ans);

int main(void) {
    int data[] = {3, 5, 6, 9, 11, 14, 16, 19, 21, 33}; 
    int size = sizeof(data) / sizeof(int);
    int n;
    int i, ans;

    printf("Search Number?:");
    scanf("%d", &n);

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
            if(m == left){
                ans = -1;
                break;
            }
            left = m;
        } else {
            if(m == right){
                ans = -1;
                break;
            }
            right = m;
        }
    }

    return ans;
}

void output(int n, int ans){
    if(ans == -1){
        printf("output: %d is not found.\n", n);
    } else {
        printf("output: %d is found in data[%d]\n", n, ans);
    }
}