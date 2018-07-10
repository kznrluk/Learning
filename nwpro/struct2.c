#include <stdio.h>

struct gakusei {
    int gakuban;
    int kamoku1;
    int kamoku2;
    float heikin;
};

int main(void) {
    int i;
    struct gakusei ns_2nen[4];

    for(i = 0; i < 4; i++){
        printf("[%d] Input your gakuban:", i);
        scanf("%d", &ns_2nen[i].gakuban);
        printf("[%d] Input your score of kamoku1:", i);
        scanf("%d", &ns_2nen[i].kamoku1);
        printf("[%d] Input your score of kamoku2:", i);
        scanf("%d", &ns_2nen[i].kamoku2);
        ns_2nen[i].heikin = (float)(ns_2nen[i].kamoku1 + ns_2nen[i].kamoku2) / 2;
    };

    for(i = 0; i < 4; i++){
        printf("[%d] gakuban : %d , heikin : %3.1f\n", i, ns_2nen[i].gakuban, ns_2nen[i].heikin);
    }

    return 0;
}

// s1732070@mv11c:~> gcc struct2.c && ./a.out
// [0] Input your gakuban:000
// [0] Input your score of kamoku1:97
// [0] Input your score of kamoku2:64
// [1] Input your gakuban:001
// [1] Input your score of kamoku1:23
// [1] Input your score of kamoku2:45
// [2] Input your gakuban:002
// [2] Input your score of kamoku1:87
// [2] Input your score of kamoku2:35
// [3] Input your gakuban:003
// [3] Input your score of kamoku1:23
// [3] Input your score of kamoku2:66
// [0] gakuban : 0 , heikin : 80.5
// [1] gakuban : 1 , heikin : 34.0
// [2] gakuban : 2 , heikin : 61.0
// [3] gakuban : 3 , heikin : 44.5