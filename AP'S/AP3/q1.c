#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int maxSize;
    int currSize;
    int curr;
    int *listArray;

} List;

List *createList(int size) {
    List *l = (List*)malloc(sizeof(List));
    l->maxSize = size;
    l->currSize = l->curr = 0;
    l->listArray = (int*)malloc(size * sizeof(int));
    return l;
}

void insert(List *l, int numb) {
    if (l->currSize < l->maxSize) {
        int i = l->currSize;

        while (i > l->curr) {
            l->listArray[i] = l->listArray[i - 1];
            i--;
        }

        l->listArray[l->curr] = numb;
        l->currSize++;
    }
}

void removee(List *l) {
    if (l->curr < 0 || l->curr >= l->maxSize) {
        return;
    }

    int i = l->curr;

    while (i < l->currSize - 1) {
        l->listArray[i] = l->listArray[i + 1];
        i++;
    }

    l->currSize--;
}

void next(List *l) {
    if (l->curr < l->maxSize) {
        l->curr++;
    }
}

void prev(List *l) {
    if (l->curr != 0) {
        l->curr--;
    }
}

void count(List *l, int numb) {
    int cnt = 0;

    for (int i = 0; i < l->currSize; i++) {
        if (l->listArray[i] == numb) {
            cnt++;
        }
    }

    printf("%d\n", cnt);
}

int main() {
    int cases, total, number;
    char word[6];

    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {
        printf("Caso %d:\n", i + 1);

        scanf("%d", &total);
        List *l = createList(total);
        int oper = total;

        while (oper--) {
            scanf(" %s", word);

            if (strcmp(word, "insert") == 0) {
                scanf("%d", &number);
                insert(l, number);
            }

            else if (strcmp(word, "remove") == 0) {
                removee(l);
            }

            else if (strcmp(word, "count") == 0) {
                scanf("%d", &number);
                count(l, number);
            }

            else if (strcmp(word, "next") == 0) {
                next(l);
            }

            else {
                prev(l);
            }
        }

        free(l->listArray);
        free(l);
    }

    return 0;
}