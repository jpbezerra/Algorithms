#include <stdio.h>
#include <stdlib.h>

typedef struct link{
    int data;
    struct link *next;

} Link;

Link *create_initial_link(Link *nextval) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->next = nextval;

    return n;
}

Link *create_link(Link *nextval, int it) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->data = it;
    n->next = nextval;

    return n;
}

typedef struct {
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;

} Linklist;

Linklist *create_list() {
    Linklist *l = (Linklist*)malloc(sizeof(Linklist));
    l->curr = l->tail = l->head = create_initial_link(NULL);

    l->cnt = 0;

    return l;
}

void insert(Linklist *l, int it) {
    l->curr->next = create_link(l->curr->next, it);

    if (l->tail == l->curr) {
        l->tail = l->curr->next;
    }
    
    l->cnt++;
}

void moveToStart(Linklist *l) {
    l->curr = l->head;
}

void moveToEnd(Linklist *l) {
    l->curr = l->tail;
}

void next(Linklist *l) {
    if (l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}

void clear(Linklist *l) {
    Link *temp = l->head->next;

    while (temp != NULL) {
        Link *next = temp->next;

        free(temp);
        temp = next;
    }

    l->curr = l->tail = l->head;
    l->cnt = 0;
}


void print_list(Linklist *list) {
    moveToStart(list);

    Link *temp = list->curr->next;

    while (temp != NULL) {
        printf("%c", temp->data);

        temp = temp->next;
    }   
}


int main() {
    char carac;
    int aux = 0; // checar se ainda tem frases
    int aux_2 = 0; // checar se ainda tem letras na frase
    int aux_3 = 0; // variável para não dar dois scanf seguidos (quando muda de uma frase pra outra)

    while (aux == 0) {
        Linklist *list = create_list();
        clear(list);
        
        while (aux_2 == 0) {
            if (aux_3 == 0) {
                scanf("%c", &carac);
            }

            aux_3 = 0;

            if (carac == '\n' || carac == -1) {
                aux_2 = 1;
            }

            else {
                if (carac == '[') {
                    moveToStart(list);
                }

                else if (carac == ']') {
                    moveToEnd(list);
                }
                
                else {
                    insert(list, carac);
                    next(list);
                }
                
            }
            carac = -1;
        }

        print_list(list);
        printf("\n");
        clear(list);
        free(list);
        list = NULL;

        scanf("%c", &carac);

        if (carac == '\n' || carac == -1) {
            aux = 1;
        }
        
        else {
            aux_3 = 1;
            aux_2 = 0;
        }
    }
    
    return 0;
}