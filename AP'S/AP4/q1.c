#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link {
    int data;
    struct link *next;

} Link;

Link *createInitialLink(Link *nextval) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->next = nextval;

    return n;
}

Link *createLink(Link *nextval, int it) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->data = it;
    n->next = nextval;

    return n;
}

typedef struct {
    Link *head;
    Link *tail;
    Link *curr;
    int size;

} Linklist;

Linklist *createList() {
    Linklist *l = (Linklist*)malloc(sizeof(Linklist));
    l->curr = l->tail = l->head = createInitialLink(NULL);

    l->size = 0;

    return l;
}

void insert(Linklist *l, int it) {
    l->curr->next = createLink(l->curr->next, it);

    if (l->tail == l->curr) {
        l->tail = l->curr->next;
    }

    l->size++;

}

void remove(Linklist *l){
    if (l->curr->next == NULL) {
        return;
    }

    Link *remove_link = l->curr->next;

    int it = remove_link->data; // we can return this

    if (l->tail == remove_link) {
        l->tail = l->curr;
    }

    l->curr->next = remove_link->next;
    free(remove_link);
    l->size--;
}

void moveToStart(Linklist *l) {
    l->curr = l->head;
}

void prev(Linklist *l) {
    if (l->curr == l->head) {
        return;
    }

    Link *temp = l->head;

    while (temp->next != l->curr) {
        temp = temp->next;
    }

    l->curr = temp;
}

void next(Linklist *l) {
    if (l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}

void clear(Linklist *l) {
    Link *temp = l->head;

    while (temp != NULL) {
        Link *next = temp->next;

        free(temp);
        temp = next;
    }

    l->curr = l->tail = l->head = createInitialLink(NULL);
    l->size = 0;
}

void count(Linklist *list, int numb) {
    Link *temp = list->head;
    int cnt = 0;

    while (temp->next != NULL) {
        if (temp->next->data == numb) {
            cnt++;
        }

        temp = temp->next;
    }

    printf("%d\n", cnt);
}

int main() {
    int cases, total, number;
    char word[6];

    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {
        printf("Caso %d:\n", i + 1);

        Linklist *l = createList();

        scanf("%d", &total);

        while (total--) {
            scanf(" %s", word);

            if (strcmp(word, "insert") == 0) {
                scanf("%d", &number);
                insert(l, number);
            }

            else if (strcmp(word, "remove") == 0) {
                remove(l);
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

        free(l);
    }

    return 0;
}
