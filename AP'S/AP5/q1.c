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
    Link *top;
    int size;

} Stack;

Stack *createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;

    return s;
}

void push(Stack *s, int it) {
    s->top = createLink(s->top, it);
    s->size++;
}

void pop(Stack *s, int numb) {
    if (s->top == NULL) {
        return;
    }

    int sum = 0;
    Link *temp = s->top;

    for (int i = 0; i < numb && temp != NULL; i++) {
        Link *n = temp->next;

        sum += temp->data;

        free(temp);
        temp = n;
    }

    s->top = temp;
    s->size -= numb;

    printf("%d\n", sum);
}

int main() {
    int cases, number;
    char word[6];

    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {
        printf("Caso %d:\n", i + 1);

        Stack *s = createStack();

        scanf(" %s", word);
        while (strcmp(word, "end") != 0) {
            scanf("%d", &number);

            if (strcmp(word, "push") == 0) {
                push(s, number);
            }

            else {
                pop(s, number);
            }

            scanf(" %s", word);
        }

        free(s);
    }

    return 0;
}