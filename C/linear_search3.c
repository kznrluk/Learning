#include <stdio.h>

struct gakusei {
    int gakuban;
    int kamoku1;
    int kamoku2;
    float heikin;
};

float linear(struct gakusei ns_2nen[], int n);
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

    printf("[liner_search3.c] Input target number:");
    scanf("%d", &n);
    
    ans = linear(ns_2nen, n);
    output(n, ans);

    return 0;
}


float linear(struct gakusei ns_2nen[], int n){
    float ans;
    int i = 0;

    while(1){
        if(i >= 20) {
            ans = -1;
            break;
        } else if(ns_2nen[i].gakuban == n){
            ans = ns_2nen[i].heikin;
            break;
        }
        i++;
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

// [binary_search3.c] Input target number:1732770
// output: 1732770's heikin is 82.0
// s1732070@mv11c:~> gcc binary_search3.c && ./a.out
// [binary_search3.c] Input target number:1732000
// output: 1732000 is not found.