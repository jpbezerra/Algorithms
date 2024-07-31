#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int cases;
    int solved;

} Queue;

Queue *create_queue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->front = queue->rear = create_initial_link(NULL);
    queue->size = 0;
    queue->cases = 0;
    queue->solved = 0;

    return queue;
}

void enqueue(Queue *queue, int it) { // add
    queue->rear->next = create_more_links(NULL, it);
    queue->rear = queue->rear->next;
    queue->size++;
}

void dequeue(Queue *queue) { // solve
    if (queue->size == 0) {
        return;
    }

    Link *temp = queue->front->next;

    queue->front->next = queue->front->next->next;

    if (queue->front->next == NULL) {
        queue->front = queue->rear;
    }
    
    queue->size--;

    free(temp);
}

void print_queue(Queue *queue) { // print
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

void status(int solve, int cases) { // status
    printf("%d %d\n", solve, cases);
}

int main() {
    int number;
    char command[6];

    Queue *queue = create_queue();

    scanf(" %s", command);
    while (strcmp(command, "end") != 0) {

        if (strcmp(command, "add") == 0) {
            scanf("%d", &number);
            enqueue(queue, number);
            queue->cases++;
        }
        
        else if (strcmp(command, "solve") == 0) {
            if (queue->size != 0) {
                dequeue(queue);
                queue->cases--;
                queue->solved++;
            }
        }
        
        else if (strcmp(command, "print") == 0) {
            if (queue->cases == 0) {
                printf("x\n");
            }
            
            else {
                print_queue(queue);   
            }
        }
        
        else if (strcmp(command, "stats") == 0) {
            status(queue->solved, queue->cases);
        }

        scanf("%s", command);
    }
}
