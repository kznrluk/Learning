#include <stdio.h>

struct gakusei {
    int gakuban;
    int kamoku1;
    int kamoku2;
    float heikin;
};

float binary(struct gakusei ns_2nen[], int n);
void output(int n, float ans);

int main(void){
    struct gakusei ns_2nen[20];
    int i, n;
    float ans;

    // input from data.txt
    FILE *fp;
    fp = fopen("data.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "File Error\n");
        return -1;
    }

    for(i = 0; i < 20; i++){
        fscanf(fp, "%d", &ns_2nen[i].gakuban);
        fscanf(fp, "%d", &ns_2nen[i].kamoku1);
        fscanf(fp, "%d", &ns_2nen[i].kamoku2);
        ns_2nen[i].heikin = (float)(ns_2nen[i].kamoku1 + ns_2nen[i].kamoku2) / 2;
    }
    fclose(fp);

    printf("[binary_search3.c] Input target number:");
    scanf("%d", &n);
    
    ans = binary(ns_2nen, n);
    output(n, ans);

    return 0;
}


float binary(struct gakusei ns_2nen[], int n){
    float ans = -1;
    int m = 0;
    int left = 0, right = 20;

    while(left <= right){
        m = (right + left) / 2;
        if(ns_2nen[m].gakuban == n){
            ans = ns_2nen[m].heikin;
            break;
        } else if (ns_2nen[m].gakuban <= n) {
            left = m + 1;
        } else {
            right = m - 1;
        }
    }

    return ans;
}

void output(int n, float ans){
    if(ans == -1){
        printf("output: %d is not found.\n", n);
    } else {
        printf("output: %d's heikin is %3.1f\n", n, ans);
    }
}

// s1732070@mv11c:~> gcc binary_search3.c && ./a.out
// [binary_search3.c] Input target number:1732770
// output: 1732770's heikin is 82.0
// s1732070@mv11c:~> gcc binary_search3.c && ./a.out
// [binary_search3.c] Input target number:1732000
// output: 1732000 is not found.