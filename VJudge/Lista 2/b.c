#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    int data;
    struct link *next;

} Link;


Link *create_initial_link(Link *nextval) {
    Link *node = (Link*)malloc(sizeof(Link));

    node->next = nextval;

    return node;
}


Link *create_more_links(Link *nextval, int it) {
    Link *node = (Link*)malloc(sizeof(Link));

    node->data = it;
    node->next = nextval;

    return node;
}


typedef struct {
    Link *front;
    Link *rear;
    int size;

} Queue;


Queue *create_queue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->front = queue->rear = create_initial_link(NULL);
    queue->size = 0;

    return queue;
}

void enqueue(Queue *queue, int it);
void print_queue(Queue *queue);
void test(Queue *comes, Queue *leaves);
void clear(Queue *q);


int main() {
    Queue *comes = create_queue();
    Queue *leaves = create_queue();

    int cases;
    scanf("%d", &cases);
    
    int numb;
    int student;

    for (int i = 0; i < cases; i++) {
        scanf("%d", &numb);
        int count = 0;

        for (int j = 0; j < numb*2; j++) {
            scanf("%d", &student);

            if (count == 0) {
                enqueue(comes, student);
                count++;
            }
            
            else {
                enqueue(leaves, student);
                count = 0;
            }
        }

        test(comes, leaves);

        clear(comes);
        clear(leaves);
    }

    free(comes);
    free(leaves);

    return 0;
}


void enqueue(Queue *queue, int it) {
    queue->rear->next = create_more_links(NULL, it);
    queue->rear = queue->rear->next;
    queue->size++;
}


void print_queue(Queue *queue) {
    Link *temp = queue->front->next;

    while (temp != NULL) {
        if (temp->next != NULL) {
            printf("%d ", temp->data);
        }
        
        else {
            printf("%d\n", temp->data);
        }
        
        temp = temp->next;
    }
}

void test(Queue *comes, Queue *leaves) {
    Queue *new_queue = create_queue();
    int second = 1;

    Link *temp_c = comes->front->next;
    Link *temp_l = leaves->front->next;

    while (temp_c != NULL && temp_l != NULL) {
        if (second > temp_c->data) {
            if (second > temp_l->data) {
                enqueue(new_queue, 0);
                temp_c = temp_c->next;
                temp_l = temp_l->next;
            }
            
            else {
                enqueue(new_queue, second);
                temp_c = temp_c->next;
                temp_l = temp_l->next;
                second++;
            }
            
        }
        
        else if (second == temp_c->data){
            enqueue(new_queue, second);
            temp_c = temp_c->next;
            temp_l = temp_l->next;
            second++;
        }
        
        else {
            second++;
        }
        
    }

    print_queue(new_queue);
    clear(new_queue);
    free(new_queue);
}


void clear(Queue *q) {
    Link *temp = q->front->next;

    while (temp != NULL) {
        Link *next = temp->next;
        free(temp);
        temp = next;
    }
    
    q->front = q->rear = create_initial_link(NULL);
    q->size = 0;
}