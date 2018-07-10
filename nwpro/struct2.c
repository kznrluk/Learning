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
        ns_2nen[i].heikin = (ns_2nen[i].kamoku1 + ns_2nen[i].kamoku2) / 2;
    };

    for(i = 0; i < 4; i++){
        printf("[%d] gakuban : %d , heikin : %g\n", i, ns_2nen[i].gakuban, ns_2nen[i].heikin);
    }

    return 0;
}