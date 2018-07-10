#include <stdio.h>

int linear(int data[], int size, int n);
void output(int n, int ans);

int main(void) {
    int data[] = {3, 9, 8, 2, 1, 4, 6, 5, 7}; 
    int size = sizeof(data) / sizeof(int);
    int n;
    int i, ans;

    printf("Search Number?:");
    scanf("%d", &n);
    
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
    return ans;
}

void output(int n, int ans){
    if(ans == -1){
        printf("output: %d is not found.\n", n);
    } else {
        printf("output: %d is found in data[%d]\n", n, ans);
    }
}

// [fid@Thinkpad nwpro]$ gcc linear_search2.c && ./a.out
// Search Number?:3
// output: 3 is found in data[0]
// [fid@Thinkpad nwpro]$ gcc linear_search2.c && ./a.out
// Search Number?:10
// output: 10 is not found.